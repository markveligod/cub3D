#include "../../minirt.h"

int		key_management(int key)
{
	if (key == KEY_ESC)
		close_win();
}

void		start_rt(t_object *obj)
{
	obj->rt->win_ptr = mlx_new_window(obj->rt->mlx_ptr, obj->dis->x, obj->dis->y, "miniRT");
	mlx_hook(obj->rt->win_ptr, 2, (1L<<5), key_management, (void *)0);
	mlx_loop(obj->rt->mlx_ptr);
}