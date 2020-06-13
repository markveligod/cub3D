#include "../../minirt.h"

void		light_lstadd_back(t_light **alst, t_light *new)
{
	t_light *lst;

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

void		push_param_light(char *line, t_object *obj)
{
	int i;
	t_light *temp;

	i = 0;
	temp = obj->lght;
	while (temp)
		temp = temp->next;
	if (!(temp = (t_light *)malloc(sizeof(t_light))))
		error("Memory could not be allocated in the Light parameter");
	temp->next = NULL;
	i += check_next_param(' ', &line[i], 1);
	get_pos(&line[i], &(temp->pos_x), &(temp->pos_y), &(temp->pos_z));
	i += check_next_param(' ', &line[i], 0);
	i += check_next_param(' ', &line[i], 1);
	temp->brightness = ft_atof(&line[i]);
	if (temp->brightness < 0.0 || temp->brightness > 1.0)
		error("the light brightness ratio in range [0.0,1.0]");
	i += check_next_param(' ', &line[i], 0);
	get_rgb(&line[i], &(temp->red), &(temp->green), &(temp->blue), "Light");
	light_lstadd_back(&obj->lght, temp);
	obj->check->light++;
}
