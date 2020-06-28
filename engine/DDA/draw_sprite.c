#include "../../cub.h"

static int		check_black(t_ptr *ptr)
{
	return (ptr->img[5]->img_data[ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx * ptr->img[5]->bpp / 8] == 0 &&
	ptr->img[5]->img_data[(ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx * ptr->img[5]->bpp / 8) + 1] == 0 &&
	ptr->img[5]->img_data[(ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx * ptr->img[5]->bpp / 8) + 2] == 0);
}

static void		check_dist_sprite(t_ptr *ptr)
{
	int			i;
	t_sprite	*temp;

	i = 0;
	while (i < ptr->b->nb_sprite)
	{
		ptr->z[i]->s_dist = ((ptr->player->pos_x - ptr->z[i]->x) * (ptr->player->pos_x -
		ptr->z[i]->x) + (ptr->player->pos_y - ptr->z[i]->y) * (ptr->player->pos_y - ptr->z[i]->y));
		i++;
	}
	i = 0;
	while (i < ptr->b->nb_sprite)
	{
		if (ptr->z[i]->s_dist < ptr->z[i + 1]->s_dist && (i + 1) < ptr->b->nb_sprite)
		{
			temp = ptr->z[i];
			ptr->z[i] = ptr->z[i + 1];
			ptr->z[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

static void		check_draw_sprite(t_ptr *ptr)
{
	if (ptr->b->drawstarty < 0)
		ptr->b->drawstarty = 0;
	if (ptr->b->drawendy >= ptr->param->y)
		ptr->b->drawendy = ptr->param->y - 1;
	if (ptr->b->drawstartx < 0)
		ptr->b->drawstartx = 0;
	if (ptr->b->drawendx >= ptr->param->x)
		ptr->b->drawendx = ptr->param->x - 1;
}

static void		put_sprite(t_ptr *ptr)
{
	int y;

	while (ptr->b->stripe < ptr->b->drawendx)
	{
		ptr->b->texx = (int)(256 * (ptr->b->stripe - (- ptr->b->spritewidth / 2 + ptr->b->spritescreenx)) * ptr->img[5]->width / ptr->b->spritewidth) / 256;
		if (ptr->b->transformy > 0 && ptr->b->stripe > 0 && ptr->b->stripe < ptr->param->x && ptr->b->transformy < ptr->b->buffer[ptr->b->stripe])
		{
			y = ptr->b->drawstarty;
			while (y < ptr->b->drawendy)
			{
				ptr->b->d = y * 256 - ptr->param->y * 128 + ptr->b->spriteheight * 128;
				ptr->b->texy = ((ptr->b->d * ptr->img[5]->height) / ptr->b->spriteheight) / 256;
				if (!(check_black(ptr)))
				{
					ptr->img[0]->img_data[ptr->b->stripe * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y] = ptr->img[5]->img_data[ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx * ptr->img[5]->bpp / 8];
					ptr->img[0]->img_data[(ptr->b->stripe * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y) + 1] = ptr->img[5]->img_data[(ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx * ptr->img[5]->bpp / 8) + 1];
					ptr->img[0]->img_data[(ptr->b->stripe * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * y) + 2] = ptr->img[5]->img_data[(ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx * ptr->img[5]->bpp / 8) + 2];
				}
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
	init_sprite_struct(ptr);
	check_dist_sprite(ptr);
	while (i < ptr->b->nb_sprite)
	{
		ptr->b->spritex = ptr->z[i]->x - ptr->player->pos_x;
		ptr->b->spritey = ptr->z[i]->y - ptr->player->pos_y;
		ptr->b->invdet = 1.0 / (ptr->player->plane_x * ptr->player->dir_y - ptr->player->dir_x * ptr->player->plane_y);
		ptr->b->transformx = ptr->b->invdet * (ptr->player->dir_y * ptr->b->spritex - ptr->player->dir_x * ptr->b->spritey);
		ptr->b->transformy = ptr->b->invdet * (-ptr->player->plane_y * ptr->b->spritex + ptr->player->plane_x * ptr->b->spritey);
		ptr->b->spritescreenx = (int)((ptr->param->x / 2) * (1 + ptr->b->transformx / ptr->b->transformy));
		ptr->b->spriteheight = abs((int)(ptr->param->y / ptr->b->transformy));
		ptr->b->drawstarty = -ptr->b->spriteheight / 2 + ptr->param->y / 2;
		ptr->b->drawendy = ptr->b->spriteheight / 2 + ptr->param->y / 2;
		ptr->b->spritewidth = abs((int)(ptr->param->y / ptr->b->transformy));
		ptr->b->drawstartx = -ptr->b->spritewidth / 2 + ptr->b->spritescreenx;
		ptr->b->drawendx = ptr->b->spritewidth / 2 + ptr->b->spritescreenx;
		check_draw_sprite(ptr);
		ptr->b->stripe = ptr->b->drawstartx;
		put_sprite(ptr);
		i++;
	}
}