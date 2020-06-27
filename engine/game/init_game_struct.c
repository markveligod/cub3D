#include "../../cub.h"

static int		is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void		set_dir_plane(t_ptr *ptr, char flag)
{
	if (flag == 'N')
	{
		ptr->player->plane_y = 0.66;
		ptr->player->dir_x = -1;
	}
	else if (flag == 'S')
	{
		ptr->player->plane_y = -0.66;
		ptr->player->dir_x = 1;
	}
	else if (flag == 'W')
	{
		ptr->player->plane_x = -0.66;
		ptr->player->dir_y = -1;
	}
	else if (flag == 'E')
	{
		ptr->player->plane_x = 0.66;
		ptr->player->dir_y = 1;
	}
}

void			init_game_param(t_ptr *ptr)
{
	int i;
	int j;

	i = -1;
	while (ptr->param->split_map[++i])
	{
		j = -1;
		while (ptr->param->split_map[i][++j])
			if (is_player(ptr->param->split_map[i][j]))
			{
				ptr->player->pos_x = (double)i;
				ptr->player->pos_y = (double)j;
				break ;
			}
	}
	ptr->player->dir_x = 0.0;
	ptr->player->dir_y = 0.0;
	ptr->player->plane_x = 0.0;
	ptr->player->plane_y = 0.0;
	ptr->player->movespeed = 0.2;
	ptr->player->rotspeed = 0.1;
	set_dir_plane(ptr, ptr->param->dir_player);
}

void			init_game_struct(t_ptr *ptr)
{
	if (!(ptr->mlx = (t_mlxparam *)malloc(sizeof(t_mlxparam))))
		error("struct mlx doesn't allocate in memory (*_*)");
	if (!(ptr->player = (t_player *)malloc(sizeof(t_player))))
		error("struct player doesn't allocate in memory (*_*)");
}