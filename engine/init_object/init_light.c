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

void		get_pos_light(char *line, t_light *temp)
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

void		get_color_light(char *line, t_light *temp)
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

void        push_param_light(char *line, t_object *obj)
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
	while (line[i] == ' ')
		i++;
	get_pos_light(&line[i], &temp);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	temp->brightness = ft_atof(&line[i]);
	if (temp->brightness < 0.0 || temp->brightness > 1.0)
		error("the light brightness ratio in range [0.0,1.0]");
	while (line[i] != ' ')
		i++;
	get_color_light(&line[i], &temp);
	light_lstadd_back(&obj->lght, temp);
}