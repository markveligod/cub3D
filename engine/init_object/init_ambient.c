#include "../../minirt.h"

void	push_param_ambient(char *line, t_object *obj)
{
	int i;

	i = 0;
	if (!(obj->amb = (t_ambient *)malloc(sizeof(t_ambient))))
		error("Memory could not be allocated in the Ambient parameter");
	while (line[i] == ' ')
		i++;
	obj->amb->coef = ft_atof(&line[i]);
	while (line[i] != ' ')
		i++;
	obj->amb->rgb[0] = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	obj->amb->rgb[1] = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	obj->amb->rgb[2] = ft_atoi(&line[i]);
	obj->check->ambient++;
}