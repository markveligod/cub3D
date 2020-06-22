#include "minirt.h"

int			check_filename(char *str, int size)
{
	return (str[size - 1] == 't' && str[size - 2] == 'r' && str[size - 3] == '.');
}

int			main(int ac, char **av)
{
	t_object	obj;
	int			fd;

	if (ac == 2)
		if (av[1] && (check_filename(av[1], ft_strlen(av[1]))))
		{
			fd = open(av[1], O_RDONLY);
			init_check_param_obj(&obj);
			push_param_obj(fd, &obj);
			init_mlx_param_obj(&obj);
			obj.rt->mlx_ptr = mlx_init();
			start_rt(&obj);
			// test arg struct's
			/*
			printf("\nCHECK STRUCT: \ndisplay - %d\nambient - %d\ncamera - %d\nlight - %d\nsphere - %d\nplane - %d\nsquare - %d\ncylinder - %d\ntriangle - %d", obj.check->display, obj.check->ambient, obj.check->camera, obj.check->light, obj.check->sphere, obj.check->plane, obj.check->square, obj.check->cylinder, obj.check->triangle);
			printf("\n\nDISPLAY STRUCT: \nDisplay - x: %d y: %d\n", obj.dis->x, obj.dis->y);
			printf("\n\nAMBIENT STRUCT: \ncoef: %f\nred: %d\ngreen: %d\nblue: %d\n", obj.amb->coef, obj.amb->red, obj.amb->green, obj.amb->blue);
			printf("\n\nCAMERA STRUCT: \npos_x: %f\npos_y: %f\npos_z: %f\nnormal_x: %f\nnormal_y: %f\nnormal_z: %f\n FOV: %d\n", obj.cam->pos_x, obj.cam->pos_y, obj.cam->pos_z, obj.cam->normal_x, obj.cam->normal_y, obj.cam->normal_z, obj.cam->fov);
			printf("\n\nLIGHT STRUCT 1: \npos_x: %f\npos_y: %f\npos_z: %f\nbrightness: %f\nred: %d\ngreen: %d\nblue: %d\n", obj.lght->pos_x, obj.lght->pos_y, obj.lght->pos_z, obj.lght->brightness, obj.lght->red, obj.lght->green, obj.lght->blue);
			printf("\n\nLIGHT STRUCT 2: \npos_x: %f\npos_y: %f\npos_z: %f\nbrightness: %f\nred: %d\ngreen: %d\nblue: %d\n", obj.lght->next->pos_x, obj.lght->next->pos_y, obj.lght->next->pos_z, obj.lght->next->brightness, obj.lght->next->red, obj.lght->next->green, obj.lght->next->blue);
			printf("\n\nSPHERE STRUCT 1: \npos_x: %f\npos_y: %f\npos_z: %f\ndiameter: %f\nred: %d\ngreen: %d\nblue: %d\n", obj.sp->pos_x, obj.sp->pos_y, obj.sp->pos_z, obj.sp->diameter, obj.sp->red, obj.sp->green, obj.sp->blue);
			printf("\n\nSPHERE STRUCT 2: \npos_x: %f\npos_y: %f\npos_z: %f\ndiameter: %f\nred: %d\ngreen: %d\nblue: %d\n", obj.sp->next->pos_x, obj.sp->next->pos_y, obj.sp->next->pos_z, obj.sp->next->diameter, obj.sp->next->red, obj.sp->next->green, obj.sp->next->blue);
			*/
		}
		else
			error("Unknown format of the scene (*_*)");
	else
		error("Many or few arguments (T_T)");
	return (0);
}
