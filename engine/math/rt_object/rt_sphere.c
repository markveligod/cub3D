#include "../../../minirt.h"

void	init_vector_oc(t_object *obj)
{
	obj->view->vector_oc_x = obj->camera->pos_x - obj->sp->pos_x;
	obj->view->vector_oc_y = obj->camera->pos_y - obj->sp->pos_y;
	obj->view->vector_oc_z = obj->camera->pos_z - obj->sp->pos_z;
}

int		rt_sphere(t_object *obj, int t_min)
{
	int k1;
	int k2;
	int k3;
	int disc;

	init_vector_oc(obj);
	k1 = (1 * 1) + (1 * 1) + (1 * 1);
	k2 = 2 * ((obj->view->vector_oc_x * 1) + (obj->view->vector_oc_y * 1) + (obj->view->vector_oc_z * 1));
	k3 = ((obj->view->vector_oc_x * obj->view->vector_oc_x) + (obj->view->vector_oc_y * obj->view->vector_oc_y) + (obj->view->vector_oc_z * obj->view->vector_oc_z)) - ((obj->sp->diameter / 2) * (obj->sp->diameter / 2));
	disc = k2 * k2 - 4 * k1 * k3;
	if (disc < 0)
		return (BACKGROUND);
	
	return (BACKGROUND);
}