#include "../cub.h"

int		close_game(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
/*
int		key_management(int key, t_link *param)
{
	if (key == 53)
		close_game();
	else if (key == 13)
		forward(param);
	else if (key == 1)
		backward(param);
	else if (key == 0)
		left(param);
	else if (key == 2)
		right(param);
	else if (key == 123)
		rotate(param, key);
	else if (key == 124)
		rotate(param, key);
	return (0);
}
*/
int     play_game(t_link *param)
{
	return (0);
}

void    start_game(t_link *param)
{
	param->display->win_ptr = mlx_new_window(param->display->mlx_ptr, param->area->x, param->area->y, "Cub3D");
//	mlx_hook(param->display->win_ptr, 2, 5, key_management, param);
//	mlx_hook(param->display->win_ptr, 17, 1, close_game, NULL);
//	mlx_loop_hook(param->display->mlx_ptr, play_game, param);
	mlx_loop(param->display->mlx_ptr);
}
