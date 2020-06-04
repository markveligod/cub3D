#include "../cub.h"

int		draw_texture(t_link *param, int y)
{
	int i;

	i = 0;
	param->display->step = 1.0 * param->image->height / param->display->lineheight;
	param->display->textpos = (param->display->drawstart - param->area->y / 2 + param->display->lineheight / 2) * param->display->step;
	while (y < param->display->drawend)
	{
		param->display->texty = (int)param->display->textpos & (param->image->height - 1);
		param->display->textpos += param->display->step;
		param->image->image_data[param->display->screen * param->image->depth / 8 + param->image->size_line * y] 
			= param->image->image_data[param->display->textx * (param->image->depth / 8) + param->display->texty * param->image->size_line];
		param->image->image_data[(param->display->screen * param->image->depth / 8 + param->image->size_line * y) + 1]
			= param->image->image_data[(param->display->textx * (param->image->depth / 8) + param->display->texty * param->image->size_line) + 1];
		param->image->image_data[(param->display->screen * param->image->depth / 8 + param->image->size_line * y) + 2]
			= param->image->image_data[(param->display->textx * (param->image->depth / 8) + param->display->texty * param->image->size_line) + 2];
		y++;
		i++;
	}
	return (i);
}