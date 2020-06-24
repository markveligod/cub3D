#ifndef CUB_H
# define CUB_H
# define BUFFER_SIZE 32

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>


/*
 * Prototype utils
*/
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strjoin(char const *s1, char const *s2);

/*
 * Prototype check
*/
int		check_filename(char *filename);

/*
 * Prototype get pararm obj
*/

/*
 * Prototype init object
*/



#endif