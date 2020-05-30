static int	check(char ch)
{
	return (ch == ' ' || ch == '\t' || ch == '\v' ||
			ch == '\r' || ch == '\n' || ch == '\f');
}

int			ft_atoi(const char *str)
{
	int i;
	int sing;
	int res;

	i = 0;
	res = 0;
	sing = 1;
	while (check(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sing = ((str[i] == '-') ? -1 : 1);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sing);
}
