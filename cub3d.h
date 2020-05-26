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
	char		**map;
	double		pos_x;
	double		pos_y;
	int			max_x;
	int			max_y;
	int			x;
	int			y;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	int			c_col;
	int			f_col;
}				area;

typedef	struct	s_display
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		camx;
	int			screenx;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
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
}				display;

typedef struct	s_link
{
	scene		*area;
	display		*dis;
}				link;

void			error(char *str)

#endif