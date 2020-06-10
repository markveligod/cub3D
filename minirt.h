#ifndef MINIRT_H
# define MINIRT_H
# define BUFFER_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

#include <stdio.h>

typedef struct			s_check
{
	int					display;
	int					ambient;
	int					camera;
	int					light;
	int					sphere;
	int					plane;
	int					square;
	int					cylinder;
	int					triangle;
}						t_check;


typedef struct			s_display
{
	int					x;
	int					y;
}						t_display;

typedef struct			s_ambient
{
	double				coef;
	int					*rgb;
}						t_ambient;

typedef struct			s_camera
{
	double				pos[3];
	double				normal[3];
	int					fov;
	struct s_camera		*next;
}						t_camera;

typedef struct			s_light
{
	double				pos[3];
	double				brightness;
	int					rgb[3];
	struct s_light		*next;
}						t_light;

typedef struct			s_sphere
{
	double				pos[3];
	double				diameter;
	int					rgb[3];
	struct s_sphere		*next;
}						t_sphere;

typedef struct			s_plane
{
	double				pos[3];
	double				normal[3];
	int					rgb[3];
	struct s_plane		*next;
}						t_plane;

typedef struct			s_square
{
	double				pos[3];
	double				normal[3];
	double				size;
	int					rgb[3];
	struct s_square		*next;
}						t_square;

typedef struct			s_cylinder
{
	double				pos[3];
	double				normal[3];
	double				diameter;
	double				height;
	int					rgb[3];
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct			s_triangle
{
	double				pos[9];
	int					rgb[3];
	struct s_triangle	*next;
}						t_triangle;

typedef struct			s_object
{
	t_check				*check;
	t_display			*dis;
	t_ambient			*amb;
	t_camera			*cam;
	t_light				*lght;
	t_sphere			*sp;
	t_plane				*pl;
	t_square			*sq;
	t_cylinder			*cy;
	t_triangle			*tr;
}						t_object;

/*
 * utils prototype
*/
int						ft_strlen(const char *str);
char					*ft_strjoin(char const *s1, char const *s2);
int						get_next_line(int fd, char **line);
int						ft_atoi(const char *str);
void					ft_putstr_fd(char *str, int fd);
double					ft_atof(char *str);
void					ft_bzero(void *s, size_t n);

/*
 * engine prototype
*/
void					error(char *str);
void					init_check_param_obj(t_object *obj);
void					push_param_obj(int fd, t_object *obj);
void					push_param_ambient(char *line, t_object *obj);
void					push_param_cylinder(char *line, t_object *obj);
void					push_param_camera(char *line, t_object *obj);
void					push_param_display(char *line, t_object *obj);
void					push_param_light(char *line, t_object *obj);
void					push_param_plane(char *line, t_object *obj);
void					push_param_sphere(char *line, t_object *obj);
void					push_param_square(char *line, t_object *obj);
void					push_param_triangle(char *line, t_object *obj);

#endif