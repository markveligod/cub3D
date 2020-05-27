/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:51:48 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/25 15:51:48 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Getting the line size
*/
int		get_size_line(char *str)
{
	int i;
	int size;

	i = -1;
	size = 0;
	while (str[++i])
		if (is_map_flag(str[i]))
			size++;
	return (size);
}

int		check_al_param(char *line, t_link *param)
{
	if (line[0] == '\0')
		return (0);
	else if (line[0] == 'R')
		push_size_x_y((line + 1), param);
	else if (line[0] == 'N' && line[1] == 'O')
		push_text((line + 2), param, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		push_text((line + 2), param, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		push_text((line + 2), param, 3);
	else if (line[0] == 'E' && line[1] == 'A')
		push_text((line + 2), param, 4);
	else if (line[0] == 'S' && line[1] != 'O')
		push_text((line + 1), param, 5);
	else if (line[0] == 'F')
		push_f_col((line + 1), param);
	else if (line[0] == 'C')
		push_c_col((line + 1), param);
	else
		return (0);
	return (1);
}

void	push_text(char *line, t_link *param, int flag)
{
	int	i;

	i = 0;
	while (line[i] = ' ' && line[i])
		i++;
	if (flag == 1)
		param->area->north = ft_strdup(&line[i]);
	else if (flag == 2)
		param->area->south = ft_strdup(&line[i]);
	else if (flag == 3)
		param->area->west = ft_strdup(&line[i]);
	else if (flag == 4)
		param->area->east = ft_strdup(&line[i]);
	else if (flag == 5)
		param->area->sprite = ft_strdup(&line[i]);
}

void	push_size_x_y(char *line, t_link *param)
{
	int	i;

	i = 0;
	param->area->x = ft_atoi(&line[i]);
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] >= '0' && line[i] <= '9' && line[i])
		i++;
	param->area->y = ft_atoi(&line[i]);
	if (param->area->x > 1920)
		param->area->x = 1920;
	else if (param->area->x < 1)
		error("ERROR: Resolution is too low");
	if (param->area->y > 1080)
		param->area->y = 1080;
	else if (param->area->y < 1)
		error("ERROR: Resolution is too low");
}