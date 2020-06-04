#include "../cub.h"

int		check_char_player(t_link *lnk)
{
	short int i;
	short int j;

	i = -1;
	while (lnk->area->split_map[++i])
	{
		j = -1;
		while (lnk->area->split_map[i][++j])
			if (lnk->area->split_map[i][j] == 'N' || lnk->area->split_map[i][j] == 'S' ||
			lnk->area->split_map[i][j] == 'W' || lnk->area->split_map[i][j] == 'E')
			{
				lnk->dis->pos_x = (double)i + 0.5;
				lnk->dis->pos_y = (double)j + 0.5;
				set_player(lnk, lnk->area->split_map[i][j]);
				return (1);
			}
	}
	return (0);
}

void	which_wall(t_link *lnk)
{
	lnk->dis->hit = 1;
	if (!lnk->dis->side)
	{
		if (lnk->dis->raydirx < 0)
			lnk->dis->side = 1;
		else if (lnk->dis->raydirx > 0)
			lnk->dis->side = 2;
	}
	else if (lnk->dis->side == 1)
	{
		if (lnk->dis->raydiry < 0)
			lnk->dis->side = 3;
		else if (lnk->dis->raydiry > 0)
			lnk->dis->side = 4;
	}
}

int		draw_ceiling(t_link *lnk, int y)
{
	while (y < lnk->dis->drawstart)
	{
		lnk->img[0]->image_data
			[lnk->dis->screen * lnk->img[0]->depth / 8 + lnk->img[0]->size_line * y] =
			lnk->area->c_red_color;
		lnk->img[0]->image_data
			[(lnk->dis->screen * lnk->img[0]->depth / 8 + lnk->img[0]->size_line * y) + 1] =
			lnk->area->c_green_color;
		lnk->img[0]->image_data
			[(lnk->dis->screen * lnk->img[0]->depth / 8 + lnk->img[0]->size_line * y) + 2] =
			lnk->area->c_blue_color;
		y++;
	}
	return (y);
}

void	draw_floor(t_link *lnk, int y)
{
	while (y < lnk->area->y)
	{
		lnk->img[0]->image_data
			[lnk->dis->screen * lnk->img[0]->depth / 8 + lnk->img[0]->size_line * y] =
			lnk->area->f_red_color;
		lnk->img[0]->image_data
			[(lnk->dis->screen * lnk->img[0]->depth / 8 + lnk->img[0]->size_line * y) + 1] =
			lnk->area->f_green_color;
		lnk->img[0]->image_data
			[(lnk->dis->screen * lnk->img[0]->depth / 8 + lnk->img[0]->size_line * y) + 2] =
			lnk->area->f_blue_color;
		y++;
	}
}

void	set_draw(t_link *lnk)
{
	int	y;

	y = 0;
	lnk->dis->lineheight = (int)(lnk->area->y / lnk->dis->walldist);
	lnk->dis->drawstart = -lnk->dis->lineheight / 2 + lnk->area->y / 2;
	if (lnk->dis->drawstart < 0)
		lnk->dis->drawstart = 0;
	lnk->dis->drawend = lnk->dis->lineheight / 2 + lnk->area->y / 2;
	if (lnk->dis->drawend >= lnk->area->y)
		lnk->dis->drawend = lnk->area->y - 1;
	y += draw_ceiling(lnk, y);
	y += draw_texture(lnk, y);
	draw_floor(lnk, y);
}