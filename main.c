/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:57:20 by aderby            #+#    #+#             */
/*   Updated: 2017/09/14 16:22:20 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(void)
{
	t_e		*e;
	void	*mlx;

	mlx = mlx_init();
	e = initialize_environment(mlx, W, H, "Wolf3d");
	e->map = fill_map();
	draw_image(e);
	system("afplay song.mp3 &");
	mlx_loop_hook(mlx, loop_hook, e);
	mlx_loop(mlx);
}
