/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:53:03 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 13:53:05 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*array;

	if (!s1 && !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = -1;
	if (s1)
		while (s1[++j])
			array[i++] = s1[j];
	j = -1;
	while (s2[++j])
		array[i++] = s2[j];
	array[i] = '\0';
	return (array);
}
