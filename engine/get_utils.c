#include "../minirt.h"

void		get_pos(char *line, double *pos_x, double *pos_y, double *pos_z)
{
	int i;

	i = 0;

	*pos_x = ft_atof(&line[i]);
	i += (check_next_param(',', &line[i], 0) + 1);
	*pos_y = ft_atof(&line[i]);
	i++;
	i += (check_next_param(',', &line[i], 0) + 1);
	*pos_z = ft_atof(&line[i]);
}

void		get_normal(char *line, double *normal_x, double *normal_y, double *normal_z, char *name)
{
	int i;

	i = 0;
	*normal_x = ft_atof(&line[i]);
	check_normal(*normal_x, name);
	i += (check_next_param(',', &line[i], 0) + 1);
	*normal_y = ft_atof(&line[i]);
	check_normal(*normal_y, name);
	i++;
	i += (check_next_param(',', &line[i], 0) + 1);
	*normal_z = ft_atof(&line[i]);
	check_normal(*normal_z, name);
}

void		get_rgb(char *line, int *rgb, char *name)
{
    int i;
	int red;
	int green;
	int blue;

    i = 0;
	red = (short int)ft_atoi(&line[i]);
	check_fail_rgb(red, ft_strjoin(name, " Red"));
	*rgb = red;
	i += (check_next_param(',', &line[i], 0) + 1);
	green = (short int)ft_atoi(&line[i]);
	check_fail_rgb(green, ft_strjoin(name, " Green"));
	*rgb = (*rgb << 8) + green;
	i += (check_next_param(',', &line[i], 0) + 1);
	blue = (short int)ft_atoi(&line[i]);
	check_fail_rgb(blue, ft_strjoin(name, " Blue"));
	*rgb = (*rgb << 8) + blue;
}