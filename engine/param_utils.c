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

void	push_floor_color(char *line, t_link *param)
{
	int i;

	i = 0;
	param->area->f_red_color = ft_atoi(line);
	while (line[i] != ',')
		i++;
	param->area->f_green_color = ft_atoi(line + i + 1);
	i++;
	while (line[i] != ',')
		i++;
	param->area->f_blue_color = ft_atoi(line + i + 1);
	if (!(param->area->f_red_color >= 0 && param->area->f_red_color <= 255) &&
	(param->area->f_green_color >= 0 && param->area->f_green_color <= 255) &&
	(param->area->f_blue_color >= 0 && param->area->f_blue_color <= 255))
		error("RGB values should be between 0 and 255");
}

void	push_ceilling_color(char *line, t_link *param)
{
	int i;

	i = 0;
	param->area->c_red_color = ft_atoi(line);
	while (line[i] != ',')
		i++;
	param->area->c_green_color = ft_atoi(line + i + 1);
	i++;
	while (line[i] != ',')
		i++;
	param->area->c_blue_color = ft_atoi(line + i + 1);
	if (!(param->area->c_red_color >= 0 && param->area->c_red_color <= 255) &&
	(param->area->c_green_color >= 0 && param->area->c_green_color <= 255) &&
	(param->area->c_blue_color >= 0 && param->area->c_blue_color <= 255))
		error("RGB values should be between 0 and 255");
}
