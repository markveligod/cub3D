#ifndef MINIRT_H
# define MINIRT_H
# define BUFFER_SIZE 32
# define KEY_ESC 53

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <mlx.h>

#include <stdio.h>

typedef struct			s_check
{
	short int			display;
	short int			ambient;
	short int			camera;
	short int			light;
	short int			sphere;
	short int			plane;
	short int			square;
	short int			cylinder;
	short int			triangle;
}						t_check;


typedef struct			s_display
{
	short int			x;
	short int			y;
}						t_display;

typedef struct			s_ambient
{
	double				coef;
	short int			red;
	short int			green;
	short int			blue;
}						t_ambient;

typedef struct			s_camera
{
	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				normal_x;
	double				normal_y;
	double				normal_z;
	short int			fov;
	struct s_camera		*next;
}						t_camera;

typedef struct			s_light
{
	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				brightness;
	short int			red;
	short int			green;
	short int			blue;
	struct s_light		*next;
}						t_light;

typedef struct			s_sphere
{
	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				diameter;
	short int			red;
	short int			green;
	short int			blue;
	struct s_sphere		*next;
}						t_sphere;

typedef struct			s_plane
{
	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				normal_x;
	double				normal_y;
	double				normal_z;
	short int			red;
	short int			green;
	short int			blue;
	struct s_plane		*next;
}						t_plane;

typedef struct			s_square
{
	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				normal_x;
	double				normal_y;
	double				normal_z;
	double				size;
	short int			red;
	short int			green;
	short int			blue;
	struct s_square		*next;
}						t_square;

typedef struct			s_cylinder
{
	double				pos_x;
	double				pos_y;
	double				pos_z;
	double				normal_x;
	double				normal_y;
	double				normal_z;
	double				diameter;
	double				height;
	short int			red;
	short int			green;
	short int			blue;
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct			s_triangle
{
	double				pos_x_dot1;
	double				pos_y_dot1;
	double				pos_z_dot1;
	double				pos_x_dot2;
	double				pos_y_dot2;
	double				pos_z_dot2;
	double				pos_x_dot3;
	double				pos_y_dot3;
	double				pos_z_dot3;
	short int			red;
	short int			green;
	short int			blue;
	struct s_triangle	*next;
}						t_triangle;

typedef struct			s_mlxrt
{
	void				*mlx_ptr;
	void				*win_ptr;
}						t_mlxrt;

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
	t_mlxrt				*rt;
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
void					check_fail_rgb(short int check, char *str);
int						check_next_param(char ch, char *line, int flag);
void					check_normal(double check, char *str);
void					get_pos(char *line, double *pos_x, double *pos_y, double *pos_z);
void					get_normal(char *line, double *normal_x, double *normal_y, double *normal_z, char *name);
void					get_rgb(char *line, short int *red, short int *green, short int *blue, char *name);
void					init_mlx_param_obj(t_object *obj);
void					start_rt(t_object *obj);
int						close_win();

#endif