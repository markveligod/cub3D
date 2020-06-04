#include "../cub.h"

int		check_char_player(t_link *param)
{
	short int i;
	short int j;

	i = -1;
	while (param->area->brut_map[++i])
	{
		j = -1;
		while (param->area->brut_map[i][++j])
			if (param->area->brut_map[i][j] == 'N' || param->area->brut_map[i][j] == 'S' ||
			param->area->brut_map[i][j] == 'W' || param->area->brut_map[i][j] == 'E')
			{
				param->display->pos_x = (double)i + 0.5;
				param->display->pos_y = (double)j + 0.5;
				set_player(param, param->area->brut_map[i][j]);
				return (1);
			}
	}
	return (0);
}

void	which_wall(t_link *param)
{
	param->display->hit = 1;
	if (!param->display->side)
	{
		if (param->display->raydirx < 0)
			param->display->side = 1;
		else if (param->display->raydirx > 0)
			param->display->side = 2;
	}
	else if (param->display->side == 1)
	{
		if (param->display->raydiry < 0)
			param->display->side = 3;
		else if (param->display->raydiry > 0)
			param->display->side = 4;
	}
}

int		draw_ceiling(t_link *param, int y)
{
	while (y < param->display->drawstart)
	{
		param->image->image_data
			[param->display->screen * param->image->depth / 8 + param->image->size_line * y] =
			param->area->c_red_color;
		param->image->image_data
			[(param->display->screen * param->image->depth / 8 + param->image->size_line * y) + 1] =
			param->area->c_green_color;
		param->image->image_data
			[(param->display->screen * param->image->depth / 8 + param->image->size_line * y) + 2] =
			param->area->c_blue_color;
		y++;
	}
	return (y);
}

void	draw_floor(t_link *param, int y)
{
	while (y < param->area->y)
	{
		param->image->image_data
			[param->display->screen * param->image->depth / 8 + param->image->size_line * y] =
			param->area->f_red_color;
		param->image->image_data
			[(param->display->screen * param->image->depth / 8 + param->image->size_line * y) + 1] =
			param->area->f_green_color;
		param->image->image_data
			[(param->display->screen * param->image->depth / 8 + param->image->size_line * y) + 2] =
			param->area->f_blue_color;
		y++;
	}
}

void	set_draw(t_link *param)
{
	int	y;

	y = 0;
	param->display->lineheight = (int)(param->area->y / param->display->walldist);
	param->display->drawstart = -param->display->lineheight / 2 + param->area->y / 2;
	if (param->display->drawstart < 0)
		param->display->drawstart = 0;
	param->display->drawend = param->display->lineheight / 2 + param->area->y / 2;
	if (param->display->drawend >= param->area->y)
		param->display->drawend = param->area->y - 1;
	y += draw_ceiling(param, y);
	y += draw_texture(param, y);
	draw_floor(param, y);
}