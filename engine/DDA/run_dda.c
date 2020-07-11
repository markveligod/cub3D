#include "../../cub.h"

void			is_side(t_ptr *ptr)
{
	ptr->dda->hit = 1;
	if (!ptr->dda->side)
	{
		if (ptr->dda->raydir_x < 0)
			ptr->dda->side = 1;
		else if (ptr->dda->raydir_x > 0)
			ptr->dda->side = 2;
	}
	else if (ptr->dda->side == 1)
	{
		if (ptr->dda->raydir_y < 0)
			ptr->dda->side = 3;
		else if (ptr->dda->raydir_y > 0)
			ptr->dda->side = 4;
	}
}

void			check_dist(t_ptr *ptr)
{
	ptr->dda->hit = 0;
	ptr->dda->side = 0;
	while (ptr->dda->hit == 0)
	{
		if (ptr->dda->sidedist_x < ptr->dda->sidedist_y)
		{
			ptr->dda->sidedist_x += ptr->dda->deltadist_x;
			ptr->dda->map_x += ptr->dda->stepx;
			ptr->dda->side = 0;
		}
		else
		{
			ptr->dda->sidedist_y += ptr->dda->deltadist_y;
			ptr->dda->map_y += ptr->dda->stepy;
			ptr->dda->side = 1;
		}
		if (ptr->p->split_map[ptr->dda->map_x][ptr->dda->map_y] == '1')
			is_side(ptr);
	}
	if (ptr->dda->side == 1 || ptr->dda->side == 2)
		ptr->dda->walldist = (ptr->dda->map_x - ptr->pl->p_x +
			(1 - ptr->dda->stepx) / 2) / ptr->dda->raydir_x;
	else if (ptr->dda->side == 3 || ptr->dda->side == 4)
		ptr->dda->walldist = (ptr->dda->map_y - ptr->pl->p_y +
			(1 - ptr->dda->stepy) / 2) / ptr->dda->raydir_y;
}

void			check_side(t_ptr *ptr)
{
	if (ptr->dda->raydir_x < 0)
	{
		ptr->dda->stepx = -1;
		ptr->dda->sidedist_x = (ptr->pl->p_x - ptr->dda->map_x) *
		ptr->dda->deltadist_x;
	}
	else
	{
		ptr->dda->stepx = 1;
		ptr->dda->sidedist_x = (ptr->dda->map_x + 1.0 - ptr->pl->p_x) *
		ptr->dda->deltadist_x;
	}
	if (ptr->dda->raydir_y < 0)
	{
		ptr->dda->stepy = -1;
		ptr->dda->sidedist_y = (ptr->pl->p_y - ptr->dda->map_y) *
		ptr->dda->deltadist_y;
	}
	else
	{
		ptr->dda->stepy = 1;
		ptr->dda->sidedist_y = (ptr->dda->map_y + 1.0 - ptr->pl->p_y) *
		ptr->dda->deltadist_y;
	}
}

void			calc_dda(t_ptr *ptr)
{
	ptr->dda->cam_x = 2 * (double)ptr->dda->screenx / (double)ptr->p->x - 1;
	ptr->dda->raydir_x = ptr->pl->d_x + ptr->pl->pl_x * ptr->dda->cam_x;
	ptr->dda->raydir_y = ptr->pl->d_y + ptr->pl->pl_y * ptr->dda->cam_x;
	ptr->dda->map_x = (int)ptr->pl->p_x;
	ptr->dda->map_y = (int)ptr->pl->p_y;
	ptr->dda->deltadist_x = fabs(1 / ptr->dda->raydir_x);
	ptr->dda->deltadist_y = fabs(1 / ptr->dda->raydir_y);
	check_side(ptr);
	check_dist(ptr);
}

void			run_dda(t_ptr *ptr)
{
	ptr->dda->screenx = 0;
	while (ptr->dda->screenx < ptr->p->x)
	{
		calc_dda(ptr);
		run_draw(ptr);
		ptr->b->buffer[ptr->dda->screenx] = ptr->dda->walldist;
		ptr->dda->screenx++;
	}
	draw_sprite(ptr);
}
