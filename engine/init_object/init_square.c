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

void		get_pos_square(char *line, t_square *temp)
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

void		get_color_square(char *line, t_square *temp)
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

void		get_normal_square(char *line, t_square *temp)
{
	int i;

	i = 0;
	temp->normal[0] = ft_atof(line[i]);
	if (temp->normal[0] < -1.0 || temp->normal[0] > 1.0)
		error("3d normalized orientation vector. In range [-1,1] (*_*)");
	while (line[i] != ',')
		i++;
	temp->normal[1] = ft_atof(&line[i]);
	if (temp->normal[1] < -1.0 || temp->normal[1] > 1.0)
		error("3d normalized orientation vector. In range [-1,1] (*_*)");
	while (line[i] != ',')
		i++;
	temp->normal[2] = ft_atof(&line[i]);
	if (temp->normal[2] < -1.0 || temp->normal[2] > 1.0)
		error("3d normalized orientation vector. In range [-1,1] (*_*)");
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
	while (line[i] == ' ')
		i++;
	get_pos_plane(&line[i], &temp);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	get_normal_plane(&line[i], &temp);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	temp->size = ft_atof(&line[i]);
	if (temp->size < 0.0)
		error("The size cannot be negative");
	while (line[i] != ' ')
		i++;
	get_color_square(&line[i], &temp);
	square_lstadd_back(&obj->sq, temp);
}
