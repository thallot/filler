/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:45:50 by thallot           #+#    #+#             */
/*   Updated: 2019/10/14 14:02:29 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../include/filler.h"

int		check_place(t_tetri *tetri, t_filler *filler, int i, int j)
{
	int nb_block;
	int heat;
	int y;
	int x;
	int connection;

	nb_block = 0;
	heat = 0;
	connection = 0;
	while (nb_block < tetri->nb_point)
	{
		y = i + tetri->point[nb_block][0] - tetri->origin[0];
		x = j + tetri->point[nb_block][1] - tetri->origin[1];
		if (x >= filler->map_w || y >= filler->map_h || x < 0
				|| y < 0 || connection > 1 || filler->heatmap[y][x] == -2)
			return (0);
		if (filler->heatmap[y][x] >= 0)
			heat += filler->heatmap[y][x];
		if (filler->heatmap[y][x] == -1)
			connection++;
		nb_block++;
	}
	heat = heat == 0 ? 1 : heat;
	return (connection == 1 ? heat : 0);
}

int		find_place(t_tetri *tetri, t_filler *filler)
{
	int i;
	int j;
	int x;
	int y;
	int heat;

	i = -1;
	x = INT_MIN;
	y = INT_MIN;
	heat = INT_MAX;
	while (++i < filler->map_h)
	{
		j = -1;
		while (++j < filler->map_w)
		{
			if ((filler->tmp = check_place(tetri, filler, i, j)) < heat
					&& filler->tmp > 0)
			{
				heat = filler->tmp;
				y = i - tetri->origin[0];
				x = j - tetri->origin[1];
			}
		}
	}
	return (print_result(filler, y, x));
}
