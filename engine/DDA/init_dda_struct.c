#include "../../cub.h"

void		init_dda_struct(t_ptr *ptr)
{
	if (!(ptr->dda = (t_dda *)malloc(sizeof(t_dda))))
		error("struct dda doesn't allocate in memory (*_*)");
}