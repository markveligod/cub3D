#include "cub.h"

int		check_filename(char *str, int size)
{
	return ((str[size - 4] == '.' && str[size - 3] == 'c' &&
	str[size - 2] == 'u' && str[size - 1] == 'b'));
}



int		main(int ac, char **av)
{
	int		fd;
	t_link	param;

	fd = 0;
	if (ac == 2 && check_filename(av[1], ft_strlen(av[1])))
	{
		fd = open(av[1], O_RDONLY);
		get_init_param(&param);
		get_param_file(fd, &param);
	}
}