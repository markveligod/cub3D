#include "../minirt.h"

void	check_fail_rgb(short int check, char *str)
{
	char *array;

	if (check > 255 || check < 0)
	{
		array = ft_strjoin("", str);
		array = ft_strjoin(array, " colors in range [0-255]");
		error(array);
	}
}

void	check_normal(double check, char *str)
{
	char *array;

	if (check < -1.0 || check > 1.0)
	{
		array = ft_strjoin("", str);
		array = ft_strjoin(array, ": 3d normalized orientation vector. In range [-1,1] (*_*)");
		error(array);
	}
}

int		check_next_param(char ch, char *line, int flag)
{
	int i;

	i = 0;
	if (flag == 1)
		while (line[i] == ch)
			i++;
	if (flag == 0)
		while (line[i] != ch)
			i++;
	return (i);
}
