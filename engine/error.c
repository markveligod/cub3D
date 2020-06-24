#include "../cub.h"

void	error(char *str)
{
	int fd;

	fd = open("log.txt", O_WRONLY);
	str = ft_strjoin("ERROR: ", str);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("CHECK LOG.TXT (-_-)", 1);
	exit(EXIT_FAILURE);
}

int		close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}