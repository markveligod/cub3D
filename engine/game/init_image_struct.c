#include "../../cub.h"

void		init_image_struct(t_ptr *ptr)
{
	int i;

	i = 0;
	if (!(ptr->img = (t_image **)malloc(sizeof(t_image *) * 7)))
		error("struct image** doesn't allocate in memory (*_*)");
	ft_bzero(ptr->img, sizeof(t_image *) * 7);
	while (i <= 5)
	{
		if (!(ptr->img[i] = (t_image *)malloc(sizeof(t_image))))
			error("struct img* doesn't allocate in memory (*_*)");
		ft_bzero(ptr->img[i], sizeof(t_image));
		i++;
	}
}