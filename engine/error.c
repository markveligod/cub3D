/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:22:21 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 11:22:43 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

/*
** Failure exit
*/

void	error(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

/*
** Success exit
*/

int		close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
