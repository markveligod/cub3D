#include "../../minirt.h"

void		cylinder_lstadd_back(t_cylinder **alst, t_cylinder *new)
{
	t_cylinder *lst;

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

void		push_param_cylinder(char *line, t_object *obj)
{
	int i;
	t_cylinder *temp;

	i = 0;
	if (!(temp = (t_cylinder *)malloc(sizeof(t_cylinder))))
		error("Memory could not be allocated in the Cylinder parameter");
	temp->next = NULL;
	i += check_next_param(' ', &line[i], 1);
	get_pos(&line[i], &(temp->pos_x), &(temp->pos_y), &(temp->pos_z));
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	get_normal(&line[i], &(temp->normal_x), &(temp->normal_y), &(temp->normal_z), "Cylinder");
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	temp->diameter = ft_atof(&line[i]);
	if (temp->diameter < 0.0)
		error("The diameter cannot be negative");
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	temp->height = ft_atof(&line[i]);
	if (temp->height < 0.0)
		error("The height cannot be negative");
	i += check_next_param(' ', &line[i], 0);
	get_rgb(&line[i], &(temp->rgb), "Cylinder");
	cylinder_lstadd_back(&obj->cy, temp);
	obj->check->cylinder++;
}
