#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 32

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <mlx.h>
# include <unistd.h>

#include <stdio.h>

typedef struct	s_check
{
	short int	r;
	short int	no;
	short int	so;
	short int	we;
	short int	ea;
	short int	s;
	short int	f;
	short int	c;
	short int	map;
	short int	pos_player;
}				t_check;

typedef struct	s_paramobj
{
	int			x;
	int			y;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			f_rgb;
	int			c_rgb;
	char		dir_player;
	char		*line_map;
	char		**split_map;
}				t_paramobj;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		movespeed;
	double		rotspeed;
}				t_player;

typedef struct	s_mlxparam
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlxparam;

typedef struct	s_dda
{
	double		camera_x;
	int			screenx;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		walldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wallx;
	int			textx;
	int			texty;
	double		step;
	double		textpos;
}				t_dda;

typedef struct	s_match
{
	short int	line_up_1;
	short int	line_up_2;
	short int	line_up_3;
	short int	line_up_4;
	short int	line_down_1;
	short int	line_down_2;
	short int	line_down_3;
	short int	line_down_4;
}				t_match;

typedef struct	s_image
{
	void		*img_ptr;
	char		*img_data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_sprite
{
	double		*buffer;
}				t_sprite;


typedef struct	s_ptr
{
	t_check		*check;
	t_paramobj	*param;
	t_player	*player;
	t_mlxparam	*mlx;
	t_match		*match;
	t_image		**img;
	t_dda		*dda;
	t_sprite	*sp;
}				t_ptr;

/*
 * Prototype error
*/
void			error(char *str);
int				close_win(void);

/*
 * Prototype utils
*/
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
void			ft_putstr_fd(char *str, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);
char			**ft_split(char const *s, char c);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
char			*ft_strtrim(char const *s1, char const *set);

/*
 * Prototype check 
*/
int				check_filename(char *filename);
void			init_check_struct(t_ptr *ptr);
void			check_line_map(char *line, t_ptr *ptr);
void			check_param_objects(t_ptr *ptr);
void			match_to_match(char **arr, t_ptr *ptr);

/*
 * Prototype get param obj
*/
void			init_param_objects(t_ptr *ptr);
void			get_param_objects(int fd, t_ptr *ptr);
void			sort_param_objects(char *line, t_ptr *ptr);
void			get_param_map(int fd, char *line, t_ptr *ptr);

/*
 * Prototype dda param
*/
void			init_dda_struct(t_ptr *ptr);
void			run_dda(t_ptr *ptr);
void			run_draw(t_ptr *ptr);

/*
 * Prototype game param
*/
void			start_game(t_ptr *ptr);
void			init_game_struct(t_ptr *ptr);
void			init_game_param(t_ptr *ptr);
void			forward_back_keys(t_ptr *ptr, int key);
void			rot_left_right_keys(t_ptr *ptr, int key);
void			left_right_keys(t_ptr *ptr, int key);
void			init_text_param(t_ptr *ptr);

#endif