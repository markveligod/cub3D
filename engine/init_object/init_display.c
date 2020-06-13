#include "../../minirt.h"

void	push_param_display(char *line, t_object *obj)
{
	int i;

	i = 0;
	if (!(obj->dis = (t_display *)malloc(sizeof(t_display))))
		error("Memory could not be allocated in the Display parameter");
	i += check_next_param(' ', &line[i], 1);
	obj->dis->x = ft_atoi(&line[i]);
	if (obj->dis->x > 1920)
		obj->dis->x = 1920;
	if (obj->dis->x <= 0)
		error("Invalid Display parameter X");
	i += check_next_param(' ', &line[i], 0);
	obj->dis->y = ft_atoi(&line[i]);
	if (obj->dis->y > 1080)
		obj->dis->y = 1080;
	if (obj->dis->y <= 0)
		error("Invalid Display parameter Y");
	obj->check->display++;
}