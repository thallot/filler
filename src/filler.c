/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:24:41 by thallot           #+#    #+#             */
/*   Updated: 2019/10/23 13:32:06 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/filler.h"

int		print_result(t_filler *filler, int i, int j)
{
	if (i == INT_MIN && j == INT_MIN)
	{
		i = 0;
		j = 0;
		filler->play = 0;
	}
	ft_putnbr(i);
	ft_putchar(' ');
	ft_putnbr(j);
	ft_putchar('\n');
	return (filler->play);
}

void	init_filler(t_filler *filler)
{
	filler->player = 0;
	filler->error = 0;
	filler->map_h = 0;
	filler->map_w = 0;
	filler->letter = '0';
	filler->origin[0] = 0;
	filler->origin[1] = 0;
	filler->init_tab = 0;
	filler->init_origin = 0;
	filler->play = 0;
	filler->nb_block = 0;
}

void	init_tetri(t_tetri *tetri)
{
	tetri->tetri = ft_strnew(10);
	tetri->width = 0;
	tetri->height = 0;
	tetri->origin[0] = 0;
	tetri->origin[1] = 0;
	tetri->nb_point = 0;
	tetri->reel_h = 0;
	tetri->reel_w = 0;
}

void	filler_loop(t_filler *filler, t_tetri tetri)
{
	char	*line;
	int		res;

	while ((res = get_next_line(0, &line, 1, 0)) > -1)
	{
		if (line && !ft_strncmp(line, "Plateau", 7))
		{
			filler->play = 1;
			!filler->init_tab ? get_map_size(filler, line) : 0;
			get_map(filler, line);
			create_heatmap(filler);
			heatmap(filler);
		}
		else if (line && !ft_strncmp(line, "Piece", 5))
		{
			init_tetri(&tetri);
			get_tetri(&tetri, line);
			free_tetri(&tetri);
			ft_strdel(&line);
			if (find_place(&tetri, filler) == 0)
				return ;
		}
		else if (line)
			ft_strdel(&line);
	}
}

int		main(void)
{
	t_filler	filler;
	t_tetri		tetri;

	init_filler(&filler);
	init_tetri(&tetri);
	if (get_player(&filler))
		filler_loop(&filler, tetri);
	free_tetri(&tetri);
	free_all(&filler);
	return (0);
}
