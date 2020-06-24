#include "../../cub.h"

void	init_check_struct(t_ptr *ptr)
{
	if (!(ptr->check = (t_check *)malloc(sizeof(t_check))))
		error("struct check doesn't allocate in memory (*_*)");
	ptr->check->check_r = 0;
	ptr->check->check_no = 0;
	ptr->check->check_so = 0;
	ptr->check->check_we = 0;
	ptr->check->check_ea = 0;
	ptr->check->check_s = 0;
	ptr->check->check_f = 0;
	ptr->check->check_c = 0;
	ptr->check->check_map = 0;
	ptr->check->check_pos_player = 0;
}