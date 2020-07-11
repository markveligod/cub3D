#include "../../cub.h"

int		check_filename(char *filename)
{
	int size;

	size = ft_strlen(filename);
	if (filename[size - 1] == 'b' && filename[size - 2] == 'u' &&
	filename[size - 3] == 'c' && filename[size - 4] == '.')
		return (1);
	return (0);
}
