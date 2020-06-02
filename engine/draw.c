#include "../cub.h"

void	set_player(t_link *param, char c)
{
	param->display->dirx = 0;
	param->display->diry = 0;
	param->display->planx = 0;
	param->display->plany = 0;
	if (c == 'N')
	{
		param->display->plany = 0.60;
		param->display->dirx = -1;
	}
	else if (c == 'S')
	{
		param->display->plany = -0.60;
		param->display->dirx = 1;
	}
	else if (c == 'W')
	{
		param->display->planx = -0.60;
		param->display->diry = -1;
	}
	else if (c == 'E')
	{
		param->display->planx = 0.60;
		param->display->diry = 1;
	}
}

void	set_point(t_link *param)
{
	param->display->camerax = 2 * (double)param->display->screen / (double)param->area->x - 1;
	param->display->raydirx = param->display->dirx + param->display->planx * param->display->camerax;
	
}

void	start_draw(t_link *param)
{
	if (!check_char_player(param))
		error("No direction of the player");
	param->display->screen = 0;
	while (param->display->screen < param->area->x)
	{
		set_point(param);
	}
	
}