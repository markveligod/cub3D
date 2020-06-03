#include "../cub.h"

void	forward(t_link *param)
{
	if (param->area->brut_map[(int)(param->display->pos_x + param->display->dirx * 0.6)][(int)param->display->pos_y] != '1'
	&& param->area->brut_map[(int)(param->display->pos_x + param->display->dirx * 0.6)][(int)param->display->pos_y] != 'Z')
		param->display->pos_x += param->display->dirx * 0.6;
	if (param->area->brut_map[(int)param->display->pos_x][(int)(param->display->pos_y + param->display->diry * 0.6)] != '1'
	&& param->area->brut_map[(int)param->display->pos_x][(int)(param->display->pos_y + param->display->diry * 0.6)] != 'Z')
		param->display->pos_y += param->display->diry * 0.6;
}

void	backward(t_link *param)
{
	if (param->area->brut_map[(int)(param->display->pos_x - param->display->dirx * 0.6)][(int)param->display->pos_y] != '1'
	&& param->area->brut_map[(int)(param->display->pos_x - param->display->dirx * 0.6)][(int)param->display->pos_y] != '2')
		param->display->pos_x -= param->display->dirx * 0.6;
	if (param->area->brut_map[(int)param->display->pos_x][(int)(param->display->pos_y - param->display->diry * 0.6)] != '1'
	&& param->area->brut_map[(int)param->display->pos_x][(int)(param->display->pos_y - param->display->diry * 0.6)] != 'Z')
		param->display->pos_y -= param->display->diry * 0.6;
}

void	left(t_link *param)
{
	if (param->area->brut_map[(int)(param->display->pos_x - param->display->planx * 0.6)][(int)param->display->pos_y] != '1'
	&& param->area->brut_map[(int)(param->display->pos_x - param->display->planx * 0.6)][(int)param->display->pos_y] != 'Z')
		param->display->pos_x -= param->display->planx * 0.6;
	if (param->area->brut_map[(int)param->display->pos_x][(int)(param->display->pos_y - param->display->plany * 0.6)] != '1'
	&& param->area->brut_map[(int)param->display->pos_x][(int)(param->display->pos_y - param->display->plany * 0.6)] != 'Z')
		param->display->pos_y -= param->display->plany * 0.6;
}

void	right(t_link *param)
{
	if (param->area->brut_map[(int)(param->display->pos_x + param->display->planx * 0.6)][(int)param->display->pos_y] != '1'
	&& param->area->brut_map[(int)(param->display->pos_x + param->display->planx * 0.6)][(int)param->display->pos_y] != 'Z')
		param->display->pos_x += param->display->planx * 0.6;
	if (param->area->brut_map[(int)param->display->pos_x][(int)(param->display->pos_y + param->display->plany * 0.6)] != '1'
	&& param->area->brut_map[(int)param->display->pos_x][(int)(param->display->pos_y + param->display->plany * 0.6)] != 'Z')
		param->display->pos_y += param->display->plany * 0.6;
}

void	rotate(t_link *param, int key)
{
	double olddirx;
	double oldplanex;

	if (key == 124)
	{
		olddirx = param->display->dirx;
		param->display->dirx = param->display->dirx * cos(-0.1) - param->display->diry * sin(-0.1);
		param->display->diry = olddirx * sin(-0.1) + param->display->diry * cos(-0.1);
		oldplanex = param->display->planx;
		param->display->planx = param->display->planx * cos(-0.1) - param->display->plany * sin(-0.1);
		param->display->plany = oldplanex * sin(-0.1) + param->display->plany * cos(-0.1);
	}
	if (key == 123)
	{
		olddirx = param->display->dirx;
		param->display->dirx = param->display->dirx * cos(0.1) - param->display->diry * sin(0.1);
		param->display->diry = olddirx * sin(0.1) + param->display->diry * cos(0.1);
		oldplanex = param->display->planx;
		param->display->planx = param->display->planx * cos(0.1) - param->display->plany * sin(0.1);
		param->display->plany = oldplanex * sin(0.1) + param->display->plany * cos(0.1);
	}
}