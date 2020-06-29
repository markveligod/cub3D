#include "../cub.h"

/*
** Failure exit
*/
void	error(char *str)
{
	int fd;

	fd = open("log.txt", O_WRONLY);
	str = ft_strjoin("Error\n", str);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("CHECK LOG.TXT (-_-)\n", 1);
	exit(EXIT_FAILURE);
}

/*
** Success exit
*/
int		close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}