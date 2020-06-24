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

typedef struct	s_ptr
{
	t_check		*check;
	t_paramobj	*param;
}				t_ptr;

/*
 * Prototype error
*/
void			error(char *str);

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

/*
 * Prototype check
*/
int				check_filename(char *filename);
void			init_check_struct(t_ptr *ptr);
void			check_line_map(char *line, t_ptr *ptr);
void			check_param_objects(t_ptr *ptr);

/*
 * Prototype get pararm obj
*/
void			init_param_objects(t_ptr *ptr);
void			get_param_objects(int fd, t_ptr *ptr);
void			sort_param_objects(char *line, t_ptr *ptr);
void			get_param_map(int fd, char *line, t_ptr *ptr);



#endif