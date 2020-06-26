#include "../../cub.h"

void		forward_key(t_ptr *ptr)
{
	if (ptr->param->split_map[(int)(ptr->player->pos_x + ptr->player->dir_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '1' &&
	ptr->param->split_map[(int)(ptr->player->pos_x + ptr->player->dir_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '2')
		ptr->player->pos_x += ptr->player->dir_x * ptr->player->movespeed;
	if (ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y + ptr->player->dir_y * ptr->player->movespeed)] != '1' &&
	ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y + ptr->player->dir_y * ptr->player->movespeed)] != '2')
		ptr->player->pos_y += ptr->player->dir_y * ptr->player->movespeed;
}

void		back_key(t_ptr *ptr)
{
	if (ptr->param->split_map[(int)(ptr->player->pos_x - ptr->player->dir_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '1' &&
	ptr->param->split_map[(int)(ptr->player->pos_x - ptr->player->dir_x * ptr->player->movespeed)][(int)ptr->player->pos_y] != '2')
		ptr->player->pos_x -= ptr->player->dir_x * ptr->player->movespeed;
	if (ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y - ptr->player->dir_y * ptr->player->movespeed)] != '1' &&
	ptr->param->split_map[(int)ptr->player->pos_x][(int)(ptr->player->pos_y - ptr->player->dir_y * ptr->player->movespeed)] != '2')
		ptr->player->pos_y -= ptr->player->dir_y * ptr->player->movespeed;
}
