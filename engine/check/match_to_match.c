/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_to_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:48:19 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 12:48:28 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

/*
** Function to initialize the structure match to match
*/

static void		init_match_struct(t_ptr *ptr)
{
	if (!(ptr->mt = (t_match *)malloc(sizeof(t_match))))
		error("struct check doesn't allocate in memory (*_*)");
	ptr->mt->line_up_1 = 0;
	ptr->mt->line_up_2 = 0;
	ptr->mt->line_up_3 = 0;
	ptr->mt->line_up_4 = 0;
	ptr->mt->line_down_1 = 0;
	ptr->mt->line_down_2 = 0;
	ptr->mt->line_down_3 = 0;
	ptr->mt->line_down_4 = 0;
}

/*
** Function for casting two points (up line) left and right
*/

static void		push_line_up(char *line, t_ptr *ptr, int j)
{
	while (line[j] != '1')
		j++;
	ptr->mt->line_up_1 = j;
	ptr->mt->line_up_3 = j;
	while (line[j])
		j++;
	while (line[j] != '1')
		j--;
	ptr->mt->line_up_2 = j;
	ptr->mt->line_up_4 = j;
}

/*
** Function to move one line further
*/

static void		push_next(char *line, t_ptr *ptr)
{
	int j;

	j = 0;
	while (line[j] != '1')
		j++;
	ptr->mt->line_down_1 = j;
	while (line[j] == '1')
		j++;
	ptr->mt->line_down_2 = j - 1;
	while (line[j])
		j++;
	j--;
	while (line[j] != '1')
		j--;
	ptr->mt->line_down_4 = j;
	while (line[j] == '1')
		j--;
	ptr->mt->line_down_3 = j + 1;
}

/*
** Function for checking two lines for unit matching
*/

static void		check_match(t_ptr *ptr)
{
	if ((ptr->mt->line_down_1 < (ptr->mt->line_up_1 - 1) &&
	ptr->mt->line_down_2 < (ptr->mt->line_up_1 - 1)) ||
	(ptr->mt->line_down_1 > (ptr->mt->line_up_2 + 1) &&
	ptr->mt->line_down_2 > (ptr->mt->line_up_2 + 1)))
		error("The left edge does not close the map. (@_@)");
	if ((ptr->mt->line_down_3 < (ptr->mt->line_up_3 - 1) &&
	ptr->mt->line_down_4 < (ptr->mt->line_up_3 - 1)) ||
	(ptr->mt->line_down_3 > (ptr->mt->line_up_4 + 1) &&
	ptr->mt->line_down_4 > (ptr->mt->line_up_4 + 1)))
		error("The right edge does not close the map. (@_@)");
	ptr->mt->line_up_1 = ptr->mt->line_down_1;
	ptr->mt->line_up_2 = ptr->mt->line_down_2;
	ptr->mt->line_up_3 = ptr->mt->line_down_3;
	ptr->mt->line_up_4 = ptr->mt->line_down_4;
}

/*
** The main function to start checking two lines of a map
*/

void			match_to_match(char **arr, t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	init_match_struct(ptr);
	while (arr[i])
	{
		if (i == 0)
		{
			push_line_up(arr[i], ptr, 0);
			i++;
			continue ;
		}
		if (arr[i + 1] == NULL)
		{
			push_next(arr[i], ptr);
			check_match(ptr);
			return ;
		}
		push_next(arr[i], ptr);
		check_match(ptr);
		i++;
	}
}
