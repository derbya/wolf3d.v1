/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:25:16 by aderby            #+#    #+#             */
/*   Updated: 2017/09/14 15:03:52 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	translate_function_f(t_e *e)
{
	if (XMAP == 0)
		e->s_pos.x += e->direction.x * 0.5;
	if (YMAP == 0)
		e->s_pos.y += e->direction.y * 0.5;
}

void	translate_function_b(t_e *e)
{
	if (XXMAP == 0)
		e->s_pos.x -= e->direction.x * 0.5;
	if (YYMAP == 0)
		e->s_pos.y -= e->direction.y * 0.5;
}

void	translate_function_l(t_e *e)
{
	if (e->map[PMAP][PMAP2] == 0)
		e->s_pos.x += e->plane.x * 0.5;
	if (e->map[QMAP1][QMAP2] == 0)
		e->s_pos.y += e->plane.y * 0.5;
}

void	translate_function_r(t_e *e)
{
	if (e->map[PPMAP1][PPMAP2] == 0)
		e->s_pos.x -= e->plane.x * 0.5;
	if (e->map[QQMAP1][QQMAP2] == 0)
		e->s_pos.y -= e->plane.y * 0.5;
}
