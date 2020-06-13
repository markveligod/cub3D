#include "../../minirt.h"

void	push_param_ambient(char *line, t_object *obj)
{
	int i;

	i = 0;
	if (!(obj->amb = (t_ambient *)malloc(sizeof(t_ambient))))
		error("Memory could not be allocated in the Ambient parameter");
	i += check_next_param(' ', &line[i], 1);
	obj->amb->coef = ft_atof(&line[i]);
	if (obj->amb->coef < 0.0 || obj->amb->coef > 1.0)
		error("Ambient lighting ratio in range [0.0,1.0] (--_--)");
	i += check_next_param(' ', &line[i], 0);
	get_rgb(&line[i], &(obj->amb->red), &(obj->amb->green), &(obj->amb->blue), "Ambient");
	obj->check->ambient++;
}