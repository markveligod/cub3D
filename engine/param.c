#include "../cub.h"

int		check_num_map(char c)
{
	return (c == '0' || c == '1' || c == '2');
}

void	get_init_param(t_link *lnk)
{
	int i;

	i = -1;
	if (!(lnk->area = (t_area *)ft_calloc(sizeof(t_area), 1)))
		error("Something went wrong with area initialization (-_-) ");
	if (!(lnk->dis = (t_display *)ft_calloc(sizeof(t_display), 1)))
		error("Something went wrong with display initialization (-_-) ");
	if (!(lnk->img = (t_image **)ft_calloc(sizeof(t_image *), 1)))
		error("Something went wrong with image initialization (-_-) ");
	while (++i <= 5)
		if (!(lnk->img[i] = (t_image *)ft_calloc(sizeof(t_image), 1)))
			error("Something went wrong with image cicle initialization (-_-)");
}

void	get_sort_param(char *line, t_link *lnk)
{
	if (line[0] == 'R')
		push_size_xy((line + 1), lnk);
	else if (line[0] == 'N' && line[1] == 'O')
		push_text((line + 2), lnk, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		push_text((line + 2), lnk, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		push_text((line + 2), lnk, 3);
	else if (line[0] == 'E' && line[1] == 'A')
		push_text((line + 2), lnk, 4);
	else if (line[0] == 'S' && line[1] != 'O')
		push_text((line + 1), lnk, 5);
	else if (line[0] == 'F')
		push_floor_color((line + 1), lnk);
	else if (line[0] == 'C')
		push_ceilling_color((line + 1), lnk);
	else
		error("Unknown char !!!");
}

void	get_param_file(int fd, t_link *lnk)
{
	char	*line;
	int		count;
	int		i;

	count = 1;
	while (count > 0)
	{
		i = 0;
		if ((count = get_next_line(fd, &line)) == (-1))
			error("The file can't be read (*.*) ");
		while (line[i] == ' ')
			i++;
		if (check_num_map(line[i]))
			break ;
		if (line[i] == 13)
			continue ;
		get_sort_param(&line[i], lnk);
	}
	if(check_num_map(line[i]))
	{
		line = get_map_param(line);
		lnk->area->linear_map = ft_strjoin(lnk->area->linear_map, line);
		while (count > 0)
		{
			if ((count = get_next_line(fd, &line)) == (-1))
				error("The file can't be read (*.*) ");
			line = get_map_param(line);
			lnk->area->linear_map = ft_strjoin(lnk->area->linear_map, line);
		}
	}
	lnk->area->split_map = ft_split(lnk->area->linear_map, '$');
}
