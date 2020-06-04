#include "../cub.h"

void	push_text(char *line, t_link *lnk, int flag)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (flag == 1)
		lnk->area->north = ft_strdup(&line[i]);
	else if (flag == 2)
		lnk->area->south = ft_strdup(&line[i]);
	else if (flag == 3)
		lnk->area->west = ft_strdup(&line[i]);
	else if (flag == 4)
		lnk->area->east = ft_strdup(&line[i]);
	else if (flag == 5)
		lnk->area->sprite = ft_strdup(&line[i]);
}

void	push_size_xy(char *line, t_link *lnk)
{
	int	i;

	i = 0;
	lnk->area->x = ft_atoi(&line[i]);
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] >= '0' && line[i] <= '9' && line[i])
		i++;
	lnk->area->y = ft_atoi(&line[i]);
	if (lnk->area->x > 1920)
		lnk->area->x = 1920;
	else if (lnk->area->x < 1)
		error("Resolution is too low");
	if (lnk->area->y > 1080)
		lnk->area->y = 1080;
	else if (lnk->area->y < 1)
		error("Resolution is too low");
}

void	push_floor_color(char *line, t_link *lnk)
{
	int i;

	i = 0;
	lnk->area->f_red_color = ft_atoi(line);
	while (line[i] != ',')
		i++;
	lnk->area->f_green_color = ft_atoi(line + i + 1);
	i++;
	while (line[i] != ',')
		i++;
	lnk->area->f_blue_color = ft_atoi(line + i + 1);
	if (!(lnk->area->f_red_color >= 0 && lnk->area->f_red_color <= 255) &&
	(lnk->area->f_green_color >= 0 && lnk->area->f_green_color <= 255) &&
	(lnk->area->f_blue_color >= 0 && lnk->area->f_blue_color <= 255))
		error("RGB values should be between 0 and 255");
}

void	push_ceilling_color(char *line, t_link *lnk)
{
	int i;

	i = 0;
	lnk->area->c_red_color = ft_atoi(line);
	while (line[i] != ',')
		i++;
	lnk->area->c_green_color = ft_atoi(line + i + 1);
	i++;
	while (line[i] != ',')
		i++;
	lnk->area->c_blue_color = ft_atoi(line + i + 1);
	if (!(lnk->area->c_red_color >= 0 && lnk->area->c_red_color <= 255) &&
	(lnk->area->c_green_color >= 0 && lnk->area->c_green_color <= 255) &&
	(lnk->area->c_blue_color >= 0 && lnk->area->c_blue_color <= 255))
		error("RGB values should be between 0 and 255");
}
