#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 16

# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <mlx.h>

#include <stdio.h> //any time

typedef	struct	s_area
{
	char		*linear_map;
	char		**brut_map;
	short int	x;
	short int	y;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	short int	c_red_color;
	short int	c_green_color;
	short int	c_blue_color;
	short int	f_red_color;
	short int	f_green_color;
	short int	f_blue_color;
}				t_area;

typedef struct	s_display
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		dirx;
	double		diry;
	double		pos_x;
	double		pos_y;
	double		planx;
	double		plany;
	short int	screen;
	double		camerax;
	double		raydirx;
	double		raydiry;
	short int	mapx;
	short int	mapy;
	double		deltadistx;
	double		deltadisty;
	short int	stepx;
	short int	stepy;
	double		sidedistx;
	double		sidedisty;
	short int	hit;
	short int	side;
	double		walldist;
	short int	lineheight;
	short int	drawstart;
	short int	drawend;
}				t_display;

typedef struct	s_image
{
	void		*image_ptr;
	char		*image_data;
	int			depth;
	short int	size_line;
	short int	endian;
	short int	width;
	short int	height;
}				t_image;

typedef struct	s_link
{
	t_area		*area;
	t_display	*display;
	t_image		*image;
}				t_link;

/*
	Utils prototype
*/
int		get_next_line(int fd,char **line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	*ft_calloc(size_t number, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *str);
int		ft_isspace(char c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);

/*
	error (*-*)
*/
void	error(char *str);

/*
	start param prototype
*/
void	get_init_param(t_link *param);
void	get_param_file(int fd, t_link *param);
void	get_sort_param(char *line, t_link *param);
void	push_size_xy(char *line, t_link *param);
void	push_text(char *line, t_link *param, int flag);
void	push_floor_color(char *line, t_link *param);
void	push_ceilling_color(char *line, t_link *param);

/*
	map prototype
*/
char	*get_map_param(char *line);

/*
 * game and	draw prototype
*/
void	start_game(t_link *param);
void	start_draw(t_link *param);
int		check_char_player(t_link *param);
void	set_player(t_link *param, char c);
void	which_wall(t_link *param);
void	set_draw(t_link *param);

#endif
