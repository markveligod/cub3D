#include "../../cub.h"

static int		control_keys(int key)
{
	if (key == 53)
		close_win();
	return (0);
}

void			start_game(t_ptr *ptr)
{
	init_game_struct(ptr);
	init_game_param(ptr);
	ptr->mlx->mlx_ptr = mlx_init();
	ptr->mlx->win_ptr = mlx_new_window(ptr->mlx->mlx_ptr, ptr->param->x, ptr->param->y, "CUB3D GAME");
	mlx_hook(ptr->mlx->win_ptr, 17, 1L<<0, close_win, (void *)0);
	mlx_hook(ptr->mlx->win_ptr, 2, 5, control_keys, ptr);
	mlx_loop(ptr->mlx->mlx_ptr);
}