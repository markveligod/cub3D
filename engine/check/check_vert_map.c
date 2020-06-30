/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vert_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:09:46 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 15:09:48 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

static void		push_left_line(char **arr, int j, t_ptr *ptr)
{
	int i;

	i = 0;
	while (arr[i][j] == ' ')
		i++;
	ptr->mt->line_up_1 = i;
	while (arr[i][j] == '1')
	{
		if (arr[i][j] != '1')
			break;
		i++;
	}
	ptr->mt->line_up_1 = i;
	while (arr[i][j])
	{
		if (arr[i + 1] == NULL)
			break;
		i++;
	}
	while (arr[i][j] == ' ')
		i--;
	
}

static int		check_start(char **arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (arr[i][j])
	{
		if (arr[i][j] == '1')
			return (j);
		if (arr[i + 1] == NULL)
		{
			i = 0;
			j++;
		}
		i++;
	}
}

void			check_vert_map(t_ptr *ptr, char **arr)
{
	int i;
	int j;

	i = 0;
	j = check_start(arr);
	push_left_line(arr, j, ptr);
	while (arr[i][j])
	{
		push_r_next();
		check_lr_side();
		if (arr[i] == NULL)
		{
			j++;
			i = 0;
		}
		i++;
	}
}
