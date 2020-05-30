#include "../cub.h"

char	*ft_strjoin(char *remains, char *buffer)
{
	char *array;
	unsigned int size;
	int i;
	int j;

	if (!remains && !buffer)
		return (NULL);
	size = ft_strlen(remains) + ft_strlen(buffer);
	if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (remains)
	{
		while (remains[i])
		{
			array[j] = remains[i];
			i++;
			j++;
		}
		i = 0;
	}
	while (buffer[i])
	{
		array[j] = buffer[i];
		i++;
		j++;
	}
	array[size] = '\0';
	free((void *)remains);
	return (array);
}