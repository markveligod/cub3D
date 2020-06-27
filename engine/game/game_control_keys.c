#include "../../cub.h"

void		forward_back_keys(t_ptr *ptr, int key)
{
	if (key == 13)
	{
		if (ptr->param->split_map[(int)(ptr->player->pos_x + ptr->player->dir_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '1' &&
		ptr->param->split_map[(int)(ptr->player->pos_x + ptr->player->dir_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '2')
			ptr->player->pos_x += ptr->player->dir_x * ptr->player->movespeed;
		if (ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y + ptr->player->dir_y * ptr->player->movespeed)] != '1' &&
		ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y + ptr->player->dir_y * ptr->player->movespeed)] != '2')
			ptr->player->pos_y += ptr->player->dir_y * ptr->player->movespeed;
	}
	if (key == 1)
	{
		if (ptr->param->split_map[(int)(ptr->player->pos_x - ptr->player->dir_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '1' &&
	ptr->param->split_map[(int)(ptr->player->pos_x - ptr->player->dir_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '2')
		ptr->player->pos_x -= ptr->player->dir_x * ptr->player->movespeed;
	if (ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y - ptr->player->dir_y * ptr->player->movespeed)] != '1' &&
	ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y - ptr->player->dir_y * ptr->player->movespeed)] != '2')
		ptr->player->pos_y -= ptr->player->dir_y * ptr->player->movespeed;
	}
}

void		rot_left_right_keys(t_ptr *ptr, int key)
{
	double olddir_x;
	double oldplane_x;

	if (key == 123)
	{
		olddir_x = ptr->player->dir_x;
		ptr->player->dir_x = ptr->player->dir_x * cos(ptr->player->rotspeed) - ptr->player->dir_y * sin(ptr->player->rotspeed);
		ptr->player->dir_y = olddir_x * (ptr->player->rotspeed) + ptr->player->dir_y * cos(ptr->player->rotspeed);
		oldplane_x = ptr->player->plane_x;
		ptr->player->plane_x = ptr->player->plane_x * cos(ptr->player->rotspeed) - ptr->player->plane_y * sin(ptr->player->rotspeed);
		ptr->player->plane_y = oldplane_x * sin(ptr->player->rotspeed) + ptr->player->plane_y * cos(ptr->player->rotspeed);
	}
	if (key == 124)
	{
		olddir_x = ptr->player->dir_x;
		ptr->player->dir_x = ptr->player->dir_x * cos(-ptr->player->rotspeed) - ptr->player->dir_y * sin(-ptr->player->rotspeed);
		ptr->player->dir_y = olddir_x * (-ptr->player->rotspeed) + ptr->player->dir_y * cos(-ptr->player->rotspeed);
		oldplane_x = ptr->player->plane_x;
		ptr->player->plane_x = ptr->player->plane_x * cos(-ptr->player->rotspeed) - ptr->player->plane_y * sin(-ptr->player->rotspeed);
		ptr->player->plane_y = oldplane_x * sin(-ptr->player->rotspeed) + ptr->player->plane_y * cos(-ptr->player->rotspeed);
	}
}

void		left_right_keys(t_ptr *ptr, int key)
{
	if (key == 2)
	{
		if (ptr->param->split_map[(int)(ptr->player->pos_x + ptr->player->plane_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '1' &&
		ptr->param->split_map[(int)(ptr->player->pos_x + ptr->player->plane_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '2')
			ptr->player->pos_x += ptr->player->plane_x * ptr->player->movespeed;
		if (ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y + ptr->player->plane_y * ptr->player->movespeed)] != '1' &&
		ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y + ptr->player->plane_y * ptr->player->movespeed)] != '2')
			ptr->player->pos_y += ptr->player->plane_y * ptr->player->movespeed;
	}
	if (key == 0)
	{
		if (ptr->param->split_map[(int)(ptr->player->pos_x - ptr->player->plane_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '1' &&
		ptr->param->split_map[(int)(ptr->player->pos_x - ptr->player->plane_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '2')
			ptr->player->pos_x -= ptr->player->plane_x * ptr->player->movespeed;
		if (ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y - ptr->player->plane_y * ptr->player->movespeed)] != '1' &&
		ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y - ptr->player->plane_y * ptr->player->movespeed)] != '2')
			ptr->player->pos_y -= ptr->player->plane_y * ptr->player->movespeed;
	}
}