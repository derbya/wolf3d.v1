/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:28:39 by aderby            #+#    #+#             */
/*   Updated: 2017/09/14 16:20:07 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	free_e(t_e *e)
{
	int i;
	int j;

	i = -1;
	j = -1;
	system("killall afplay");
	mlx_destroy_image(e->mlx, e->img->img);
	free(e->img);
	while (++i <= 199)
		free(e->map[i]);
	free(e->map);
}

int			key_hook(int keycode, t_e *e)
{
	if (keycode == 53)
	{
		free_e(e);
		exit(0);
	}
	if (keycode == 13 || keycode == 1)
		(keycode == 13) ? (e->button.w = 1)
			: (e->button.s = 1);
	if (keycode == 0 || keycode == 2)
		(keycode == 0) ? (e->button.a = 1)
			: (e->button.d = 1);
	if (keycode == 12 || keycode == 14)
		(keycode == 12) ? (e->button.q = 1)
			: (e->button.e = 1);
	if (keycode == 123 || keycode == 124)
		(keycode == 123) ? (e->button.e = 1)
			: (e->button.q = 1);
	return (keycode);
}

int			keyr_hook(int keycode, t_e *e)
{
	if (keycode == 13 || keycode == 1)
		(keycode == 13) ? (e->button.w = 0)
			: (e->button.s = 0);
	if (keycode == 0 || keycode == 2)
		(keycode == 0) ? (e->button.a = 0)
			: (e->button.d = 0);
	if (keycode == 12 || keycode == 14)
		(keycode == 12) ? (e->button.q = 0)
			: (e->button.e = 0);
	if (keycode == 123 || keycode == 124)
		(keycode == 123) ? (e->button.e = 0)
			: (e->button.q = 0);
	return (keycode);
}

int			expose_hook(t_e *e)
{
	e->draw = 1;
	return (0);
}

int			exit_hook(t_e *e)
{
	free_e(e);
	exit(0);
}
