#include "../../cub.h"

void		check_line_map(char *line, t_ptr *ptr)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !(line[i] >= '0' && line[i] <= '2') &&
		line[i] != 'N' && line[i] != 'S' && line[i] != 'E' &&
		line[i] != 'W' && line[i] != '\t')
			error("Unknown symbol on map line");
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
		line[i] == 'W')
		{
			ptr->param->dir_player = line[i];
			ptr->check->pos_player++;
		}
		i++;
	}
}