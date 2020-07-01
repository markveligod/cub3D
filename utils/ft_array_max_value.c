/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_max_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:31:02 by ckakuna           #+#    #+#             */
/*   Updated: 2020/07/01 13:31:03 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_array_max_value(char **arr)
{
	int res;
	int temp;
	int i;
	int j;

	i = 0;
	temp = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			j++;
		if (j > temp)
		{
			temp = j;
			res = i;
		}
		i++;
	}
	return (res);
}
