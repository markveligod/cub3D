#include "../cub.h"

/*
** Failure exit
*/

void	error(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
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
