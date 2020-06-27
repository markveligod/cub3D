#include "../../cub.h"

static int		draw_ceilling(t_ptr *ptr, int y)
{
	int r;
	int g;
	int b;

	r = ptr->param->c_rgb % 256;
	g = (ptr->param->c_rgb / 256) % 256;
	b = ((ptr->param->c_rgb / 256) / 256) % 256;
	while (y < ptr->dda->drawstart)
	{
		ptr->img[0]->img_data
		[ptr->dda->screenx * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y] = r;
		ptr->img[0]->img_data
		[(ptr->dda->screenx * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y) + 1] = g;
		ptr->img[0]->img_data
		[(ptr->dda->screenx * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y) + 2] = b;
		y++;
	}
	return (y);
}

static void		draw_floor(t_ptr *ptr, int y)
{
	int r;
	int g;
	int b;

	r = ptr->param->f_rgb % 256;
	g = (ptr->param->f_rgb / 256) % 256;
	b = ((ptr->param->f_rgb / 256) / 256) % 256;
	while (y < ptr->param->y)
	{
		ptr->img[0]->img_data
		[ptr->dda->screenx * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y] = r;
		ptr->img[0]->img_data
		[(ptr->dda->screenx * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y) + 1] = g;
		ptr->img[0]->img_data
		[(ptr->dda->screenx * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y) + 2] = b;
		y++;
	}
}

static void		set_texture(t_ptr *ptr)
{
	if (ptr->dda->side == 1 || ptr->dda->side == 2)
	{
		ptr->dda->wallx = ptr->player->pos_y + ptr->dda->walldist * ptr->dda->raydir_y;
		ptr->dda->wallx -= floor(ptr->dda->wallx);
		ptr->dda->textx = (int)(ptr->dda->wallx * (double)ptr->img[ptr->dda->side]->width);
		if (ptr->dda->raydir_x > 0)
			ptr->dda->textx = ptr->img[ptr->dda->side]->width - ptr->dda->textx - 1;
	}
	else if (ptr->dda->side == 3 || ptr->dda->side == 4)
	{
		ptr->dda->wallx = ptr->player->pos_x + ptr->dda->walldist * ptr->dda->raydir_x;
		ptr->dda->wallx -= floor(ptr->dda->wallx);
		ptr->dda->textx = (int)(ptr->dda->wallx * (double)ptr->img[ptr->dda->side]->width);
		if (ptr->dda->raydir_y < 0)
			ptr->dda->textx = ptr->img[ptr->dda->side]->width - ptr->dda->textx - 1;
	}
}

static int		draw_texture(t_ptr *ptr, int y)
{
	int i;

	i = 0;
	set_texture(ptr);
	ptr->dda->step = 1.0 * ptr->img[ptr->dda->side]->height / ptr->dda->lineheight;
	ptr->dda->textpos = (ptr->dda->drawstart - ptr->param->y / 2 + ptr->dda->lineheight / 2) * ptr->dda->step;
	while (y < ptr->dda->drawend)
	{
		ptr->dda->texty = (int)ptr->dda->textpos & (ptr->img[ptr->dda->side]->height * ptr->dda->texty + ptr->dda->textx);
		ptr->dda->textpos += ptr->dda->step;
		ptr->img[0]->img_data[ptr->dda->screenx * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y] =
		ptr->img[ptr->dda->side]->img_data[ptr->dda->textx * (ptr->img[ptr->dda->side]->bpp / 8) + ptr->dda->texty * ptr->img[ptr->dda->side]->size_line];
		ptr->img[0]->img_data[(ptr->dda->screenx * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y) + 1] =
		ptr->img[ptr->dda->side]->img_data[(ptr->dda->textx * (ptr->img[ptr->dda->side]->bpp / 8) + ptr->dda->texty * ptr->img[ptr->dda->side]->size_line) + 1];
				ptr->img[0]->img_data[(ptr->dda->screenx * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y) + 2] =
		ptr->img[ptr->dda->side]->img_data[(ptr->dda->textx * (ptr->img[ptr->dda->side]->bpp / 8) + ptr->dda->texty * ptr->img[ptr->dda->side]->size_line) + 2];
		y++;
		i++;
	}
	return (i);
}

void			run_draw(t_ptr *ptr)
{
	int y;

	y = 0;
	ptr->dda->lineheight = (int)(ptr->param->y / ptr->dda->walldist);
	ptr->dda->drawstart = -ptr->dda->lineheight / 2 + ptr->param->y / 2;
	if (ptr->dda->drawstart < 0)
		ptr->dda->drawstart = 0;
	ptr->dda->drawend = ptr->dda->lineheight/ 2 + ptr->param->y / 2;
	if (ptr->dda->drawend > ptr->param->y)
		ptr->dda->drawend = ptr->param->y - 1;
	y += draw_ceilling(ptr, y);
	y += draw_texture(ptr, y);
	draw_floor(ptr, y);
}