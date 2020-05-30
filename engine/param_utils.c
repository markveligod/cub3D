#include "../cub.h"

void	push_text(char *line, t_link *param, int flag)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (flag == 1)
		param->area->north = ft_strdup(&line[i]);
	else if (flag == 2)
		param->area->south = ft_strdup(&line[i]);
	else if (flag == 3)
		param->area->west = ft_strdup(&line[i]);
	else if (flag == 4)
		param->area->east = ft_strdup(&line[i]);
	else if (flag == 5)
		param->area->sprite = ft_strdup(&line[i]);
}

void	push_size_xy(char *line, t_link *param)
{
	int	i;

	i = 0;
	param->area->x = ft_atoi(&line[i]);
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] >= '0' && line[i] <= '9' && line[i])
		i++;
	param->area->y = ft_atoi(&line[i]);
	if (param->area->x > 1920)
		param->area->x = 1920;
	else if (param->area->x < 1)
		error("Resolution is too low");
	if (param->area->y > 1080)
		param->area->y = 1080;
	else if (param->area->y < 1)
		error("Resolution is too low");
}
