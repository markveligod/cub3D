#include "../../cub.h"

/*
** Checking the sprite background for black
*/

int			check_black(t_ptr *ptr)
{
	return (ptr->img[5]->img_data[ptr->img[5]->size_line * ptr->b->texy +
	ptr->b->texx * ptr->img[5]->bpp / 8] == 0 && ptr->img[5]->img_data
	[(ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx *
	ptr->img[5]->bpp / 8) + 1] == 0 && ptr->img[5]->img_data
	[(ptr->img[5]->size_line * ptr->b->texy + ptr->b->texx *
	ptr->img[5]->bpp / 8) + 2] == 0);
}

/*
** Checking the distance from the sprite to the player
*/

void		check_dist_sprite(t_ptr *ptr)
{
	int			i;
	t_sprite	*temp;

	i = 0;
	while (i < ptr->b->nb_sprite)
	{
		ptr->z[i]->s_dist = ((ptr->pl->p_x - ptr->z[i]->x) * (ptr->pl->p_x -
		ptr->z[i]->x) + (ptr->pl->p_y - ptr->z[i]->y) * (ptr->pl->p_y -
		ptr->z[i]->y));
		i++;
	}
	i = 0;
	while (i < ptr->b->nb_sprite)
	{
		if (ptr->z[i]->s_dist < ptr->z[i + 1]->s_dist && (i + 1) <
		ptr->b->nb_sprite)
		{
			temp = ptr->z[i];
			ptr->z[i] = ptr->z[i + 1];
			ptr->z[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

/*
** Parameter limitation on the size of FOV
*/

void		check_draw_sprite(t_ptr *ptr)
{
	ptr->b->spritewidth = abs((int)(ptr->p->y / ptr->b->transformy));
	ptr->b->drawstartx = -ptr->b->spritewidth / 2 + ptr->b->spritescreenx;
	ptr->b->drawendx = ptr->b->spritewidth / 2 + ptr->b->spritescreenx;
	if (ptr->b->drawstarty < 0)
		ptr->b->drawstarty = 0;
	if (ptr->b->drawendy >= ptr->p->y)
		ptr->b->drawendy = ptr->p->y - 1;
	if (ptr->b->drawstartx < 0)
		ptr->b->drawstartx = 0;
	if (ptr->b->drawendx >= ptr->p->x)
		ptr->b->drawendx = ptr->p->x - 1;
}
