#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 32

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

typedef	struct	s_area
{
	char		*linear_map;
	char		**brut_map;
	int			x;
	int			y;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
}				t_area;

typedef struct	s_link
{
	t_area		*area;
}				t_link;

/*
	Utils prototype
*/
int		get_next_line(int fd,char **line);
char	*ft_strjoin(char *remains, char *buffer);
int		ft_strlen(char *str);
void	*ft_calloc(size_t number, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strdup(const char *str);
int		ft_isspace(char c);
int		ft_atoi(const char *str);

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

/*
	map prototype
*/
char	*get_map_param(char *line);

#endif