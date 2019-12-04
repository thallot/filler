/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:43:45 by thallot           #+#    #+#             */
/*   Updated: 2019/10/14 13:54:33 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/filler.h"

int		get_player(t_filler *filler)
{
	char *line;

	if (get_next_line(0, &line, 1, 0) == -1)
	{
		ft_memdel((void **)&line);
		return (0);
	}
	filler->player = ft_atoi(&line[10]);
	if (filler->player != 1 && filler->player != 2)
	{
		ft_memdel((void **)&line);
		return (0);
	}
	filler->letter = filler->player == 1 ? 'O' : 'X';
	filler->adv = filler->player == 1 ? 'X' : 'O';
	ft_memdel((void **)&line);
	return (1);
}

int		get_map_size(t_filler *filler, char *line)
{
	int i;

	i = 0;
	line = ft_strchr(line, ' ') + 1;
	filler->map_h = ft_atoi(line);
	filler->map_w = ft_atoi(ft_strchr(line, ' '));
	if (!(filler->map = (char **)malloc(sizeof(char *) * filler->map_h)))
		return (0);
	if (!(filler->heatmap = (int **)malloc(sizeof(int *) * filler->map_h)))
		return (0);
	while (i < filler->map_h)
	{
		if (!(filler->map[i] = (char *)malloc(sizeof(char) * filler->map_w)))
			return (0);
		if (!(filler->heatmap[i] = (int *)malloc(sizeof(int) * filler->map_w)))
			return (0);
		i++;
	}
	filler->init_tab = 1;
	return (1);
}

int		get_map(t_filler *filler, char *line)
{
	int i;
	int j;

	i = -1;
	ft_strdel(&line);
	get_next_line(0, &line, 1, 0);
	ft_strdel(&line);
	while (++i < filler->map_h)
	{
		get_next_line(0, &line, 1, 0);
		j = -1;
		while (++j < filler->map_w)
		{
			if (filler->init_origin == 0 && line[j + 4] == filler->letter)
			{
				filler->origin[0] = i;
				filler->origin[1] = j;
				filler->init_origin = 1;
			}
			filler->map[i][j] = line[j + 4];
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

int		get_tetri(t_tetri *tetri, char *line)
{
	int nb_line;

	nb_line = 0;
	line = ft_strchr(line, ' ') + 1;
	tetri->height = ft_atoi(line);
	tetri->width = ft_atoi(ft_strchr(line, ' '));
	while (nb_line++ < tetri->height && get_next_line(0, &line, 1, 0))
	{
		tetri->tetri = strjoinfree(tetri->tetri, line, 1);
		tetri->tetri = strjoinfree(tetri->tetri, "\n", 1);
		ft_strdel(&line);
	}
	set_origin_tetri(tetri);
	set_point(tetri);
	set_coordinate(tetri);
	return (1);
}
