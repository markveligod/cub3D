#include "../../cub.h"

/*
** Function that records the coordinates of sprites
*/

static void		push_sprite(t_ptr *ptr)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (ptr->p->split_map[x])
	{
		y = 0;
		while (ptr->p->split_map[x][y])
		{
			if (ptr->p->split_map[x][y] == '2')
			{
				ptr->z[i]->x = x;
				ptr->z[i]->y = y;
				i++;
			}
			y++;
		}
		x++;
	}
}

/*
** Checking the number of sprites on the map
*/

static void		check_nb_sprite(t_ptr *ptr)
{
	int x;
	int y;

	x = 0;
	ptr->b->nb_sprite = 0;
	while (ptr->p->split_map[x])
	{
		y = 0;
		while (ptr->p->split_map[x][y])
		{
			if (ptr->p->split_map[x][y] == '2')
				ptr->b->nb_sprite++;
			y++;
		}
		x++;
	}
}

/*
** Function for initializing the sprite structure
*/

void			init_sprite_struct(t_ptr *ptr)
{
	int	x;

	x = 0;
	check_nb_sprite(ptr);
	if (!(ptr->z = malloc(sizeof(t_sprite *) * (ptr->b->nb_sprite + 1))))
		error("Something went wrong with sprite initialization");
	ft_bzero(ptr->z, sizeof(t_sprite *) * (ptr->b->nb_sprite + 1));
	while (x <= ptr->b->nb_sprite)
	{
		if (!(ptr->z[x] = malloc(sizeof(t_sprite))))
			error("Something went wrong with sprite initialization - 2");
		ft_bzero(ptr->z[x++], sizeof(t_sprite));
	}
	push_sprite(ptr);
}
