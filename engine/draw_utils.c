#include "../cub.h"

int		check_char_player(t_link *param)
{
	short int i;
	short int j;

	i = -1;
	while (param->area->brut_map[++i])
	{
		j = -1;
		while (param->area->brut_map[i][++j])
			if (param->area->brut_map[i][j] == 'N' || param->area->brut_map[i][j] == 'S' ||
			param->area->brut_map[i][j] == 'W' || param->area->brut_map[i][j] == 'E')
			{
				param->display->pos_x = (double)i + 0.5;
				param->display->pos_y = (double)j + 0.5;
				set_player(param, param->area->brut_map[i][j]);
				return (1);
			}
	}
	return (0);
}