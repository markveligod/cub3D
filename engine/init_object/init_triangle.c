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

void		push_param_triangle(char *line, t_object *obj)
{
	int i;
	t_triangle *temp;

	i = 0;
	if (!(temp = (t_triangle *)malloc(sizeof(t_triangle))))
		error("Memory could not be allocated in the Cylinder parameter");
	temp->next = NULL;
	i += check_next_param(' ', &line[i], 1);
	get_pos(&line[i], &(temp->pos_x_dot1), &(temp->pos_x_dot2), &(temp->pos_x_dot3));
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	get_pos(&line[i], &(temp->pos_y_dot1), &(temp->pos_y_dot2), &(temp->pos_y_dot3));
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	get_pos(&line[i], &(temp->pos_z_dot1), &(temp->pos_z_dot2), &(temp->pos_z_dot3));
	i += check_next_param(' ', &line[i], 0);
	get_rgb(&line[i], &(temp->rgb), "Triangle");
	triangle_lstadd_back(&obj->tr, temp);
	obj->check->triangle++;
}
