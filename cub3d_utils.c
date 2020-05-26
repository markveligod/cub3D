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

/*
	Getting the line size
*/
int		get_size_line()
{

}

char	*clean_map_line(char *line)
{
	char	*clean_line;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = 
}