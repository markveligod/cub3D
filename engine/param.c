#include "../cub.h"

int		check_num_map(char c)
{
	return (c == '0' || c == '1' || c == '2');
}

void	get_init_param(t_link *param)
{
	if (!(param->area = (t_area *)ft_calloc(sizeof(t_area), 1)))
		error("Something went wrong with scene initialization (-_-) ");
}

void	get_sort_param(char *line, t_link *param)
{
	if (line[0] == '\0')
		return ;
	else if (line[0] == 'R')
		push_size_xy((line + 1), param);
	else if (line[0] == 'N' && line[1] == 'O')
		push_text((line + 2), param, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		push_text((line + 2), param, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		push_text((line + 2), param, 3);
	else if (line[0] == 'E' && line[1] == 'A')
		push_text((line + 2), param, 4);
	else if (line[0] == 'S' && line[1] != 'O')
		push_text((line + 1), param, 5);
	else
		error("Unrecognized element in file");
}

void	get_param_file(int fd, t_link *param)
{
	char	*line;
	int		count;
	int		i;

	while (count > 0)
	{
		i = 0;
		if ((count = get_next_line(fd, &line)) == (-1))
			error("The file can't be read (*.*) ");
		while (line[i] == ' ')
			i++;
		if (check_num_map(line[i]))
			break;
		get_sort_param(&line[i], param);		
	}
	if(check_num_map(line[i]))
	{
		line = get_map_param(line);
		param->area->linear_map = ft_strjoin(param->area->linear_map, line);
		while (count > 0)
		{
			if ((count = get_next_line(fd, &line)) == (-1))
				error("The file can't be read (*.*) ");
			line = get_map_param(line);
			param->area->linear_map = ft_strjoin(param->area->linear_map, line);
		}
	}
	param->area->brut_map = ft_split(param->area->linear_map, '$');
}