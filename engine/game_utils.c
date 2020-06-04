#include "../cub.h"

void	forward(t_link *lnk)
{
	if (lnk->area->split_map[(int)(lnk->dis->pos_x + lnk->dis->dirx * 0.6)][(int)lnk->dis->pos_y] != '1'
	&& lnk->area->split_map[(int)(lnk->dis->pos_x + lnk->dis->dirx * 0.6)][(int)lnk->dis->pos_y] != 'Z')
		lnk->dis->pos_x += lnk->dis->dirx * 0.6;
	if (lnk->area->split_map[(int)lnk->dis->pos_x][(int)(lnk->dis->pos_y + lnk->dis->diry * 0.6)] != '1'
	&& lnk->area->split_map[(int)lnk->dis->pos_x][(int)(lnk->dis->pos_y + lnk->dis->diry * 0.6)] != 'Z')
		lnk->dis->pos_y += lnk->dis->diry * 0.6;
}

void	backward(t_link *lnk)
{
	if (lnk->area->split_map[(int)(lnk->dis->pos_x - lnk->dis->dirx * 0.6)][(int)lnk->dis->pos_y] != '1'
	&& lnk->area->split_map[(int)(lnk->dis->pos_x - lnk->dis->dirx * 0.6)][(int)lnk->dis->pos_y] != '2')
		lnk->dis->pos_x -= lnk->dis->dirx * 0.6;
	if (lnk->area->split_map[(int)lnk->dis->pos_x][(int)(lnk->dis->pos_y - lnk->dis->diry * 0.6)] != '1'
	&& lnk->area->split_map[(int)lnk->dis->pos_x][(int)(lnk->dis->pos_y - lnk->dis->diry * 0.6)] != 'Z')
		lnk->dis->pos_y -= lnk->dis->diry * 0.6;
}

void	left(t_link *lnk)
{
	if (lnk->area->split_map[(int)(lnk->dis->pos_x - lnk->dis->planx * 0.6)][(int)lnk->dis->pos_y] != '1'
	&& lnk->area->split_map[(int)(lnk->dis->pos_x - lnk->dis->planx * 0.6)][(int)lnk->dis->pos_y] != 'Z')
		lnk->dis->pos_x -= lnk->dis->planx * 0.6;
	if (lnk->area->split_map[(int)lnk->dis->pos_x][(int)(lnk->dis->pos_y - lnk->dis->plany * 0.6)] != '1'
	&& lnk->area->split_map[(int)lnk->dis->pos_x][(int)(lnk->dis->pos_y - lnk->dis->plany * 0.6)] != 'Z')
		lnk->dis->pos_y -= lnk->dis->plany * 0.6;
}

void	right(t_link *lnk)
{
	if (lnk->area->split_map[(int)(lnk->dis->pos_x + lnk->dis->planx * 0.6)][(int)lnk->dis->pos_y] != '1'
	&& lnk->area->split_map[(int)(lnk->dis->pos_x + lnk->dis->planx * 0.6)][(int)lnk->dis->pos_y] != 'Z')
		lnk->dis->pos_x += lnk->dis->planx * 0.6;
	if (lnk->area->split_map[(int)lnk->dis->pos_x][(int)(lnk->dis->pos_y + lnk->dis->plany * 0.6)] != '1'
	&& lnk->area->split_map[(int)lnk->dis->pos_x][(int)(lnk->dis->pos_y + lnk->dis->plany * 0.6)] != 'Z')
		lnk->dis->pos_y += lnk->dis->plany * 0.6;
}

void	rotate(t_link *lnk, int key)
{
	double olddirx;
	double oldplanex;

	if (key == 124)
	{
		olddirx = lnk->dis->dirx;
		lnk->dis->dirx = lnk->dis->dirx * cos(-0.1) - lnk->dis->diry * sin(-0.1);
		lnk->dis->diry = olddirx * sin(-0.1) + lnk->dis->diry * cos(-0.1);
		oldplanex = lnk->dis->planx;
		lnk->dis->planx = lnk->dis->planx * cos(-0.1) - lnk->dis->plany * sin(-0.1);
		lnk->dis->plany = oldplanex * sin(-0.1) + lnk->dis->plany * cos(-0.1);
	}
	if (key == 123)
	{
		olddirx = lnk->dis->dirx;
		lnk->dis->dirx = lnk->dis->dirx * cos(0.1) - lnk->dis->diry * sin(0.1);
		lnk->dis->diry = olddirx * sin(0.1) + lnk->dis->diry * cos(0.1);
		oldplanex = lnk->dis->planx;
		lnk->dis->planx = lnk->dis->planx * cos(0.1) - lnk->dis->plany * sin(0.1);
		lnk->dis->plany = oldplanex * sin(0.1) + lnk->dis->plany * cos(0.1);
	}
}