/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:37:17 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 12:37:20 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

int		check_filename(char *filename)
{
	int size;

	size = ft_strlen(filename);
	if (filename[size - 1] == 'b' && filename[size - 2] == 'u' &&
	filename[size - 3] == 'c' && filename[size - 4] == '.')
		return (1);
	return (0);
}
