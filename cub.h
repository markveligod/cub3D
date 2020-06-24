#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 32

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>


typedef struct	s_check
{
	short int	check_r;
	short int	check_no;
	short int	check_so;
	short int	check_we;
	short int	check_ea;
	short int	check_s;
	short int	check_f;
	short int	check_c;
	short int	check_map;
	short int	check_pos_player;
}				t_check;

typedef struct	s_param
{
	int			x;
	int			y;
	char		*north;
	char		*south;
	char		*west;
	char		*west;
	char		*east;
	char		*sprite;
	int			f_rgb;
	int			c_rgb;
	char		dir_player;
	char		*line_map;
	char		**split_map;
}				t_param;

typedef struct	s_ptr
{
	t_check		*check;
	t_param		*param;
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

/*
 * Prototype check
*/
int				check_filename(char *filename);
void			init_check_struct(t_ptr *ptr);
void			check_line_map(char *line, t_ptr *ptr);

/*
 * Prototype get pararm obj
*/
void			init_param_objects(t_ptr *ptr);
void			get_param_objects(int fd, t_ptr *ptr);
void			sort_param_objects(char *line, t_ptr *ptr);



#endif