#include "../../cub.h"

/*
** Getting map data from files and creating a two-dimensional array
*/

void		get_param_map(int fd, char *line, t_ptr *ptr)
{
	int count;

	count = 1;
	check_line_map(line, ptr);
	ptr->p->line_map = ft_strjoin(line, "$");
	while (count > 0)
	{
		if ((count = get_next_line(fd, &line)) == (-1))
			error("File doesn't read (8_*)");
		check_line_map(line, ptr);
		ptr->p->line_map = ft_strjoin(ptr->p->line_map, line);
		ptr->p->line_map = ft_strjoin(ptr->p->line_map, "$");
	}
	ptr->p->split_map = ft_split(ptr->p->line_map, '$');
}
