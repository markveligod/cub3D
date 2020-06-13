#include "../../minirt.h"

void		square_lstadd_back(t_square **alst, t_square *new)
{
	t_square *lst;

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

void		push_param_square(char *line, t_object *obj)
{
	int i;
	t_square *temp;

	i = 0;
	temp = obj->sq;
	while (temp)
		temp = temp->next;
	if (!(temp = (t_square *)malloc(sizeof(t_square))))
		error("Memory could not be allocated in the Square parameter");
	temp->next = NULL;
	i += check_next_param(' ', &line[i], 1);
	get_pos(&line[i], &(temp->pos_x), &(temp->pos_y), &(temp->pos_z));
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	get_normal(&line[i], &(temp->normal_x), &(temp->normal_y), &(temp->normal_z), "Square");
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	temp->size = ft_atof(&line[i]);
	if (temp->size < 0.0)
		error("The size cannot be negative");
	i += check_next_param(' ', &line[i], 0);
	get_rgb(&line[i], &(temp->red), &(temp->green), &(temp->blue), "Square");
	square_lstadd_back(&obj->sq, temp);
	obj->check->square++;
}
