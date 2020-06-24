#include "../../cub.h"

void		init_param_objects(t_ptr *ptr)
{
	if (!(ptr->param = (t_param *)malloc(sizeof(t_param))))
		error("struct param doesn't allocate in memory (*_*)");
}