#include "../cub.h"

void	set_texture(t_link *lnk)
{
	if (lnk->dis->side == 1 || lnk->dis->side == 2)
	{
		lnk->dis->wallx = lnk->dis->pos_y + lnk->dis->walldist * lnk->dis->raydiry;
		lnk->dis->wallx -= floor(lnk->dis->wallx);
		lnk->dis->textx = (int)(lnk->dis->wallx * (double)lnk->img[lnk->dis->side]->width);
		if (lnk->dis->raydirx > 0)
			lnk->dis->textx = lnk->img[lnk->dis->side]->width - lnk->dis->textx - 1;
	}
	else if (lnk->dis->side == 3 || lnk->dis->side == 4)
	{
		lnk->dis->wallx = lnk->dis->pos_x + lnk->dis->walldist * lnk->dis->raydirx;
		lnk->dis->wallx -= floor(lnk->dis->wallx);
		lnk->dis->textx = (int)(lnk->dis->wallx * (double)lnk->img[lnk->dis->side]->width);
		if (lnk->dis->raydiry < 0)
			lnk->dis->textx = lnk->img[lnk->dis->side]->width - lnk->dis->textx - 1;
	}
}

int		draw_texture(t_link *lnk, int y)
{
	int i;

	i = 0;
	set_texture(lnk);
	lnk->dis->step = 1.0 * lnk->img[lnk->dis->side]->height / lnk->dis->lineheight;
	lnk->dis->textpos = (lnk->dis->drawstart - lnk->area->y / 2 + lnk->dis->lineheight / 2) * lnk->dis->step;
	while (y < lnk->dis->drawend)
	{
		lnk->dis->texty = (int)lnk->dis->textpos & (lnk->img[lnk->dis->side]->height - 1);
		lnk->dis->textpos += lnk->dis->step;
		lnk->img[0]->image_data[lnk->dis->screen * lnk->img[0]->depth / 8 + lnk->img[0]->size_line * y] 
			= lnk->img[lnk->dis->side]->image_data[lnk->dis->textx * (lnk->img[lnk->dis->side]->depth / 8) + lnk->dis->texty * lnk->img[lnk->dis->side]->size_line];
		lnk->img[0]->image_data[(lnk->dis->screen * lnk->img[0]->depth / 8 + lnk->img[0]->size_line * y) + 1]
			= lnk->img[lnk->dis->side]->image_data[(lnk->dis->textx * (lnk->img[lnk->dis->side]->depth / 8) + lnk->dis->texty * lnk->img[lnk->dis->side]->size_line) + 1];
		lnk->img[0]->image_data[(lnk->dis->screen * lnk->img[0]->depth / 8 + lnk->img[0]->size_line * y) + 2]
			= lnk->img[lnk->dis->side]->image_data[(lnk->dis->textx * (lnk->img[lnk->dis->side]->depth / 8) + lnk->dis->texty * lnk->img[lnk->dis->side]->size_line) + 2];
		y++;
		i++;
	}
	return (i);
}
