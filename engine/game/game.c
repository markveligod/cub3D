#include "../../cub.h"

static int		control_keys(int key)
{
	if (key == 53)
		close_win();
	return (0);
}

static int		play(t_ptr *ptr)
{
	ptr->img[0]->img_ptr = mlx_new_image(ptr->mlx->mlx_ptr, ptr->param->x, ptr->param->y);
	ptr->img[0]->img_data = mlx_get_data_addr(ptr->img[0]->img_ptr, &ptr->img[0]->bpp,
	&ptr->img[0]->size_line, &ptr->img[0]->endian);
	run_dda(ptr);
	mlx_put_image_to_window(ptr->mlx->mlx_ptr, ptr->mlx->win_ptr, ptr->img[0]->img_ptr, 0, 0);
	return (0);
}

void			start_game(t_ptr *ptr)
{
	init_game_struct(ptr);
	init_game_param(ptr);
	init_image_struct(ptr);
	init_dda_struct(ptr);
	ptr->mlx->mlx_ptr = mlx_init();
	ptr->mlx->win_ptr = mlx_new_window(ptr->mlx->mlx_ptr, ptr->param->x, ptr->param->y, "CUB3D GAME");
	mlx_hook(ptr->mlx->win_ptr, 17, 1L<<0, close_win, (void *)0);
	mlx_hook(ptr->mlx->win_ptr, 2, 5, control_keys, ptr);
	mlx_loop_hook(ptr->mlx->mlx_ptr, play, ptr);
	mlx_loop(ptr->mlx->mlx_ptr);
}