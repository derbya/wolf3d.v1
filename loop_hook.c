/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:02:47 by aderby            #+#    #+#             */
/*   Updated: 2017/09/14 14:30:50 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		loop_hook(t_e *e)
{
	if (BUT.w == 1 || BUT.s == 1 || BUT.a == 1 || BUT.d == 1 || BUT.q
			|| BUT.e == 1)
	{
		if (e->button.w == 1 || e->button.s == 1)
			(BUT.w == 1) ? translate_function_f(e) : translate_function_b(e);
		if (e->button.a == 1 || e->button.d == 1)
			(BUT.a == 1) ? translate_function_r(e) : translate_function_l(e);
		if (BUT.q == 1 || BUT.e == 1)
			(BUT.q == 1) ? rotation_function_r(e) : rotation_function_l(e);
		e->draw = 1;
	}
	if (e->draw == 1)
	{
		e->draw = 0;
		draw_image(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
	}
	return (1);
}
