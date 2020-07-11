#include "../../cub.h"

void		check_param_objects(t_ptr *ptr)
{
	if (ptr->c->r != 1)
		error("Set permission");
	if (ptr->c->no != 1)
		error("Set path north");
	if (ptr->c->so != 1)
		error("Set path south");
	if (ptr->c->we != 1)
		error("Set path west");
	if (ptr->c->ea != 1)
		error("Set path east");
	if (ptr->c->s != 1)
		error("Set path sprite");
	if (ptr->c->f != 1)
		error("Set RGB floor");
	if (ptr->c->c != 1)
		error("Set RGB ceilling");
	if (ptr->c->map != 1)
		error("Set param map");
	if (ptr->c->pos_player != 1)
		error("Set pos player on map");
}
