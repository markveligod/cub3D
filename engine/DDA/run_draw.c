#include "../../cub.h"

int				draw_ceilling(t_ptr *p, int y)
{
	int r;
	int g;
	int b;

	r = p->p->c_rgb % 256;
	g = (p->p->c_rgb / 256) % 256;
	b = ((p->p->c_rgb / 256) / 256) % 256;
	while (y < p->dda->drawstart)
	{
		p->img[0]->img_data
		[p->dda->screenx * p->img[0]->bpp / 8 + p->img[0]->size_line * y] = r;
		p->img[0]->img_data
		[(p->dda->screenx * p->img[0]->bpp / 8 + p->img[0]->size_line * y) +
		1] = g;
		p->img[0]->img_data
		[(p->dda->screenx * p->img[0]->bpp / 8 + p->img[0]->size_line * y) +
		2] = b;
		y++;
	}
	return (y);
}

void			draw_floor(t_ptr *p, int y)
{
	int r;
	int g;
	int b;

	r = p->p->f_rgb % 256;
	g = (p->p->f_rgb / 256) % 256;
	b = ((p->p->f_rgb / 256) / 256) % 256;
	while (y < p->p->y)
	{
		p->img[0]->img_data
		[p->dda->screenx * p->img[0]->bpp / 8 + p->img[0]->size_line * y] = r;
		p->img[0]->img_data
		[(p->dda->screenx * p->img[0]->bpp / 8 + p->img[0]->size_line * y) +
		1] = g;
		p->img[0]->img_data
		[(p->dda->screenx * p->img[0]->bpp / 8 + p->img[0]->size_line * y) +
		2] = b;
		y++;
	}
}

void			set_texture(t_ptr *p)
{
	if (p->dda->side == 1 || p->dda->side == 2)
	{
		p->dda->wallx = p->pl->p_y + p->dda->walldist * p->dda->raydir_y;
		p->dda->wallx -= floor(p->dda->wallx);
		p->dda->textx = (int)(p->dda->wallx * (double)p->img[p->dda->side]->
		width);
		if (p->dda->raydir_x > 0)
			p->dda->textx = p->img[p->dda->side]->width - p->dda->textx - 1;
	}
	else if (p->dda->side == 3 || p->dda->side == 4)
	{
		p->dda->wallx = p->pl->p_x + p->dda->walldist * p->dda->raydir_x;
		p->dda->wallx -= floor(p->dda->wallx);
		p->dda->textx = (int)(p->dda->wallx * (double)p->img[p->dda->side]->
		width);
		if (p->dda->raydir_y < 0)
			p->dda->textx = p->img[p->dda->side]->width - p->dda->textx - 1;
	}
}

int				draw_texture(t_ptr *p, int y)
{
	int i;

	i = 0;
	set_texture(p);
	p->dda->step = 1.0 * p->img[p->dda->side]->height / p->dda->lineheight;
	p->dda->textpos = (p->dda->drawstart - p->p->y / 2 + p->dda->lineheight
	/ 2) * p->dda->step;
	while (y < p->dda->drawend)
	{
		p->dda->texty = (int)p->dda->textpos & (p->img[p->dda->side]->height
		- 1);
		p->dda->textpos += p->dda->step;
		put_pixel_texture(p, y);
		y++;
		i++;
	}
	return (i);
}

void			run_draw(t_ptr *ptr)
{
	int y;

	y = 0;
	ptr->dda->lineheight = (int)(ptr->p->y / ptr->dda->walldist);
	ptr->dda->drawstart = -ptr->dda->lineheight / 2 + ptr->p->y / 2;
	if (ptr->dda->drawstart < 0)
		ptr->dda->drawstart = 0;
	ptr->dda->drawend = ptr->dda->lineheight / 2 + ptr->p->y / 2;
	if (ptr->dda->drawend > ptr->p->y)
		ptr->dda->drawend = ptr->p->y - 1;
	y += draw_ceilling(ptr, y);
	y += draw_texture(ptr, y);
	draw_floor(ptr, y);
}
