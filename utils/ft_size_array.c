int		ft_size_array(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}
