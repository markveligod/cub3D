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

void	set_walldist(t_link *param)
{
	param->display->hit = 0;
	param->display->side = 0;
	while (param->display->hit == 0)
	{
		if (param->display->sidedistx < param->display->sidedisty)
		{
			param->display->sidedistx += param->display->deltadistx;
			param->display->mapx += param->display->stepx;
			param->display->side = 0;
		}
		else
		{
			param->display->sidedisty += param->display->deltadisty;
			param->display->mapy += param->display->stepy;
			param->display->side = 1;
		}
		if (param->area->brut_map[param->display->mapx][param->display->mapy] == '1')
			which_wall(param);
	}
	if (param->display->side == 1 || param->display->side == 2)
		param->display->walldist = (param->display->mapx - param->display->pos_x +
			(1 - param->display->stepx) / 2) / param->display->raydirx;
	else if (param->display->side == 3 || param->display->side == 4)
		param->display->walldist = (param->display->mapy - param->display->pos_y +
			(1 - param->display->stepy) / 2) / param->display->raydiry;
}

void	set_sidedist(t_link *param)
{
	if (param->display->raydirx < 0)
	{
		param->display->stepx = -1;
		param->display->sidedistx = (param->display->pos_x - param->display->mapx) * param->display->deltadistx;
	}
	else
	{
		param->display->stepx = 1;
		param->display->sidedistx = (param->display->mapx + 1.0 - param->display->pos_x) * param->display->deltadistx;
	}
	if (param->display->raydiry < 0)
	{
		param->display->stepy = -1;
		param->display->deltadisty = (param->display->pos_y - param->display->mapy) * param->display->deltadisty;
	}
	else
	{
		param->display->stepy = 1;
		param->display->sidedisty = (param->display->mapy + 1.0 - param->display->pos_y) * param->display->deltadisty;
	}
	
}

void	set_point(t_link *param)
{
	param->display->camerax = 2 * (double)param->display->screen / (double)param->area->x - 1;
	param->display->raydirx = param->display->dirx + param->display->planx * param->display->camerax;
	param->display->raydiry = param->display->diry + param->display->plany * param->display->camerax;
	param->display->mapx = (int)param->display->pos_x;
	param->display->mapy = (int)param->display->pos_y;
	param->display->deltadistx = fabs(1 / param->display->raydirx);
	param->display->deltadisty = fabs(1 / param->display->raydiry);
	set_sidedist(param);
	set_walldist(param);
}

void	start_draw(t_link *param)
{
	if (!check_char_player(param))
		error("No direction of the player");
	param->display->screen = 0;
	while (param->display->screen < param->area->x)
	{
		set_point(param);
		set_draw(param);
		param->display->screen++;
	}
}
