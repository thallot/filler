/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:02:32 by thallot           #+#    #+#             */
/*   Updated: 2019/10/14 13:52:48 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/filler.h"
#define LIMIT 1000

void	place_heat(t_filler *filler, int i, int j)
{
	int heat;

	heat = 1;
	if (filler->heatmap[i][j] != -2)
		heat = filler->heatmap[i][j] + 1;
	if (i + 1 < filler->map_h && filler->heatmap[i + 1][j] == LIMIT)
		filler->heatmap[i + 1][j] = heat;
	if (i - 1 >= 0 && filler->heatmap[i - 1][j] == LIMIT)
		filler->heatmap[i - 1][j] = heat;
	if (j + 1 < filler->map_w && filler->heatmap[i][j + 1] == LIMIT)
		filler->heatmap[i][j + 1] = heat;
	if (j - 1 >= 0 && filler->heatmap[i][j - 1] == LIMIT)
		filler->heatmap[i][j - 1] = heat;
	if (j - 1 >= 0 && i - 1 >= 0 && filler->heatmap[i - 1][j - 1] == LIMIT)
		filler->heatmap[i - 1][j - 1] = heat;
	if (i + 1 < filler->map_h && j + 1 < filler->map_w
			&& filler->heatmap[i + 1][j + 1] == LIMIT)
		filler->heatmap[i + 1][j + 1] = heat;
	if (j - 1 >= 0 && i + 1 < filler->map_h
			&& filler->heatmap[i + 1][j - 1] == LIMIT)
		filler->heatmap[i + 1][j - 1] = heat;
	if (j + 1 < filler->map_w && i - 1 >= 0
			&& filler->heatmap[i - 1][j + 1] == LIMIT)
		filler->heatmap[i - 1][j + 1] = heat;
}

int		heatmap(t_filler *filler)
{
	int i;
	int j;
	int continue_loop;
	int cpt;

	i = 0;
	cpt = 0;
	continue_loop = 1;
	while (continue_loop && cpt++ < filler->map_h + filler->map_w)
	{
		continue_loop = 0;
		i = -1;
		while (++i < filler->map_h)
		{
			j = -1;
			while (++j < filler->map_w)
			{
				if (filler->heatmap[i][j] == LIMIT)
					continue_loop += filler->heatmap[i][j] == LIMIT ? 1 : 0;
				if (filler->heatmap[i][j] == -2 || filler->heatmap[i][j] >= 1)
					place_heat(filler, i, j);
			}
		}
	}
	return (1);
}

void	create_heatmap(t_filler *filler)
{
	int i;
	int j;
	int adv;

	i = -1;
	adv = 0;
	while (++i < filler->map_h)
	{
		j = -1;
		while (++j < filler->map_w)
		{
			if (filler->map[i][j] == '.')
				filler->heatmap[i][j] = LIMIT;
			if (filler->map[i][j] == filler->letter
					|| filler->map[i][j] == filler->letter + 32)
				filler->heatmap[i][j] = -1;
			if ((filler->map[i][j] == filler->adv
					|| filler->map[i][j] == filler->adv + 32) && ++adv)
				filler->heatmap[i][j] = -2;
		}
	}
	if (adv > filler->nb_block)
		filler->nb_block = adv;
	else
		filler->play = 0;
}
