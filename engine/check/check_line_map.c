#include "../../cub.h"

static void		check(int i, int j, char **map)
{
	int k;

	k = j;
	while (map[i][k] != '1' && map[i][k])
		k--;
	if (map[i][k] != '1')
		error("player out of range");
	k = j;
	while (map[i][k] != '1' && map[i][k])
		k++;
	if (map[i][k] != '1')
		error("player out of range");
	k = i;
	while (map[k] && map[k][j] != '1')
		k++;
	if (!map[k] || map[k][j] != '1')
		error("player out of range");
	k = i;
	while (k >= 0 && map[k][j] != '1')
		k--;
	if (!map[k] || map[k][j] != '1')
		error("player out of range");
}

void			check_player(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' ||
				map[i][j] == 'W')
				check(i, j, map);
			j++;
		}
		i++;
	}
}

void			check_up_down_line(char **arr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (arr[i][j])
	{
		if (arr[i][j] != '1' && arr[i][j] != ' ')
			error("First line have zero or player (-___)");
		j++;
	}
	while (arr[i])
		i++;
	j = 0;
	i--;
	while (arr[i][j])
	{
		if (arr[i][j] != '1' && arr[i][j] != ' ')
			error("Last line have zero or player (-___)");
		j++;
	}
}

void			check_line_map(char *line, t_ptr *ptr)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && !(line[i] >= '0' && line[i] <= '2') &&
		line[i] != 'N' && line[i] != 'S' && line[i] != 'E' &&
		line[i] != 'W' && line[i] != '\t')
			error("Unknown symbol on map line");
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' ||
		line[i] == 'W')
		{
			ptr->p->dir_pl = line[i];
			ptr->c->pos_player++;
		}
		i++;
	}
}
