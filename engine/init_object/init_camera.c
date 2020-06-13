#include "../../minirt.h"

void		camera_lstadd_back(t_camera **alst, t_camera *new)
{
	t_camera *lst;

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

void		push_param_camera(char *line, t_object *obj)
{
	int i;
	t_camera *temp;

	i = 0;
	if (!(temp = (t_camera *)malloc(sizeof(t_camera))))
		error("Memory could not be allocated in the Camera parameter");
	temp->next = NULL;
	i += check_next_param(' ', &line[i], 1);
	get_pos(&line[i], &(temp->pos_x), &(temp->pos_y), &(temp->pos_z));
	i += check_next_param(' ', &line[i], 0);
	get_normal(&line[i], &(temp->normal_x), &(temp->normal_y), &(temp->normal_z), "Camera");
	i += check_next_param(' ', &line[i], 1);
	i += check_next_param(' ', &line[i], 0);
	temp->fov = ft_atoi(&line[i]);
	if (temp->fov < 0 || temp->fov > 180)
		error("FOV : Horizontal field of view in degrees in range [0,180]");
	camera_lstadd_back(&obj->cam, temp);
	obj->check->camera++;
}
