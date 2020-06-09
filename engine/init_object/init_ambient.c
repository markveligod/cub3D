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
	if (obj->amb->coef < 0.0 || obj->amb->coef > 1.0)
		error("Ambient lighting ratio in range [0.0,1.0] (--_--)");
	while (line[i] != ' ')
		i++;
	obj->amb->rgb[0] = ft_atoi(&line[i]);
		printf("%s\n", line);
	if (obj->amb->rgb[0] > 255 || obj->amb->rgb[0] < 0)
		error("Red colors in range [0-255]");
	while (line[i] != ',')
		i++;
	obj->amb->rgb[1] = ft_atoi(&line[i]);
	if (obj->amb->rgb[1] > 255 || obj->amb->rgb[1] < 0)
		error("Green colors in range [0-255]");
	while (line[i] != ',')
		i++;
	obj->amb->rgb[2] = ft_atoi(&line[i]);
	if (obj->amb->rgb[2] > 255 || obj->amb->rgb[2] < 0)
		error("Blue colors in range [0-255]");
	obj->check->ambient++;
}