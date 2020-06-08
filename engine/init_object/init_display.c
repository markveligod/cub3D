#include "../../minirt.h"

void    push_param_display(char *line, t_object *obj)
{
	int i;

	i = 0;
	if (!(obj->dis = (t_display *)malloc(sizeof(t_display))))
		error("Memory could not be allocated in the Display parameter");
	while (line[i] == ' ')
		i++;
	obj->dis->x = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	obj->dis->y = ft_atoi(&line[i]);
	obj->check->display++;
}