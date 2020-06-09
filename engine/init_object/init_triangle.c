#include "../../minirt.h"

void		triangle_lstadd_back(t_triangle **alst, t_triangle *new)
{
	t_triangle *lst;

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

void		get_point_trinagle(char *line, t_triangle *temp, int check)
{
    int i;

	i = 0;
	temp->pos[check] = ft_atof(line);
	while (line[i] != ',')
		i++;
	temp->pos[check + 1] = ft_atof(&line[i]);
	i++;
	while (line[i] != ',')
		i++;
	temp->pos[check + 2] = ft_atof(&line[i]);
}

void		get_color_triangle(char *line, t_triangle *temp)
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

void		push_param_triangle(char *line, t_object *obj)
{
	int i;
	t_triangle *temp;

	i = 0;
	temp = obj->tr;
	while (temp)
		temp = temp->next;
	if (!(temp = (t_triangle *)malloc(sizeof(t_triangle))))
		error("Memory could not be allocated in the Cylinder parameter");
	temp->next = NULL;
	while (line[i] == ' ')
		i++;
	get_point_trinagle(&line[i], &temp, 0);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	get_point_trinagle(&line[i], &temp, 3);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	get_point_trinagle(&line[i], &temp, 6);
	while (line[i] != ' ')
		i++;
	get_color_triangle(&line[i], &temp);
	triangle_lstadd_back(&obj->tr, temp);
}
