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
	Calling an error
*/
void	error(char *str)
{
	int fd;

	fd = open("log.txt", O_APPEND);
	ft_putendl_fd(str, fd);
	close(fd);
	exit(EXIT_FAILURE);
}

int		is_map_flag(char c)
{
	return(c == '0' || c == '1' || c == '2' || c == 'N' ||
	c == 'S' || c == 'W' || c == 'E' || c == ' ')
}

/*
	Getting the line size
*/
int		get_size_line(char *str)
{
	int i;
	int size;

	i = -1;
	size = 0;
	while (line[++i])
		if (is_map_flag(line[i]))
			size++;
	return (size);
}

char	*clean_map_line(char *line)
{
	char	*clean_line;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = get_size_line(line);
	if (!(clean_line = malloc(sizeof(char) * (size + 1))))
		error("ERROR: map_line didn't malloc");
	while (line[i])
	{
		if (!is_map_flag(line[i]))
			error("ERROR: invalid character in the file");
		clean_line[j] = line[i];
		i++;
		j++;
	}
	clean_line[j] = '-';
	clean_line[size] = '\0';
	return (clean_line);	
}