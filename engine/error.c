#include "../cub.h"

void	error(char *str)
{
	int fd;

	fd = open("log.txt", O_WRONLY);
	str = ft_strjoin("ERROR: ", str);
	ft_putstr_fd(fd, str);
	ft_putstr_fd(1, "CHECK LOG.TXT (-_-)");
	exit(EXIT_FAILURE);
}