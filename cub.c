#include "cub.h"

int		main(int ac, char **av)
{
	int		fd;
	t_ptr	ptr;

	if (ac == 2)
	{
		if (check_filename(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			init_check_struct(&ptr);
			get_param_objects(fd ,&ptr);
		}
		else
			error("File name invalid (^_^)");
	}
	else
		error("Arg more two input or less two input (> <)");
	return (0);
}