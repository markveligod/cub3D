/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <ck@ck.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:51:45 by ckakuna           #+#    #+#             */
/*   Updated: 2020/05/25 15:51:45 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <mlx.h>
# include "libft/libft.h"

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

typedef	struct	s_display
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_display;

typedef struct	s_link
{
	t_area		*area;
	t_display	*display;
}				t_link;

void			error(char *str);
char			*ft_strjoin_upd(char *s1, char *s2, int flag);
int				get_size_line(char *str);
void			get_map_file(int fd, t_link *param);
char			*clean_map_line(char *line);
int				is_map_flag(char c);


#endif