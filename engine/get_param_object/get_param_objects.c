#include "../../cub.h"

void	get_param_objects(int fd, t_ptr *ptr)
{
	int		count;
	char	*line;
	int		i;

	count = 1;
	i = 0;
	init_param_objects(ptr);
	while (count > 0)
	{
		if ((count = get_next_line(fd, &line)) == -1)
			error("File doesn't read (*_8)");
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		sort_param_object(&line[i], ptr);
	}
}