#include "../../cub.h"

void		put_pixel_texture(t_ptr *p, int y)
{
	p->img[0]->img_data[p->dda->screenx * p->img[0]->bpp / 8 + p->img[0]->
	size_line * y] = p->img[p->dda->side]->img_data[p->dda->textx * (p->img
	[p->dda->side]->bpp / 8) + p->dda->texty * p->img[p->dda->side]->size_line];
	p->img[0]->img_data[(p->dda->screenx * p->img[0]->bpp / 8 + p->img[0]->
	size_line * y) + 1] = p->img[p->dda->side]->img_data[(p->dda->textx *
	(p->img[p->dda->side]->bpp / 8) + p->dda->texty * p->img
	[p->dda->side]->size_line) + 1];
	p->img[0]->img_data[(p->dda->screenx * p->img[0]->bpp / 8 + p->img[0]->
	size_line * y) + 2] = p->img[p->dda->side]->img_data[(p->dda->textx *
	(p->img[p->dda->side]->bpp / 8) + p->dda->texty * p->img[p->dda->side]->
	size_line) + 2];
}

void		init_dda_struct(t_ptr *ptr)
{
	if (!(ptr->dda = (t_dda *)malloc(sizeof(t_dda))))
		error("struct dda doesn't allocate in memory (*_*)");
}
