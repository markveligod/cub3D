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

static int		draw_texture(t_ptr *ptr, int y)
{
	int r;
	int g;
	int b;

	r = 255;
	g = 0;
	b = 0;
	while (y < ptr->dda->drawend)
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
	printf("%d , %d \n", ptr->dda->drawstart, ptr->dda->drawend);
	y += draw_ceilling(ptr, y);
	y += draw_texture(ptr, y);
	draw_floor(ptr, y);
}