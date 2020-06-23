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

void		push_param_sphere(char *line, t_object *obj)
{
	int i;
	t_sphere *temp;

	i = 0;
	if (!(temp = (t_sphere *)malloc(sizeof(t_sphere))))
		error("Memory could not be allocated in the Sphere parameter");
	temp->next = NULL;
	i += check_next_param(' ', &line[i], 1);
	get_pos(&line[i], &(temp->pos_x), &(temp->pos_y), &(temp->pos_z));
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	temp->diameter = ft_atof(&line[i]);
	if (temp->diameter < 0.0)
		error("The diameter cannot be negative");
	i += check_next_param(' ', &line[i], 0);
	get_rgb(&line[i], &(temp->rgb), "Sphere");
	sphere_lstadd_back(&obj->sp, temp);
	obj->check->sphere++;
}