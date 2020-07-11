int		ft_array_max_value(char **arr)
{
	int res;
	int temp;
	int i;
	int j;

	i = 0;
	temp = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
			j++;
		if (j > temp)
		{
			temp = j;
			res = i;
		}
		i++;
	}
	return (res);
}
