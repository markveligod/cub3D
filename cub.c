#include "cub.h"

int		main(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		if (check_filename(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			
		}
		else
			error("File name invalid (^_^)")
	}
	else
		error("Arg more two input or less two input (> <)");
	return (0);
}