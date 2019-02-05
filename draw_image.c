/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 01:35:07 by aderby            #+#    #+#             */
/*   Updated: 2017/09/14 14:30:15 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_line(int x, t_e *e, t_ray ray)
{
	int y;

	y = -1;
	while (++y <= ray.draw_start - 1)
		e->img->data[x + (y * (e->img->size))] = 0xBCBCBA;
	e->img->data[x + (y * (e->img->size))] = 0x0000000;
	while (++y < ray.draw_end)
		e->img->data[x + (y * (e->img->size))] = ray.color;
	e->img->data[x + (y * (e->img->size))] = 0x0000000;
	while (++y < H)
		e->img->data[x + (y * (e->img->size))] = 0x656565;
}

static void	wall_height(t_ray r, int x, t_e *e)
{
	if (r.side == 0)
		r.walld = (r.xmap - r.pos.x + (1 - r.step_x) / 2) / r.dir.x;
	else
		r.walld = (r.ymap - r.pos.y + (1 - r.step_y) / 2) / r.dir.y;
	r.line_height = (int)(H * 2 / r.walld);
	r.draw_start = (-r.line_height / 2) + (H / 2);
	if (r.draw_start < 0)
		r.draw_start = 0;
	r.draw_end = (r.line_height / 2) + (H / 2);
	if (r.draw_end >= H)
		r.draw_end = H - 1;
	if (r.side == 1)
		(r.dir.y < 0) ? (r.color = 0xFF9550)
			: (r.color = 0xAA0095);
	else
		(r.dir.x < 0) ? (r.color = 0x5095FF)
			: (r.color = 0xFFFF25);
	draw_line(x, e, r);
}

/*
** ┌────────────────────────────────────────────────┐
** │     DIGITAL      DIFFERENTIAL     ANALYSIS     │
** └────────────────────────────────────────────────┘
*/

static void	digital_d_analysis(t_ray ray, int x, t_e *e)
{
	while (ray.hit == 0)
	{
		if (ray.side_distance.x < ray.side_distance.y)
		{
			ray.side_distance.x += ray.delta.x;
			ray.xmap += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_distance.y += ray.delta.y;
			ray.ymap += ray.step_y;
			ray.side = 1;
		}
		if (e->map[ray.xmap][ray.ymap] > 0)
			ray.hit = 1;
	}
	wall_height(ray, x, e);
}

void		draw_image(t_e *e)
{
	int		x;
	t_ray	r;

	x = -1;
	while (++x < W)
	{
		r.camera = 2 * x / (double)W - 1;
		r.hit = 0;
		r.pos.x = e->s_pos.x;
		r.pos.y = e->s_pos.y;
		r.dir.x = e->direction.x + e->plane.x * r.camera;
		r.dir.y = e->direction.y + e->plane.y * r.camera;
		r.xmap = (int)r.pos.x;
		r.ymap = (int)r.pos.y;
		r.delta.x = sqrt(1 + (r.dir.y * r.dir.y) / (r.dir.x * r.dir.x));
		r.delta.y = sqrt(1 + (r.dir.x * r.dir.x) / (r.dir.y * r.dir.y));
		r.step_x = (r.dir.x < 0) ? -1 : 1;
		r.side_distance.x = ((r.dir.x < 0) ? (r.pos.x - r.xmap)
				: (r.xmap + 1.0 - r.pos.x)) * r.delta.x;
		r.step_y = (r.dir.y < 0) ? -1 : 1;
		r.side_distance.y = ((r.dir.y < 0) ? (r.pos.y - r.ymap)
				: (r.ymap + 1.0 - r.pos.y)) * r.delta.y;
		digital_d_analysis(r, x, e);
	}
}
