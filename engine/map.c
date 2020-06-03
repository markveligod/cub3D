#include "../cub.h"

int		check_map_char(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ');
}

int		check_size(char *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (check_map_char(str[i]))
			size++;
		i++;
	}
	return (size);
}

char	*get_map_param(char *line)
{
	char	*array;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = check_size(line);
    if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
        error("Something went wrong with Map allocation !(-_-)! ");
    while (line[i])
    {
		if (check_map_char(line[i]))
		{
			array[j] = line[i];
			j++;
		}
        i++;
    }
    array[j] = '$';
    array[size + 1] = '\0';
    return (array);    
}
