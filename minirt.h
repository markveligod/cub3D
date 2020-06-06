#ifndef MINIRT_H
# define MINIRT_H
# define BUFFER_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

typedef struct	s_display
{
	int			x;
	int			y;
}				t_display;

typedef struct	s_ambient
{
	double		coef;
	int			rgb[3];
}				t_ambient;

typedef struct	s_camera
{
	double		pos[3];
	double		normal[3];
	int			fov;
	t_camera	*next;
}				t_camera;

typedef struct	s_light
{
	double		pos[3];
	double		brightness;
	int			rgb[3];
	t_light		*next;
}				t_light;

typedef struct	s_sphere
{
	double		pos[3];
	double		diameter;
	int			rgb[3];
	t_sphere	*next;
}				t_sphere;

typedef struct	s_plane
{
	double		pos[3];
	double		normal[3];
	int			rgb[3];
	t_plane		*next;
}				t_plane;

typedef struct	s_square
{
	double		pos[3];
	double		normal[3];
	double		size;
	int			rgb[3];
	t_square	*next;
}				t_square;

typedef struct	s_cylinder
{
	double		pos[3];
	double		normal[3];
	double		diameter;
	double		height;
	int			rgb[3];
	t_cylinder	*next;
}				t_cylinder;

typedef struct	s_triangle
{
	double		pos[3];
	double		normal[3];
	double		diameter;
	double		height;
	int			rgb[3];
	t_triangle	*next;
}				t_triangle;

typedef struct	s_object
{
	t_display	*dis;
	t_ambient	*amb;
	t_camera	*cam;
	t_light		*lght;
	t_sphere	*sp;
	t_plane		*pl;
	t_square	*sq;
	t_cylinder	*cy;
	t_triangle	*tr;
}				t_object;

/*
 * utils prototype
*/
int				ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
int				get_next_line(int fd, char **line);
int				ft_atoi(const char *str);
void			ft_putstr_fd(char *str, int fd);
double			ft_atof(const char *str);

/*
 * engine prototype
*/
void			error(char *str);

#endif