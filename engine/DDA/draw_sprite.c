#include "../../cub.h"

void			put_pixel(t_ptr *ptr, int y)
{
	ptr->img[0]->img_data[ptr->b->stripe * ptr->img[0]->bpp / 8 +
	ptr->img[0]->size_line * y] = ptr->img[5]->img_data[ptr->img[5]->size_line
	* ptr->b->texy + ptr->b->texx * ptr->img[5]->bpp / 8];
	ptr->img[0]->img_data[(ptr->b->stripe * ptr->img[0]->bpp / 8 +
	ptr->img[0]->size_line * y) + 1] = ptr->img[5]->img_data
	[(ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx *
	ptr->img[5]->bpp / 8) + 1];
	ptr->img[0]->img_data[(ptr->b->stripe * ptr->img[0]->bpp / 8 +
	ptr->img[0]->size_line * y) + 2] = ptr->img[5]->img_data
	[(ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx *
	ptr->img[5]->bpp / 8) + 2];
}

void			put_sprite(t_ptr *ptr)
{
	int y;

	while (ptr->b->stripe < ptr->b->drawendx)
	{
		ptr->b->texx = (int)(256 * (ptr->b->stripe - (-ptr->b->spritewidth
		/ 2 + ptr->b->spritescreenx)) * ptr->img[5]->width /
		ptr->b->spritewidth) / 256;
		if (ptr->b->transformy > 0 && ptr->b->stripe > 0 && ptr->b->stripe <
		ptr->p->x && ptr->b->transformy < ptr->b->buffer[ptr->b->stripe])
		{
			y = ptr->b->drawstarty;
			while (y < ptr->b->drawendy)
			{
				ptr->b->d = y * 256 - ptr->p->y * 128 + ptr->b->spriteheight
				* 128;
				ptr->b->texy = ((ptr->b->d * ptr->img[5]->height) /
				ptr->b->spriteheight) / 256;
				if (!(check_black(ptr)))
					put_pixel(ptr, y);
				y++;
			}
		}
		ptr->b->stripe++;
	}
}

void			draw_sprite(t_ptr *ptr)
{
	int i;

	i = 0;
	check_dist_sprite(ptr);
	while (i < ptr->b->nb_sprite)
	{
		ptr->b->spritex = ptr->z[i]->x - ptr->pl->p_x + 0.5;
		ptr->b->spritey = ptr->z[i]->y - ptr->pl->p_y + 0.5;
		ptr->b->invdet = 1.0 / (ptr->pl->pl_x * ptr->pl->d_y -
		ptr->pl->d_x * ptr->pl->pl_y);
		ptr->b->transformx = ptr->b->invdet * (ptr->pl->d_y *
		ptr->b->spritex - ptr->pl->d_x * ptr->b->spritey);
		ptr->b->transformy = ptr->b->invdet * (-ptr->pl->pl_y *
		ptr->b->spritex + ptr->pl->pl_x * ptr->b->spritey);
		ptr->b->spritescreenx = (int)((ptr->p->x / 2) * (1 +
		ptr->b->transformx / ptr->b->transformy));
		ptr->b->spriteheight = abs((int)(ptr->p->y / ptr->b->transformy));
		ptr->b->drawstarty = -ptr->b->spriteheight / 2 + ptr->p->y / 2;
		ptr->b->drawendy = ptr->b->spriteheight / 2 + ptr->p->y / 2;
		check_draw_sprite(ptr);
		ptr->b->stripe = ptr->b->drawstartx;
		put_sprite(ptr);
		i++;
	}
}
