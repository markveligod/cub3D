#include "../../cub.h"

void			check_space_map(char **arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == ' ')
				error("Space input map");
			j++;
		}
		i++;
	}
}

char			**transform_space_map(char **arr)
{
	char	**new_arr;
	int		size_vert;
	int		i;

	size_vert = ft_size_array(arr);
	if (!(new_arr = (char **)malloc(sizeof(char *) * (size_vert + 1))))
		return (NULL);
	i = 0;
	while (arr[i])
	{
		new_arr[i] = ft_strtrim(arr[i], " ");
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}

static char		**check_new(char **new)
{
	int i;
	int j;

	i = 0;
	while (new[i])
	{
		j = 0;
		while (new[i][j])
		{
			if (new[i][j] != ' ' && !(new[i][j] >= '0' && new[i][j] <= '2')
			&& new[i][j] != 'N' && new[i][j] != 'S' && new[i][j] != 'E' &&
			new[i][j] != 'W' && new[i][j] != '\t')
				new[i][j] = ' ';
			j++;
		}
		new[i][j] = '\0';
		i++;
	}
	return (new);
}

static char		**push_param_map(char **new, char **arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			new[j][i] = arr[i][j];
			j++;
		}
		i++;
	}
	return (check_new(new));
}

char			**transform_split_map(char **arr)
{
	int		i;
	int		size_vert;
	int		size_gorz;
	char	**new_arr;

	size_gorz = ft_size_array(arr);
	size_vert = ft_strlen(arr[ft_array_max_value(arr)]);
	if (!(new_arr = (char **)malloc(sizeof(char *) * (size_vert + 1))))
		return (NULL);
	i = 0;
	while (i < size_vert)
	{
		if (!(new_arr[i] = (char *)malloc(sizeof(char) * (size_gorz))))
		{
			while (new_arr[--i])
				free(new_arr[i]);
			free(new_arr);
		}
		i++;
	}
	new_arr[size_vert] = NULL;
	return (push_param_map(new_arr, arr));
}
