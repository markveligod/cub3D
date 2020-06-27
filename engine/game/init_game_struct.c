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
	ptr->player->movespeed = 0.1;
	ptr->player->rotspeed = 0.1;
	set_dir_plane(ptr, ptr->param->dir_player);
}

static void		add_text(t_ptr *ptr, int flag, char *path)
{
	if (!(ptr->img[flag]->img_ptr = mlx_xpm_file_to_image(ptr->mlx->mlx_ptr, path, &ptr->img[flag]->width, &ptr->img[flag]->height)))
		error("Texture path isn't valid");
	ptr->img[flag]->img_data = mlx_get_data_addr(ptr->img[flag]->img_ptr, &ptr->img[flag]->bpp, &ptr->img[flag]->size_line, &ptr->img[flag]->endian);
}

void			init_game_struct(t_ptr *ptr)
{
	int i;

	i = 0;
	if (!(ptr->mlx = (t_mlxparam *)malloc(sizeof(t_mlxparam))))
		error("struct mlx doesn't allocate in memory (*_*)");
	ptr->mlx->mlx_ptr = mlx_init();
	if (!(ptr->player = (t_player *)malloc(sizeof(t_player))))
		error("struct player doesn't allocate in memory (*_*)");
	if (!(ptr->sp = (t_sprite *)malloc(sizeof(t_sprite))))
		error("Struct mlx doesn't allocate in memory (*_*)");
	if (!(ptr->img = (t_image **)malloc(sizeof(t_image *) * 7)))
		error("struct image** doesn't allocate in memory (*_*)");
	ft_bzero(ptr->img, sizeof(t_image *) * 7);
	while (i <= 5)
	{
		if (!(ptr->img[i] = (t_image *)malloc(sizeof(t_image))))
			error("struct img* doesn't allocate in memory (*_*)");
		ft_bzero(ptr->img[i], sizeof(t_image));
		i++;
	}
	add_text(ptr, 1, ft_strtrim(ptr->param->north, " "));
	add_text(ptr, 2, ft_strtrim(ptr->param->south, " "));
	add_text(ptr, 3, ft_strtrim(ptr->param->west, " "));
	add_text(ptr, 4, ft_strtrim(ptr->param->east, " "));
}