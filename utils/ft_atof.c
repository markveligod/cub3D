double		check_coef(int i)
{
	double coef;

	coef = 0.10;
	while (i > 0)
		coef *= 0.10;
	return (coef);
}

double		check_point(char *str)
{
	double	n;
	double	coef;
	int		i;

	i = 0;
	n = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		coef = check_coef(i);
		n = n + ((str[i] - '0') * coef);
		i++;
	}
	return (n);
}

double		ft_atof(const char *str)
{
	int		i;
	double	n;
	double	sign;

	i = 0;
	n = 0;
	sign = 1.0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1.0;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		n = (n * 10.0) + (str[i] - '0');
		i++;
	}
	return (((str[i] == '.' ? (n + check_point(&str[++i])) : n) * sign));
}
