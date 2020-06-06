#include "minirt.h"

int			check_filename(char *str, int size)
{
	return (str[size - 1] == 't' && str[size - 2] == 'r' && str[size - 3] == '.');
}

void	init_obj(t_object *obj)
{
	if (!(obj->dis = (t_display *)malloc(sizeof(t_display))))
		error("Memory was not allocated in the display structure");
	if (!(obj->amb = (t_ambient *)malloc(sizeof(t_ambient))))
		error("Memory was not allocated in the ambient structure");
	if (!(obj->cam = (t_camera *)malloc(sizeof(t_camera))))
		error("Memory was not allocated in the camera structure");
	obj->cam->next = NULL;
	if (!(obj->lght = (t_light *)malloc(sizeof(t_light))))
		error("Memory was not allocated in the light structure");
	obj->lght->next = NULL;
}

void		main(int ac, char **av)
{
	t_object	*obj;
	int			fd;

	if (ac == 2)
		if (av[1] && (check_filename(av[1], ft_strlen(av[1]))))
		{
			fd = open(av[1], O_RDONLY);
			init_obj(&obj);
			obj = push_param_obj(fd, &obj);
		}
		else
			error("Unknown format of the scene (*_*)");
	else
		error("Many or few arguments (T_T)");
}