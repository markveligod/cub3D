#include "../../cub.h"

void	init_check_struct(t_ptr *ptr)
{
	if (!(ptr->check = (t_check *)malloc(sizeof(t_check))))
		error("struct check doesn't allocate in memory (*_*)");
	ptr->check->r = 0;
	ptr->check->no = 0;
	ptr->check->so = 0;
	ptr->check->we = 0;
	ptr->check->ea = 0;
	ptr->check->s = 0;
	ptr->check->f = 0;
	ptr->check->c = 0;
	ptr->check->map = 0;
	ptr->check->pos_player = 0;
}