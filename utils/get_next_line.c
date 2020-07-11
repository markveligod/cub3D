#include "../cub.h"

int		check_line_break(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*push_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*cut_next_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (0);
	}
	if (!(str = malloc(sizeof(char) * (ft_strlen(line) - i + 1))))
		return (0);
	i++;
	while (line[i])
	{
		str[j] = line[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(line);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*remains;
	int			count;

	count = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!check_line_break(remains) && count != 0)
	{
		if ((count = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	free(buffer);
	*line = push_line(remains);
	remains = cut_next_line(remains);
	return (count == 0 ? 0 : 1);
}
