/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:24:39 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 11:24:47 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

/*
** Start function for getting all data from a file
*/

void			get_param_objects(int fd, t_ptr *ptr)
{
	int		count;
	char	*line;
	int		i;

	count = 1;
	i = 0;
	init_param_objects(ptr);
	while (count > 0)
	{
		if ((count = get_next_line(fd, &line)) == (-1))
			error("File doesn't read (*_8)");
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] == '1' || line[i] == '0' || line[i] == '2')
		{
			ptr->c->map++;
			get_param_map(fd, line, ptr);
			break ;
		}
		sort_param_objects(&line[i], ptr);
	}
	check_param_objects(ptr);
}
