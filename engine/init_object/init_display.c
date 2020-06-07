#include "../../minirt.h"

void    push_param_display(char *line, t_object *obj)
{
    int i;

    i = 0;
    while (line[i] == ' ')
        i++;
    obj->dis->x = ft_atoi(&line[i]);
    while (line[i] != ' ')
        i++;
    obj->dis->y = ft_atoi(&line[i]);
    obj->check->display++;
}