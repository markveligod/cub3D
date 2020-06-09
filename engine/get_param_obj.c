#include "../minirt.h"

void	init_check_param_obj(t_object *obj)
{
	if (!(obj->check = malloc(sizeof(t_check))))
		error("Memory could not be allocated in the Check parameter");
	obj->check->display = 0;
	obj->check->ambient = 0;
	obj->check->camera = 0;
	obj->check->light = 0;
	obj->check->sphere = 0;
	obj->check->plane = 0;
	obj->check->square = 0;
	obj->check->cylinder = 0;
	obj->check->triangle = 0;
}

void	check_param_obj(t_object *obj)
{
	if (!(obj->check->display != 1))
		error("The display parameter is omitted or too many parameters are specified");
	if (!(obj->check->ambient) != 1)
		error("The ambient parameter is omitted or too many parameters are specified");
	if (!(obj->check->camera) != 1)
		error("The camera parameter is omitted or too many parameters are specified");
}

void	sort_param_obj(char *line, t_object *obj)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return ;
	if (line[i] == 'R')
		push_param_display(&line[i + 1], obj);
	else if (line[i] == 'A')
		push_param_ambient(&line[i + 1], obj);
	else if (line[i] == 'c')
		push_param_camera(&line[i + 1], obj);
	else if (line[i] == 'l')
		push_param_light(&line[i + 1], obj);
	else if (line[i] == 's' && line[i + 1] == 'p')
		push_param_sphere(&line[i + 2], obj);
	else if (line[i] == 'p' && line[i + 1] == 'l')
		push_param_plane(&line[i + 2], obj);
	else if (line[i] == 's' && line[i + 1] == 'q')
		push_param_square(&line[i + 2], obj);
	else if (line[i] == 'c' && line[i + 1] == 'y')
		push_param_cylinder(&line[i + 2], obj);
	else if (line[i] == 't' && line[i + 1] == 'r')
		push_param_triangle(&line[i + 2], obj);
	else
		error("Unknown scene parameter (O_O) ");
}

void	push_param_obj(int fd, t_object *obj)
{
	int		count;
	char	*line;

	count = 1;
	while (count > 0)
	{
		if ((count = get_next_line(fd, &line)) == (-1))
			error("I can't read the file (-_-) ");
		sort_param_obj(line, obj);
	}
	check_param_obj(obj);
}
