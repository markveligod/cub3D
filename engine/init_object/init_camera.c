#include "../../minirt.h"

t_camera	*camera_lstlast(t_camera *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void		camera_lstadd_back(t_camera **alst, t_camera *new)
{
	t_camera *lst;

	if (!new)
		return ;
	if (!alst || !*alst)
		*alst = new;
	else
	{
		lst = camera_lstlast(*alst);
		lst->next = new;
	}
}

void			get_pos_camera(char *line, t_camera *temp)
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

void			get_normal_camera(char *line, t_camera *temp)
{
	int i;

	i = 0;
	temp->normal[0] = ft_atof(line[i]);
	while (line[i] != ',')
		i++;
	temp->normal[1] = ft_atof(&line[i]);
	while (line[i] != ',')
		i++;
	temp->normal[2] = ft_atof(&line[i]);
}

t_camera		push_param_camera(char *line, t_object *obj)
{
	int i;
	t_camera *temp;

	i = 0;
	temp = obj->cam;
	while (temp)
		temp = temp->next;
	if (!(temp = (t_camera *)malloc(sizeof(t_camera))))
		error("Memory could not be allocated in the Camera parameter");
	obj->cam->next = NULL;
	while (line[i] == ' ')
		i++;
	get_pos_camera(&line[i], &temp);
	while (line[i] != ' ')
		i++;
	get_normal_camera(&line[i], &temp);
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ')
		i++;
	temp->fov = ft_atoi(&line[i]);
}