#include "../minirt.h"

void	error(char *str)
{
	int fd;

	fd = open("log.txt", O_CREAT | O_WRONLY );
	ft_putstr_fd("ERROR: ", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("Check log.txt", 1);
	exit(EXIT_FAILURE);
}