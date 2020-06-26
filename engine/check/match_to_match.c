#include "../../cub.h"

static void		init_match_struct(t_ptr *ptr)
{
	if(!(ptr->match = (t_match *)malloc(sizeof(t_match))))
		error("struct check doesn't allocate in memory (*_*)");
	ptr->match->line_up_1 = 0;
	ptr->match->line_up_2 = 0;
	ptr->match->line_up_3 = 0;
	ptr->match->line_up_4 = 0;
	ptr->match->line_down_1 = 0;
	ptr->match->line_down_2 = 0;
	ptr->match->line_down_3 = 0;
	ptr->match->line_down_4 = 0;
}

static void		push_line_up_down(short int *l1, short int *l2, short int *l3, short int *l4, char *line)
{
	int j;

	j = 0;
	while (line[j] != '1')
		j++;
	*l1 = j;
	*l3 = j;
	while (line[j] == '1')
		j++;
	*l2 = j - 1;
	*l4 = j - 1;
}

static void		push_next(char *line, t_ptr *ptr)
{
	int j;

	j = 0;
	while (line[j] != '1')
		j++;
	ptr->match->line_down_1 = j;
	while (line[j] == '1')
		j++;
	ptr->match->line_down_2 = j - 1;
	while (line[j])
		j++;
	j--;
	while (line[j] != '1')
		j--;
	ptr->match->line_down_4 = j;
	while (line[j] == '1')
		j--;
	ptr->match->line_down_3 = j + 1;
}

static void		check_match(t_ptr *ptr)
{
	if ((ptr->match->line_down_1 < ptr->match->line_up_1 && ptr->match->line_down_2 < ptr->match->line_up_1) ||
	(ptr->match->line_down_1 > ptr->match->line_up_2 && ptr->match->line_down_2 > ptr->match->line_up_2))
		error("The left edge does not close the map. (@_@)");
	if ((ptr->match->line_down_3 < ptr->match->line_up_3 && ptr->match->line_down_4 < ptr->match->line_up_3) ||
	(ptr->match->line_down_3 > ptr->match->line_up_4 && ptr->match->line_down_4 > ptr->match->line_up_4))
	{
		printf("Up: %d %d %d %d\nDown: %d %d %d %d\n", ptr->match->line_up_1, ptr->match->line_up_2, ptr->match->line_up_3, ptr->match->line_up_4, ptr->match->line_down_1, ptr->match->line_down_2, ptr->match->line_down_3, ptr->match->line_down_4);
		error("The right edge does not close the map. (@_@)");
	}
	ptr->match->line_up_1 = ptr->match->line_down_1;
	ptr->match->line_up_2 = ptr->match->line_down_2;
	ptr->match->line_up_3 = ptr->match->line_down_3;
	ptr->match->line_up_4 = ptr->match->line_down_4;
}

void			match_to_match(char **arr, t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	init_match_struct(ptr);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		if (i == 0)
		{
			push_line_up_down(&(ptr->match->line_up_1), &(ptr->match->line_up_2), &(ptr->match->line_up_3),
			&(ptr->match->line_up_4), arr[i]);
			i++;
			continue ;
		}
		if (arr[i + 1] == NULL)
		{
			push_line_up_down(&(ptr->match->line_down_1), &(ptr->match->line_down_2), &(ptr->match->line_down_3),
			&(ptr->match->line_down_4), arr[i]);
		}
		push_next(arr[i], ptr);
		check_match(ptr);
		i++;
	}
}