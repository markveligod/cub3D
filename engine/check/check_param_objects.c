#include "../../cub.h"

void		check_param_objects(t_ptr *ptr)
{
	if (ptr->check->r != 1)
		error("Set permission");
	if (ptr->check->no != 1)
		error("Set path north");
	if (ptr->check->so != 1)
		error("Set path south");
	if (ptr->check->we != 1)
		error("Set path west");
	if (ptr->check->ea != 1)
		error("Set path east");
	if (ptr->check->s != 1)
		error("Set path sprite");
	if (ptr->check->f != 1)
		error("Set RGB floor");	
	if (ptr->check->c != 1)
		error("Set RGB ceilling");
	if (ptr->check->map != 1)
		error("Set param map"); 
	if (ptr->check->pos_player != 1)
		error("Set pos player on map");
}