/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:58:50 by aderby            #+#    #+#             */
/*   Updated: 2017/09/14 15:53:20 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft/inc/libft.h"
# include "miniLibx/mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

/*
** ┌────────────────────────────────────────────────┐
** │ USEFUL        MACROS         ARE        USEFUL │
** └────────────────────────────────────────────────┘
*/

# define MW 200
# define MH 200
# define H 1000
# define W 1000

/*
** ┌────────────────────────────────────────────────┐
** │ NORM               SUCKS             EGGPLANTS │
** └────────────────────────────────────────────────┘
*/

# define EDIR e->direction
# define PLANE e->plane
# define BUT e->button
# define POS e->s_pos
# define XMAP e->map[(int)(e->s_pos.x + e->direction.x)][(int)e->s_pos.y]
# define YMAP e->map[(int)e->s_pos.x][(int)(e->s_pos.y + e->direction.y)]
# define XXMAP e->map[(int)(e->s_pos.x - e->direction.x)][(int)e->s_pos.y]
# define YYMAP e->map[(int)e->s_pos.x][(int)(e->s_pos.y - e->direction.y)]
# define PMAP (int)(POS.x + PLANE.x)
# define PMAP2 (int)e->s_pos.y
# define QMAP1 (int)e->s_pos.x
# define QMAP2 (int)(POS.y + PLANE.y)
# define PPMAP1 (int)(POS.x - PLANE.x)
# define PPMAP2 (int)e->s_pos.y
# define QQMAP1 (int)e->s_pos.x
# define QQMAP2 (int)(POS.y - PLANE.y)

/*
** ┌────────────────────────────────────────────────┐
** │                   STRUCTS                      │
** └────────────────────────────────────────────────┘
*/

typedef struct		s_img
{
	int				*data;
	int				bbp;
	int				size;
	int				e;
	void			*img;
}					t_img;

typedef struct		s_coord
{
	double			x;
	double			y;
}					t_coord;

typedef struct		s_ray
{
	int				xmap;
	int				ymap;
	int				color;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				hit;
	int				side;
	double			walld;
	double			step_x;
	double			step_y;
	double			camera;
	t_coord			pos;
	t_coord			dir;
	t_coord			side_distance;
	t_coord			delta;

}					t_ray;
typedef struct		s_button
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				q;
	int				e;
}					t_button;

typedef struct		s_e
{
	int				color;
	int				draw;
	int				**map;
	void			*mlx;
	void			*win;
	t_img			*img;
	t_coord			s_pos;
	t_coord			plane;
	t_coord			direction;
	t_button		button;
}					t_e;

/*
** ┌────────────────────────────────────────────────┐
** │                  PROTOTYPES                    │
** └────────────────────────────────────────────────┘
*/

int					key_hook(int keycode, t_e *e);
int					keyr_hook(int keycode, t_e *e);
int					expose_hook(t_e *e);
int					exit_hook(t_e *e);
int					**fill_map(void);
int					loop_hook(t_e *e);
t_e					*initialize_environment(void *m, int w, int h, char *t);
void				initialize_hooks(t_e *env);
void				draw_image(t_e *e);
void				translate_function_f(t_e *e);
void				translate_function_b(t_e *e);
void				translate_function_l(t_e *e);
void				translate_function_r(t_e *e);
void				rotation_function_r(t_e *e);
void				rotation_function_l(t_e *e);
void				fill_grid(t_img *i, int x, int y, int color);
t_img				*image_maker(void *mlx, int w, int h);

#endif
