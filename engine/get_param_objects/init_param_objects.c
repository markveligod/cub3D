#include "../../cub.h"

void		init_param_objects(t_ptr *ptr)
{
	if (!(ptr->param = (t_paramobj *)malloc(sizeof(t_paramobj))))
		error("struct param doesn't allocate in memory (*_*)");
}