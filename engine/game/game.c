/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:36:12 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 11:37:25 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

/*
** Function that tracks keystrokes
*/

static int		control_keys(int key, t_ptr *ptr)
{
	if (key == 53)
		close_win();
	else if (key == 13 || key == 1)
		forward_back_keys(ptr, key);
	else if (key == 123 || key == 124)
		rot_left_right_keys(ptr, key, 0, 0);
	else if (key == 0 || key == 2)
		left_right_keys(ptr, key);
	return (0);
}

/*
** Function to start rendering frames in the image array
*/

static int		play(t_ptr *ptr)
{
	ptr->img[0]->img_ptr = mlx_new_image(ptr->m->mlx_ptr,
	ptr->p->x, ptr->p->y);
	ptr->img[0]->img_data = mlx_get_data_addr(ptr->img[0]->img_ptr,
	&ptr->img[0]->bpp, &ptr->img[0]->size_line, &ptr->img[0]->endian);
	run_dda(ptr);
	mlx_put_image_to_window(ptr->m->mlx_ptr, ptr->m->win_ptr,
	ptr->img[0]->img_ptr, 0, 0);
	return (0);
}

/*
** Starting function to start initializing game parameters
*/

void			start_game(t_ptr *p)
{
	init_game_struct(p);
	add_text(p, 1, ft_strtrim(p->p->nr, " "));
	add_text(p, 2, ft_strtrim(p->p->so, " "));
	add_text(p, 3, ft_strtrim(p->p->we, " "));
	add_text(p, 4, ft_strtrim(p->p->ea, " "));
	add_text(p, 5, ft_strtrim(p->p->sp, " "));
	init_game_param(p);
	init_dda_struct(p);
	p->m->win_ptr = mlx_new_window(p->m->mlx_ptr, p->p->x,
	p->p->y, "CUB3D GAME");
	mlx_hook(p->m->win_ptr, 17, 1L << 0, close_win, (void *)0);
	mlx_hook(p->m->win_ptr, 2, 5, control_keys, p);
	mlx_loop_hook(p->m->mlx_ptr, play, p);
	mlx_loop(p->m->mlx_ptr);
}
