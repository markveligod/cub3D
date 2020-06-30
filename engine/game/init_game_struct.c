/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:29:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 12:29:10 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static int		is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/*
** Function for determining the direction of the FOV by the map parameter
*/

static void		set_dir_plane(t_ptr *ptr, char flag)
{
	if (flag == 'N')
	{
		ptr->pl->pl_y = 0.66;
		ptr->pl->d_x = -1;
	}
	else if (flag == 'S')
	{
		ptr->pl->pl_y = -0.66;
		ptr->pl->d_x = 1;
	}
	else if (flag == 'W')
	{
		ptr->pl->pl_x = -0.66;
		ptr->pl->d_y = -1;
	}
	else if (flag == 'E')
	{
		ptr->pl->pl_x = 0.66;
		ptr->pl->d_y = 1;
	}
}

/*
** Function for initializing player parameters
*/

void			init_game_param(t_ptr *ptr)
{
	int i;
	int j;

	i = -1;
	while (ptr->p->split_map[++i])
	{
		j = -1;
		while (ptr->p->split_map[i][++j])
			if (is_player(ptr->p->split_map[i][j]))
			{
				ptr->pl->p_x = (double)i;
				ptr->pl->p_y = (double)j;
				break ;
			}
	}
	ptr->pl->d_x = 0.0;
	ptr->pl->d_y = 0.0;
	ptr->pl->pl_x = 0.0;
	ptr->pl->pl_y = 0.0;
	ptr->pl->ms = 0.1;
	ptr->pl->rots = 0.1;
	set_dir_plane(ptr, ptr->p->dir_pl);
}

/*
** Function for adding textures in image array
*/

void			add_text(t_ptr *ptr, int flag, char *path)
{
	if (!(ptr->img[flag]->img_ptr = mlx_xpm_file_to_image(ptr->m->mlx_ptr,
	path, &ptr->img[flag]->width, &ptr->img[flag]->height)))
		error("Texture path isn't valid");
	ptr->img[flag]->img_data = mlx_get_data_addr(ptr->img[flag]->img_ptr,
	&ptr->img[flag]->bpp, &ptr->img[flag]->size_line, &ptr->img[flag]->endian);
}

/*
** The main function to initialize the game structure
*/

void			init_game_struct(t_ptr *ptr)
{
	int i;

	i = 0;
	if (!(ptr->m = (t_mlxparam *)malloc(sizeof(t_mlxparam))))
		error("struct mlx doesn't allocate in memory (*_*)");
	ptr->m->mlx_ptr = mlx_init();
	if (!(ptr->pl = (t_player *)malloc(sizeof(t_player))))
		error("struct player doesn't allocate in memory (*_*)");
	if (!(ptr->b = (t_barrel *)malloc(sizeof(t_barrel))))
		error("Something went wrong with sprite initialization");
	if (!(ptr->b->buffer = malloc(sizeof(double) * (ptr->p->x + 1))))
		error("Memory allocation failed");
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
}
