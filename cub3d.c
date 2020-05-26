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
int     check_filename(char *str, int size)
{
	return ((str[size - 4] == '.' && str[size - 3] == 'c' &&
	str[size - 2] == 'u' && str[size - 1] == 'b'));
}

/*
	Initializing the entire structure
*/
void	get_calloc_param(link *param)
{
	if(!(param->area = ft_calloc(sizeof(area), 1)))
		error("ERROR: failed to execute 'calloc' for 'area'");
	if(!(param->dis = ft_calloc(sizeof(display), 1)))
		error("ERROR: failed to execute 'calloc' for 'display'");
}

/*
	Getting parameters from a file
*/
void	get_param_file(int fd, link *param)
{
	char	*line;
	int		count;
	int		i;

	count = 1;
	while (count > 0)
	{
		i = 0;
		if ((count = get_next_line(fd, &line)) == (-1))
			error("ERROR: The file cannot be read");
		while (line[i] == ' ')
			i++;
	}
	if (line[i] == '1' || line[i] == '0' || line[i] == '2')
	{
		line = 
	}
}

int     main(int ac, char **av)
{
	int     fd;
	link  param;

	fd = 0;
	if (ac == 2 && check_filename(av[1], ft_strlen(av[1])))
	{
		fd = open(av[1], O_RDONLY);
		init_param(&param);
		param.dis->mlx_ptr = mlx_init();
		get_param_file(fd, &param);
		start_game(&param);
	}
	close(fd);
	return (0);
}