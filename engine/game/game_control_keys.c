#include "../../cub.h"

/*
** Function for changing the frame forward or backward
*/

void		forward_back_keys(t_ptr *p, int key)
{
	if (key == 13)
	{
		if (p->p->split_map[(int)(p->pl->p_x + p->pl->d_x * p->pl->ms)]
		[(int)p->pl->p_y] != '1' && p->p->split_map[(int)(p->pl->p_x +
		p->pl->d_x * p->pl->ms)][(int)p->pl->p_y] != '2')
			p->pl->p_x += p->pl->d_x * p->pl->ms;
		if (p->p->split_map[(int)p->pl->p_x][(int)(p->pl->p_y +
		p->pl->d_y * p->pl->ms)] != '1' && p->p->split_map[(int)p->pl->p_x]
		[(int)(p->pl->p_y + p->pl->d_y * p->pl->ms)] != '2')
			p->pl->p_y += p->pl->d_y * p->pl->ms;
	}
	if (key == 1)
	{
		if (p->p->split_map[(int)(p->pl->p_x - p->pl->d_x * p->pl->ms)]
		[(int)p->pl->p_y] != '1' && p->p->split_map[(int)(p->pl->p_x -
		p->pl->d_x * p->pl->ms)][(int)p->pl->p_y] != '2')
			p->pl->p_x -= p->pl->d_x * p->pl->ms;
		if (p->p->split_map[(int)p->pl->p_x][(int)(p->pl->p_y -
		p->pl->d_y * p->pl->ms)] != '1' && p->p->split_map[(int)p->pl->p_x]
		[(int)(p->pl->p_y - p->pl->d_y * p->pl->ms)] != '2')
			p->pl->p_y -= p->pl->d_y * p->pl->ms;
	}
}

/*
** Function for changing the rotate to left or right frame
*/

void		rot_left_right_keys(t_ptr *p, int key, double olddx, double oldplx)
{
	if (key == 123)
	{
		olddx = p->pl->d_x;
		p->pl->d_x = p->pl->d_x * cos(p->pl->rots) - p->pl->d_y *
		sin(p->pl->rots);
		p->pl->d_y = olddx * (p->pl->rots) + p->pl->d_y * cos(p->pl->rots);
		oldplx = p->pl->pl_x;
		p->pl->pl_x = p->pl->pl_x * cos(p->pl->rots) - p->pl->pl_y *
		sin(p->pl->rots);
		p->pl->pl_y = oldplx * sin(p->pl->rots) + p->pl->pl_y *
		cos(p->pl->rots);
	}
	if (key == 124)
	{
		olddx = p->pl->d_x;
		p->pl->d_x = p->pl->d_x * cos(-p->pl->rots) - p->pl->d_y *
		sin(-p->pl->rots);
		p->pl->d_y = olddx * (-p->pl->rots) + p->pl->d_y * cos(-p->pl->rots);
		oldplx = p->pl->pl_x;
		p->pl->pl_x = p->pl->pl_x * cos(-p->pl->rots) - p->pl->pl_y *
		sin(-p->pl->rots);
		p->pl->pl_y = oldplx * sin(-p->pl->rots) + p->pl->pl_y *
		cos(-p->pl->rots);
	}
}

/*
** Function for changing the left or right frame
*/

void		left_right_keys(t_ptr *ptr, int key)
{
	if (key == 2)
	{
		if (ptr->p->split_map[(int)(ptr->pl->p_x + ptr->pl->pl_x * ptr->pl->ms)]
		[(int)ptr->pl->p_y] != '1' && ptr->p->split_map[(int)(ptr->pl->p_x +
		ptr->pl->pl_x * ptr->pl->ms)][(int)ptr->pl->p_y] != '2')
			ptr->pl->p_x += ptr->pl->pl_x * ptr->pl->ms;
		if (ptr->p->split_map[(int)ptr->pl->p_x][(int)(ptr->pl->p_y +
		ptr->pl->pl_y * ptr->pl->ms)] != '1' && ptr->p->split_map[(int)
		ptr->pl->p_x][(int)(ptr->pl->p_y + ptr->pl->pl_y * ptr->pl->ms)] != '2')
			ptr->pl->p_y += ptr->pl->pl_y * ptr->pl->ms;
	}
	if (key == 0)
	{
		if (ptr->p->split_map[(int)(ptr->pl->p_x - ptr->pl->pl_x * ptr->pl->ms)]
		[(int)ptr->pl->p_y] != '1' && ptr->p->split_map[(int)(ptr->pl->p_x -
		ptr->pl->pl_x * ptr->pl->ms)][(int)ptr->pl->p_y] != '2')
			ptr->pl->p_x -= ptr->pl->pl_x * ptr->pl->ms;
		if (ptr->p->split_map[(int)ptr->pl->p_x][(int)(ptr->pl->p_y -
		ptr->pl->pl_y * ptr->pl->ms)] != '1' && ptr->p->split_map[(int)
		ptr->pl->p_x][(int)(ptr->pl->p_y - ptr->pl->pl_y * ptr->pl->ms)] != '2')
			ptr->pl->p_y -= ptr->pl->pl_y * ptr->pl->ms;
	}
}
