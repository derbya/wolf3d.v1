/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:47:42 by aderby            #+#    #+#             */
/*   Updated: 2017/09/14 15:49:06 by aderby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	add_walls(int **map)
{
	int i;

	i = 1;
	while (++i < 198)
		map[2][i] = 1;
	i = 5;
	while (++i < 100)
		map[i][6] = 1;
	i = 100;
	while (++i < 195)
		map[i][9] = 1;
	i = 94;
	while (++i < 155)
		map[i][24] = 1;
	i = 190;
	while (--i > 9)
		map[66][i] = 1;
	i = 20;
	while (++i < 180)
		map[i][i] = 1;
}

int			**fill_map(void)
{
	int	**map;
	int	i;

	i = -1;
	map = (int **)ft_memalloc(sizeof(int *) * 200);
	while (++i < 200)
		map[i] = (int *)ft_memalloc(sizeof(int) * 200);
	i = -1;
	while (++i < 200)
		map[i][0] = 1;
	while (i-- > 0)
		map[199][i - 1] = 1;
	while (++i < 200)
		map[i][199] = 1;
	while (--i >= 0)
		map[0][i] = 1;
	add_walls(map);
	return (map);
}
