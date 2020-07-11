#include "../../cub.h"

/*
** Function for initializing the parameter structure
*/

void		init_param_objects(t_ptr *ptr)
{
	if (!(ptr->p = (t_paramobj *)malloc(sizeof(t_paramobj))))
		error("struct param doesn't allocate in memory (*_*)");
}
