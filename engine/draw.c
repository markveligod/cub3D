#include "../cub.h"

void	set_player(t_link *lnk, char c)
{
	lnk->dis->dirx = 0;
	lnk->dis->diry = 0;
	lnk->dis->planx = 0;
	lnk->dis->plany = 0;
	if (c == 'N')
	{
		lnk->dis->plany = 0.60;
		lnk->dis->dirx = -1;
	}
	else if (c == 'S')
	{
		lnk->dis->plany = -0.60;
		lnk->dis->dirx = 1;
	}
	else if (c == 'W')
	{
		lnk->dis->planx = -0.60;
		lnk->dis->diry = -1;
	}
	else if (c == 'E')
	{
		lnk->dis->planx = 0.60;
		lnk->dis->diry = 1;
	}
}

void	set_walldist(t_link *lnk)
{
	lnk->dis->hit = 0;
	lnk->dis->side = 0;
	while (lnk->dis->hit == 0)
	{
		if (lnk->dis->sidedistx < lnk->dis->sidedisty)
		{
			lnk->dis->sidedistx += lnk->dis->deltadistx;
			lnk->dis->mapx += lnk->dis->stepx;
			lnk->dis->side = 0;
		}
		else
		{
			lnk->dis->sidedisty += lnk->dis->deltadisty;
			lnk->dis->mapy += lnk->dis->stepy;
			lnk->dis->side = 1;
		}
		if (lnk->area->split_map[lnk->dis->mapx][lnk->dis->mapy] == '1')
			which_wall(lnk);
	}
	if (lnk->dis->side == 1 || lnk->dis->side == 2)
		lnk->dis->walldist = (lnk->dis->mapx - lnk->dis->pos_x +
			(1 - lnk->dis->stepx) / 2) / lnk->dis->raydirx;
	else if (lnk->dis->side == 3 || lnk->dis->side == 4)
		lnk->dis->walldist = (lnk->dis->mapy - lnk->dis->pos_y +
			(1 - lnk->dis->stepy) / 2) / lnk->dis->raydiry;
}

void	set_sidedist(t_link *lnk)
{
	if (lnk->dis->raydirx < 0)
	{
		lnk->dis->stepx = -1;
		lnk->dis->sidedistx = (lnk->dis->pos_x - lnk->dis->mapx) * lnk->dis->deltadistx;
	}
	else
	{
		lnk->dis->stepx = 1;
		lnk->dis->sidedistx = (lnk->dis->mapx + 1.0 - lnk->dis->pos_x) * lnk->dis->deltadistx;
	}
	if (lnk->dis->raydiry < 0)
	{
		lnk->dis->stepy = -1;
		lnk->dis->deltadisty = (lnk->dis->pos_y - lnk->dis->mapy) * lnk->dis->deltadisty;
	}
	else
	{
		lnk->dis->stepy = 1;
		lnk->dis->sidedisty = (lnk->dis->mapy + 1.0 - lnk->dis->pos_y) * lnk->dis->deltadisty;
	}
	
}

void	set_point(t_link *lnk)
{
	lnk->dis->camerax = 2 * (double)lnk->dis->screen / (double)lnk->area->x - 1;
	lnk->dis->raydirx = lnk->dis->dirx + lnk->dis->planx * lnk->dis->camerax;
	lnk->dis->raydiry = lnk->dis->diry + lnk->dis->plany * lnk->dis->camerax;
	lnk->dis->mapx = (int)lnk->dis->pos_x;
	lnk->dis->mapy = (int)lnk->dis->pos_y;
	lnk->dis->deltadistx = fabs(1 / lnk->dis->raydirx);
	lnk->dis->deltadisty = fabs(1 / lnk->dis->raydiry);
	set_sidedist(lnk);
	set_walldist(lnk);
}

void	start_draw(t_link *lnk)
{
	if (!check_char_player(lnk))
		error("No direction of the player");
	lnk->dis->screen = 0;
	while (lnk->dis->screen < lnk->area->x)
	{
		set_point(lnk);
		set_draw(lnk);
		lnk->dis->screen++;
	}
}
