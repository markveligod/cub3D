#include "../cub.h"

int		close_game(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int		check_keyboard(int key, t_link *lnk)
{
	if (key == 53)
		close_game();
	else if (key == 13)
		forward(lnk);
	else if (key == 1)
		backward(lnk);
	else if (key == 0)
		left(lnk);
	else if (key == 2)
		right(lnk);
	else if (key == 123)
		rotate(lnk, key);
	else if (key == 124)
		rotate(lnk, key);
	return (0);
}

int     play_game(t_link *lnk)
{
	lnk->img[0]->image_ptr = mlx_new_image(lnk->dis->mlx_ptr, lnk->area->x, lnk->area->y);
	lnk->img[0]->image_data = mlx_get_data_addr(lnk->img[0]->image_ptr, &lnk->img[0]->depth, &lnk->img[0]->size_line, &lnk->img[0]->endian);
	start_draw(lnk);
	mlx_put_image_to_window(lnk->dis->mlx_ptr, lnk->dis->win_ptr, lnk->img[0]->image_ptr, 0, 0);
	return (0);
}

void    start_game(t_link *lnk)
{
	lnk->dis->win_ptr = mlx_new_window(lnk->dis->mlx_ptr, lnk->area->x, lnk->area->y, "Cub3D");
	mlx_hook(lnk->dis->win_ptr, 2, 5, check_keyboard, lnk);
	mlx_hook(lnk->dis->win_ptr, 17, 1, close_game, NULL);
	mlx_loop_hook(lnk->dis->mlx_ptr, play_game, lnk);
	mlx_loop(lnk->dis->mlx_ptr);
}
