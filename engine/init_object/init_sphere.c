#include "../../minirt.h"

void		sphere_lstadd_back(t_sphere **alst, t_sphere *new)
{
	t_sphere *lst;

	if (!new)
		return ;
	if (!alst || !*alst)
		*alst = new;
	else
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

void		get_pos_sphere(char *line, t_sphere *temp)
{
	int i;

	i = 0;
	temp->pos[0] = ft_atof(line);
	while (line[i] != ',')
		i++;
	temp->pos[1] = ft_atof(&line[i]);
	i++;
	while (line[i] != ',')
		i++;
	temp->pos[2] = ft_atof(&line[i]);
}

void		get_color_sphere(char *line, t_sphere *temp)
{
	int i;

	i = 0;
	temp->rgb[0] = ft_atoi(line[i]);
	if (temp->rgb[0] > 255 || temp->rgb[0] < 0)
		error("Red colors in range [0-255]");
	while (line[i] != ',')
		i++;
	temp->rgb[1] = ft_atoi(&line[i]);
	if (temp->rgb[1] > 255 || temp->rgb[1] < 0)
		error("Green colors in range [0-255]");
	while (line[i] != ',')
		i++;
	temp->rgb[2] = ft_atoi(&line[i]);
	if (temp->rgb[2] > 255 || temp->rgb[2] < 0)
		error("Blue colors in range [0-255]");
}

void		push_param_sphere(char *line, t_object *obj)
{
	int i;
	t_sphere *temp;

	i = 0;
	temp = obj->sp;
	while (temp)
		temp = temp->next;
	if (!(temp = (t_light *)malloc(sizeof(t_light))))
		error("Memory could not be allocated in the Sphere parameter");
	temp->next = NULL;
	while (line[i] == ' ')
		i++;
	get_pos_sphere(&line[i], &temp);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	temp->diameter = ft_atof(&line[i]);
	if (temp->diameter < 0.0)
		error("The diameter cannot be negative");
	while (line[i] != ' ')
		i++;
	get_color_sphere(&line[i], &temp);
	sphere_lstadd_back(&obj->sp, temp);
}