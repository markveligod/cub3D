#include "../../minirt.h"

void		plane_lstadd_back(t_plane **alst, t_plane *new)
{
	t_plane *lst;

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

void		push_param_plane(char *line, t_object *obj)
{
	int		i;
	t_plane	*temp;

	i = 0;
	temp = obj->pl;
	while (temp)
		temp = temp->next;
	if (!(temp = (t_plane *)malloc(sizeof(t_plane))))
		error("Memory could not be allocated in the Plane parameter");
	temp->next = NULL;
	i += check_next_param(' ', &line[i], 1);
	get_pos(&line[i], &(temp->pos_x), &(temp->pos_y), &(temp->pos_z));
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	get_normal(&line[i], &(temp->normal_x), &(temp->normal_y), &(temp->normal_z), "Plane");
	i += check_next_param(' ', &line[i], 0);
	get_rgb(&line[i], &(temp->red), &(temp->green), &(temp->blue), "Plane");
	plane_lstadd_back(&obj->pl, temp);
	obj->check->plane++;
}
