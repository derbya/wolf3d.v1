/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 18:19:55 by aderby            #+#    #+#             */
/*   Updated: 2017/09/13 18:29:02 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rotation_function_l(t_e *e)
{
	double	odx;
	double	opx;

	odx = e->direction.x;
	EDIR.x = EDIR.x * cos(0.05) - EDIR.y * sin(0.05);
	EDIR.y = odx * sin(0.05) + EDIR.y * cos(0.05);
	opx = PLANE.x;
	PLANE.x = PLANE.x * cos(0.05) - PLANE.y * sin(0.05);
	PLANE.y = opx * sin(0.05) + PLANE.y * cos(0.05);
}

void	rotation_function_r(t_e *e)
{
	double	odx;
	double	opx;

	odx = e->direction.x;
	EDIR.x = EDIR.x * cos(-0.05) - EDIR.y * sin(-0.05);
	EDIR.y = odx * sin(-0.05) + EDIR.y * cos(-0.05);
	opx = PLANE.x;
	PLANE.x = PLANE.x * cos(-0.05) - PLANE.y * sin(-0.05);
	PLANE.y = opx * sin(-0.05) + PLANE.y * cos(-0.05);
}
