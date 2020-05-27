/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:51:48 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/25 15:51:48 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	Check for compliance with the format
*/
int		check_filename(char *str, int size)
{
	return ((str[size - 4] == '.' && str[size - 3] == 'c' &&
	str[size - 2] == 'u' && str[size - 1] == 'b'));
}

/*
	Initializing the entire structure
*/
void	get_calloc_param(t_link *param)
{
	if(!(param->area = ft_calloc(sizeof(t_area), 1)))
		error("ERROR: failed to execute 'calloc' for 'area'");
	if(!(param->display = ft_calloc(sizeof(t_display), 1)))
		error("ERROR: failed to execute 'calloc' for 'display'");
}

/*
	Getting parameters from a file
*/
void	get_linear_map(int fd, t_link *param)
{
	char	*line;
	int		count;
	int		flag;
	int		i;

	flag = 1;
	while (flag)
	{
		count = get_next_line(fd, &line);
		if (count == (-1))
			error("ERROR: Scene file can't be read");
		else
		{
			flag = (count == 0) ? 0 : 1;
			i = -1;
			while (line[++i])
			{
				if (line[i] == ' ')
					continue ;
				if (check_al_param(line, param))
					break ;
				if (line[i] == '1' || line[i] == '0' || line[i] == '2')
				{
					line = clean_map_line(line);
					param->area->linear_map = ft_strjoin_upd(param->area->linear_map, line, 1);
					break ;
				}
			}
		}
	}
}

int     main(int ac, char **av)
{
	int     fd;
	t_link  param;

	fd = 0;
	if (ac == 2 && check_filename(av[1], ft_strlen(av[1])))
	{
		fd = open(av[1], O_RDONLY);
		init_param(&param);
		param.display->mlx_ptr = mlx_init();
		get_linear_map(fd, &param);
		param.area->brut_map = ft_split(param.area->linear_map, '$');

	}
	close(fd);
	return (0);
}