#include "../cub.h"

char	*push_line(char *remains)
{
	int i;
	char *array;

	i = 0;
	if (remains[0] == '\n')
		return (ft_strdup(""));
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!(array = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		array[i] = remains[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*cut_next_line(char *remains)
{
	int i;
	int j;
	char *array;

	i = 0;
	j = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	if (!(array = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + ((i == 0) ? 0 : 1)))))
		return (NULL);
	i++;
	while (remains[i])
	{
		array[j] = remains[i];
		i++;
		j++;
	}
	array[j] = '\0';
	free(remains);
	return (array);
}

int		check_remains(char *remains)
{
	int	i;

	i = -1;
	if (!remains)
		return (0);
	while (remains[++i])
		if (remains[i] == '\n')
			return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			*buffer;
	static char		*remains;
	int				count;

	count = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!check_remains(remains) && count != 0)
	{
		if ((count = read(fd, buffer, BUFFER_SIZE)) == (-1))
		{
			free(buffer);
			return (-1);
		}
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	free(buffer);
	*line = push_line(remains);
	remains = cut_next_line(remains);
	return((count == 0) ? 0 : 1);
}
