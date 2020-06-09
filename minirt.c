#include "minirt.h"

int			check_filename(char *str, int size)
{
	return (str[size - 1] == 't' && str[size - 2] == 'r' && str[size - 3] == '.');
}

void		main(int ac, char **av)
{
	t_object	obj;
	int			fd;

	if (ac == 2)
		if (av[1] && (check_filename(av[1], ft_strlen(av[1]))))
		{
			fd = open(av[1], O_RDONLY);
			init_check_param_obj(&obj);
			push_param_obj(fd, &obj);
			printf ("Display - %d\n", obj.check->display);
		}
		else
			error("Unknown format of the scene (*_*)");
	else
		error("Many or few arguments (T_T)");
}