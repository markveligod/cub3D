/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:39:01 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/27 14:39:01 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*clean_map_line(char *line)
{
	char	*clean_line;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(line);
	if (!(clean_line = malloc(sizeof(char) * (size + 2))))
		error("ERROR: map_line didn't malloc");
	while (line[i])
	{
		if (line[i] != '\n')
			clean_line[j] = line[i];
		j++;
		i++;
	}
	clean_line[j] = '$';
	clean_line[size + 2] = '\0';
	return (clean_line);	
}
