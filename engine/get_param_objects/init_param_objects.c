/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckakuna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:26:42 by ckakuna           #+#    #+#             */
/*   Updated: 2020/06/30 11:26:48 by ckakuna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub.h"

/*
** Function for initializing the parameter structure
*/

void		init_param_objects(t_ptr *ptr)
{
	if (!(ptr->p = (t_paramobj *)malloc(sizeof(t_paramobj))))
		error("struct param doesn't allocate in memory (*_*)");
}
