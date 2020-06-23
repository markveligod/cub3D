#include "../../minirt.h"

int			key_management(int key)
{
	if (key == KEY_ESC)
		close_win();
	return (0);
}

void		canvas_to_viewport(t_object *obj, int x, int y)
{
	// формула v_x = Cw/2 + x; v_y = Ch/2 - y; v_z = d - расстояние до плоскости проекции;
	// нормаль 0 0 0 если нет то нужно переписать для виюпорта расстояние
	obj->view->v_x = obj->dis->x/2 + x;
	obj->view->v_y = obj->dis->y/2 - y;
	obj->view->v_z = 1;
}

int			run_rt(t_object *obj)
{
	int i;
	int j;
	int color;

	obj->rt->img_ptr = mlx_new_image(obj->rt->mlx_ptr, obj->dis->x, obj->dis->y);
	obj->rt->img_data = mlx_get_data_addr(obj->rt->img_ptr, &obj->rt->bpp, &obj->rt->line_length, &obj->rt->endian);
	i = (-1) * (obj->dis->x / 2);
	while (i < (obj->dis->x / 2))
	{
		j = (-1) * (obj->dis->y / 2);
		while (j < (obj->dis->y / 2))
		{
			canvas_to_viewport(obj, i, j);
			color = rt_sphere(obj, 1);
			mlx_pixel_put(obj->rt->mlx_ptr, obj->rt->win_ptr, obj->view->v_x, obj->view->v_y, color);
			j++;
		}
		i++;
	}
	return (0);
}

void		start_rt(t_object *obj)
{
	obj->rt->win_ptr = mlx_new_window(obj->rt->mlx_ptr, obj->dis->x, obj->dis->y, "miniRT");
	mlx_hook(obj->rt->win_ptr, 2, (1L<<5), key_management, (void *)0);
	mlx_loop_hook(obj->rt->mlx_ptr, run_rt, obj);
	mlx_loop(obj->rt->mlx_ptr);
}