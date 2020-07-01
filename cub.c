/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:10:07 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 11:10:29 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/*
** A function that throws pixels to a bmp file
*/

static void		push_img_to_bmp(t_ptr *ptr, int fd)
{
	unsigned char	rgb[3];
	int				i;
	int				j;
	int				max_x;
	int				max_y;

	i = 0;
	max_y = ptr->p->y - 1;
	while (i < max_y)
	{
		max_x = ptr->p->x;
		j = 0;
		while (j < max_x)
		{
			rgb[0] = ptr->img[0]->img_data[j * ptr->img[0]->bpp / 8 +
			ptr->img[0]->size_line * max_y];
			rgb[1] = ptr->img[0]->img_data[(j * ptr->img[0]->bpp / 8 +
			ptr->img[0]->size_line * max_y) + 1];
			rgb[2] = ptr->img[0]->img_data[(j * ptr->img[0]->bpp / 8 +
			ptr->img[0]->size_line * max_y) + 2];
			write(fd, rgb, 3);
			j++;
		}
		max_y--;
	}
}

/*
** Pre-initialization to prevent memory leak
*/

static void		before_game_init(t_ptr *p)
{
	check_player(p->p->split_map);
	p->p->space_map = transform_space_map(p->p->split_map);
	check_space_map(p->p->space_map);
	init_match_struct(p);
	match_to_match(p->p->split_map, p);
	p->p->trans_map = transform_split_map(p->p->split_map);
	match_to_match(p->p->trans_map, p);
	init_game_struct(p);
	add_text(p, 1, ft_strtrim(p->p->nr, " "));
	add_text(p, 2, ft_strtrim(p->p->so, " "));
	add_text(p, 3, ft_strtrim(p->p->we, " "));
	add_text(p, 4, ft_strtrim(p->p->ea, " "));
	add_text(p, 5, ft_strtrim(p->p->sp, " "));
	init_game_param(p);
	init_dda_struct(p);
	p->m->win_ptr = mlx_new_window(p->m->mlx_ptr, p->p->x,
	p->p->y, "cub3D");
}

/*
** A function that draws a single frame
*/

static void		start_render(t_ptr *ptr, int fd)
{
	init_check_struct(ptr);
	get_param_objects(fd, ptr);
	before_game_init(ptr);
	ptr->img[0]->img_ptr = mlx_new_image(ptr->m->mlx_ptr, ptr->p->x,
	ptr->p->y);
	ptr->img[0]->img_data = mlx_get_data_addr(ptr->img[0]->img_ptr,
	&ptr->img[0]->bpp, &ptr->img[0]->size_line, &ptr->img[0]->endian);
	run_dda(ptr);
	mlx_put_image_to_window(ptr->m->mlx_ptr, ptr->m->win_ptr,
	ptr->img[0]->img_ptr, 0, 0);
}

/*
** General function that creating bmp file
*/

static void		creaty_bmp(t_ptr *ptr, int fd, char *filename)
{
	unsigned char			*file_header;
	unsigned char			*bitmap_header;

	fd = open(filename, O_RDONLY);
	start_render(ptr, fd);
	close(fd);
	fd = open("cub3D.bmp", O_CREAT | O_RDWR, 416);
	file_header = create_file_header(ptr->p->y - 1, ptr->p->x);
	bitmap_header = create_bitmap_header(ptr->p->y - 1, ptr->p->x);
	write(fd, file_header, 14);
	write(fd, bitmap_header, 40);
	push_img_to_bmp(ptr, fd);
	close(fd);
	close_win();
}

/*
** Main function
*/

int				main(int ac, char **av)
{
	int		fd;
	t_ptr	ptr;

	if (ac == 2)
	{
		if (check_filename(av[1]))
		{
			init_check_struct(&ptr);
			get_param_objects(open(av[1], O_RDONLY), &ptr);
			before_game_init(&ptr);
			start_game(&ptr);
		}
		else
			error("File name invalid (^_^)\n");
	}
	else if (ac == 3)
	{
		if (((ft_strcmp(av[2], "--save") == 0) ||
		(ft_strcmp(av[1], "--save") == 0)) &&
		(check_filename(av[1]) || check_filename(av[2])))
			creaty_bmp(&ptr, fd, (check_filename(av[1])) ? av[1] : av[2]);
	}
	else
		error("Arg more two input or less two input (> <)\n");
	return (0);
}
