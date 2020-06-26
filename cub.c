#include "cub.h"

int		main(int ac, char **av)
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
			//start_game(&ptr);
			/*
			//TEST check struct input
			printf("r: %d\nno: %d\nso: %d\nwe: %d\nea: %d\ns: %d\nf: %d\nc: %d\nmap: %d\npos_player: %d\n", ptr.check->r, ptr.check->no, ptr.check->so, ptr.check->we, ptr.check->ea, ptr.check->s, ptr.check->f, ptr.check->c, ptr.check->map, ptr.check->pos_player);
			*/
			/*
			//TEST param obj
			printf("\nDisplay: %d, %d\n", ptr.param->x, ptr.param->y);
			printf("\nNORTH: %s\n", ptr.param->north);
			printf("\nSOUTH: %s\n", ptr.param->south);
			printf("\nWEST: %s\n", ptr.param->west);
			printf("\nEAST: %s\n", ptr.param->east);
			printf("\nSPRITE: %s\n", ptr.param->sprite);
			printf("\nDir player: %c\n", ptr.param->dir_player);
			printf("\nLine map: %s\n", ptr.param->line_map);
			printf("\n Floor RGB: B - %d G - %d R - %d", ptr.param->f_rgb%256, (ptr.param->f_rgb/256)%256, ((ptr.param->f_rgb/256)/256)%256);
			printf("\n Ceilling RGB: B - %d G - %d R - %d", ptr.param->c_rgb%256, (ptr.param->c_rgb/256)%256, ((ptr.param->c_rgb/256)/256)%256);
			printf("\n\nMAP:\n\n");
			for (int i = 0; i < 14; i++)
				printf("%s\n", ptr.param->split_map[i]);
			*/
		}
		else
			error("File name invalid (^_^)");
	}
	else
		error("Arg more two input or less two input (> <)");
	return (0);
}