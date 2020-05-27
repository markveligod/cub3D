/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:17:49 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/27 16:17:49 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Calling an error
*/
void	error(char *str)
{
	int fd;

	fd = open("log.txt", O_WRONLY);
	ft_putendl_fd(str, fd);
	close(fd);
	exit(EXIT_FAILURE);
}