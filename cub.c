#include "cub.h"

static void		push_img_to_bmp(t_ptr *ptr, int fd)
{
	unsigned char	rgb[3];
	int				i;
	int				j;
	int				max_x;
	int				max_y;

	i = 0;
	max_y = ptr->param->y - 1;
	while (i < max_y)
	{
		max_x = ptr->param->x;
		j = 0;
		while (j < max_x)
		{
			rgb[0] = ptr->img[0]->img_data[j * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * max_y];
			rgb[1] = ptr->img[0]->img_data[(j * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * max_y) + 1];
			rgb[2] = ptr->img[0]->img_data[(j * ptr->img[0]->bpp / 8 + ptr->img[0]->size_line * max_y) + 2];
			write(fd, rgb, 3);
			j++;
		}
		max_y--;
	}
}

static void		start_render(t_ptr *ptr, int fd)
{
	init_check_struct(ptr);
	get_param_objects(fd ,ptr);
	match_to_match(ptr->param->split_map, ptr);
	init_game_struct(ptr);
	add_text(ptr, 1, ft_strtrim(ptr->param->north, " "));
	add_text(ptr, 2, ft_strtrim(ptr->param->south, " "));
	add_text(ptr, 3, ft_strtrim(ptr->param->west, " "));
	add_text(ptr, 4, ft_strtrim(ptr->param->east, " "));
	add_text(ptr, 5, ft_strtrim(ptr->param->sprite, " "));
	init_game_param(ptr);
	init_dda_struct(ptr);
	ptr->mlx->win_ptr = mlx_new_window(ptr->mlx->mlx_ptr, ptr->param->x, ptr->param->y, "CUB3D GAME");
	ptr->img[0]->img_ptr = mlx_new_image(ptr->mlx->mlx_ptr, ptr->param->x, ptr->param->y);
	ptr->img[0]->img_data = mlx_get_data_addr(ptr->img[0]->img_ptr, &ptr->img[0]->bpp,
	&ptr->img[0]->size_line, &ptr->img[0]->endian);
	run_dda(ptr);
	mlx_put_image_to_window(ptr->mlx->mlx_ptr, ptr->mlx->win_ptr, ptr->img[0]->img_ptr, 0, 0);
}

static void		creaty_bmp(t_ptr *ptr, int fd, char *filename)
{
	unsigned char			*file_header;
	unsigned char			*bitmap_header;


	fd = open(filename, O_RDONLY);
	start_render(ptr, fd);
	close(fd);
	fd = open("cub3d_picture.bmp", O_CREAT | O_RDWR, 416);
	file_header = create_file_header(ptr->param->y - 1, ptr->param->x);
	bitmap_header = create_bitmap_header(ptr->param->y - 1, ptr->param->x);
	write(fd, file_header, 14);
	write(fd, bitmap_header, 40);
	push_img_to_bmp(ptr, fd);
	close(fd);
	close_win();
}

int				main(int ac, char **av)
{
	int		fd;
	t_ptr	ptr;

	if (ac == 2)
	{
		if (check_filename(av[1]))
		{
			fd = open(av[1], O_RDONLY);
			init_check_struct(&ptr);
			get_param_objects(fd ,&ptr);
			match_to_match(ptr.param->split_map, &ptr);
			start_game(&ptr);
		}
		else
			ft_putstr_fd("File name invalid (^_^)\n", 1);
	}
	else if (ac == 3)
	{
		if (((ft_strncmp(av[2], "--save", ft_strlen("--save")) || ft_strncmp(av[1], "--save", ft_strlen("--save")))
		&& (check_filename(av[1]) || check_filename(av[2]))))
			creaty_bmp(&ptr, fd, (check_filename(av[1])) ? av[1] : av[2]);
	}
	else
		ft_putstr_fd("Arg more two input or less two input (> <)\n", 1);
	return (0);
}