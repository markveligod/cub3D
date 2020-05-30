#include "../cub.h"

void	error(char *str)
{
	int fd;

	fd = open("log.txt", O_WRONLY);
    ft_putstr_fd("ERROR: ", fd);
	ft_putendl_fd(str, fd);
	close(fd);
	exit(EXIT_FAILURE);
}