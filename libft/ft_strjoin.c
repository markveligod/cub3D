/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:15:30 by ck                #+#    #+#             */
/*   Updated: 2020/05/27 19:55:31 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*array;

	if (s1 && s2)
	{
		size = ft_strlen(s1) + ft_strlen(s2);
		if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		i = 0;
		j = -1;
		while (s1[++j])
			array[i++] = s1[j];
		j = -1;
		while (s2[++j])
			array[i++] = s2[j];
		array[i] = '\0';
		return (array);
	}
	return (NULL);
}
