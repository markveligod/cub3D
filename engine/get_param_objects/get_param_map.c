#include "../../cub.h"

void		get_param_map(int fd, char *line, t_ptr *ptr)
{
	int count;

	count = 1;
	check_line_map(line, ptr);
	ptr->param->line_map = ft_strjoin(line, "$");
	while (count > 0)
	{
		if ((count = get_next_line(fd, &line)) == (-1))
			error("File doesn't read (8_*)");
		check_line_map(line, ptr);
		ptr->param->line_map = ft_strjoin(ptr->param->line_map, line);
		ptr->param->line_map = ft_strjoin(ptr->param->line_map, "$");
	}
}