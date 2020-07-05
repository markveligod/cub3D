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

int				control_keys(int key, t_ptr *ptr)
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

int				play(t_ptr *ptr)
{
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
	mlx_hook(p->m->win_ptr, 17, 1L << 0, close_win, (void *)0);
	mlx_hook(p->m->win_ptr, 2, 5, control_keys, p);
	mlx_loop_hook(p->m->mlx_ptr, play, p);
	mlx_loop(p->m->mlx_ptr);
}
