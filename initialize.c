/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 17:03:57 by aderby            #+#    #+#             */
/*   Updated: 2017/09/13 19:39:16 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	initialize_hooks(t_e *env)
{
	mlx_hook(env->win, 2, 0, key_hook, env);
	mlx_hook(env->win, 3, 0, keyr_hook, env);
	mlx_hook(env->win, 12, 0, expose_hook, env);
	mlx_hook(env->win, 17, 0, exit_hook, env);
}

t_img	*image_maker(void *mlx, int w, int h)
{
	t_img *i;

	i = (t_img *)ft_memalloc(sizeof(t_img));
	i->img = mlx_new_image(mlx, w, h);
	i->data = (int *)mlx_get_data_addr(i->img, &i->bbp, &i->size, &i->e);
	return (i);
}

void	initialize_ray_info(t_e *e)
{
	e->s_pos.x = 22.0;
	e->s_pos.y = 12.0;
	e->direction.x = -1.0;
	e->direction.y = 0.0;
	e->plane.x = 0.0;
	e->plane.y = 0.66;
}

t_e		*initialize_environment(void *mlx, int w, int h, char *title)
{
	t_e		*new;
	t_img	*img;

	new = (t_e *)ft_memalloc(sizeof(t_e));
	new->mlx = mlx;
	new->win = mlx_new_window(new->mlx, w, h, title);
	new->map = NULL;
	new->color = 0xFF00FF;
	new->img = NULL;
	img = image_maker(new->mlx, W, H);
	initialize_hooks(new);
	initialize_ray_info(new);
	img->size /= 4;
	new->img = img;
	return (new);
}
