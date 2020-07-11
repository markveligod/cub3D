#include "../../cub.h"

/*
** Auxiliary function for adding texture and sprite parameters
*/

void			push_param_object(char **param, char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '.' && line[i + 1] == '/')
		*param = line;
	else
		error("Incorrect path to the texture (*_*)");
}

/*
** The function records display parameters
*/

static void		get_resolution(char *line, t_ptr *ptr)
{
	int i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	ptr->p->x = ft_atoi(&line[i]);
	if (ptr->p->x > 2560)
		ptr->p->x = 2560;
	else if (ptr->p->x <= 0)
		error("Set a normal width!!! (-_-)");
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	ptr->p->y = ft_atoi(&line[i]);
	if (ptr->p->y > 1440)
		ptr->p->y = 1440;
	else if (ptr->p->y <= 0)
		error("Set a normal HEIGHT (-_-)");
	ptr->c->r++;
}

/*
** The function writes the parameters of the texture and sprite
*/

static void		get_texture(char *line, t_ptr *ptr, char *flags, int i)
{
	if (flags[i] == 'N' && flags[i + 1] == 'O')
	{
		push_param_object(&(ptr->p->nr), line);
		ptr->c->no++;
	}
	else if (flags[i] == 'S' && flags[i + 1] == 'O')
	{
		push_param_object(&(ptr->p->so), line);
		ptr->c->so++;
	}
	else if (flags[i] == 'W' && flags[i + 1] == 'E')
	{
		push_param_object(&(ptr->p->we), line);
		ptr->c->we++;
	}
	else if (flags[i] == 'E' && flags[i + 1] == 'A')
	{
		push_param_object(&(ptr->p->ea), line);
		ptr->c->ea++;
	}
	else if (flags[i] == 'S' && flags[i + 1] == '\0')
	{
		push_param_object(&(ptr->p->sp), line);
		ptr->c->s++;
	}
}

/*
** Function for getting the color of the ceiling and floor
*/

static void		get_f_c(char *line, int *rgb, char flag, t_ptr *ptr)
{
	int r;
	int g;
	int b;
	int i;

	i = 0;
	r = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	g = ft_atoi(&line[i]);
	while (line[i] != ',')
		i++;
	i++;
	b = ft_atoi(&line[i]);
	if (!((r >= 0 && r <= 255) && ((g >= 0 && g <= 255)) &&
	((b >= 0 && b <= 255))))
		error("RGB within [0-255] (6_6)");
	*rgb = r;
	*rgb = (*rgb << 8) + g;
	*rgb = (*rgb << 8) + b;
	if (flag == 'F')
		ptr->c->f++;
	else if (flag == 'C')
		ptr->c->c++;
}

/*
** The main function for sorting incoming parameters
*/

void			sort_param_objects(char *line, t_ptr *ptr)
{
	int i;

	i = 0;
	if (line[i] == '\0' || line[i] == 13)
		return ;
	if (line[i] == 'R' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		get_resolution(&line[i + 1], ptr);
	else if (((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' &&
	line[i + 1] == 'O') || (line[i] == 'W' && line[i + 1] == 'E') ||
	(line[i] == 'E' && line[i + 1] == 'A')) && (line[i + 2] == ' ' ||
	line[i + 2] == '\t'))
		get_texture(&line[i + 2], ptr, &line[i], 0);
	else if (line[i] == 'S' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		get_texture(&line[i + 1], ptr, "S", 0);
	else if (line[i] == 'F' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		get_f_c(&line[i + 1], &(ptr->p->f_rgb), line[i], ptr);
	else if (line[i] == 'C' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		get_f_c(&line[i + 1], &(ptr->p->c_rgb), line[i], ptr);
	else
		error("Unknow identifier (!_!)");
}
