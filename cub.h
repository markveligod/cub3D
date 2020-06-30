/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:20:18 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 11:20:48 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 32

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <errno.h>
# include <mlx.h>
# include <unistd.h>

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
	char		*nr;
	char		*so;
	char		*we;
	char		*ea;
	char		*sp;
	int			f_rgb;
	int			c_rgb;
	char		dir_pl;
	char		*line_map;
	char		**split_map;
}				t_paramobj;

typedef struct	s_player
{
	double		p_x;
	double		p_y;
	double		d_x;
	double		d_y;
	double		pl_x;
	double		pl_y;
	double		ms;
	double		rots;
}				t_player;

typedef struct	s_mlxparam
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlxparam;

typedef struct	s_dda
{
	double		cam_x;
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

typedef	struct	s_barrel
{
	int			nb_sprite;
	double		*buffer;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			stripe;
	int			d;
	int			texx;
	int			texy;
}				t_barrel;

typedef	struct	s_sprite
{
	int			x;
	int			y;
	double		s_dist;
}				t_sprite;

typedef struct	s_ptr
{
	t_check		*c;
	t_paramobj	*p;
	t_player	*pl;
	t_mlxparam	*m;
	t_match		*mt;
	t_image		**img;
	t_dda		*dda;
	t_barrel	*b;
	t_sprite	**z;
}				t_ptr;

/*
** Prototype error
*/

void			error(char *str);
int				close_win(void);

/*
** Prototype utils
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
int				ft_strncmp(const char *str1, const char *str2, size_t n);

/*
** Prototype check
*/

int				check_filename(char *filename);
void			init_check_struct(t_ptr *ptr);
void			check_line_map(char *line, t_ptr *ptr);
void			check_param_objects(t_ptr *ptr);
void			match_to_match(char **arr, t_ptr *ptr);
int				check_black(t_ptr *ptr);
void			check_dist_sprite(t_ptr *ptr);
void			check_draw_sprite(t_ptr *ptr);
void			check_up_down_line(t_ptr *ptr);
void			check_vert_map(t_ptr *ptr, char **arr);

/*
** Prototype get param obj
*/

void			init_param_objects(t_ptr *ptr);
void			get_param_objects(int fd, t_ptr *ptr);
void			sort_param_objects(char *line, t_ptr *ptr);
void			get_param_map(int fd, char *line, t_ptr *ptr);
void			push_param_object(char **param, char *line);
void			init_sprite_struct(t_ptr *ptr);

/*
** Prototype dda param
*/

void			init_dda_struct(t_ptr *ptr);
void			run_dda(t_ptr *ptr);
void			run_draw(t_ptr *ptr);
void			draw_sprite(t_ptr *ptr);
void			put_pixel_texture(t_ptr *p, int y);

/*
** Prototype game param
*/

void			start_game(t_ptr *ptr);
void			init_game_struct(t_ptr *ptr);
void			init_game_param(t_ptr *ptr);
void			forward_back_keys(t_ptr *ptr, int key);
void			rot_left_right_keys(t_ptr *p, int key, double olddx,
				double oldplx);
void			left_right_keys(t_ptr *ptr, int key);
void			init_text_param(t_ptr *ptr);
void			add_text(t_ptr *ptr, int flag, char *path);
unsigned char	*create_file_header(int res_y, int res_x);
unsigned char	*create_bitmap_header(int res_y, int res_x);

#endif
