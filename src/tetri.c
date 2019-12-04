/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:51:29 by thallot           #+#    #+#             */
/*   Updated: 2019/10/14 14:07:43 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../include/filler.h"

void	set_origin_tetri(t_tetri *tetri)
{
	int letter;
	int y;
	int x;

	letter = 0;
	y = 0;
	x = 0;
	while (tetri->tetri[letter] != '\0')
	{
		if (tetri->tetri[letter] == '*')
			break ;
		if (tetri->tetri[letter] == '\n')
		{
			y++;
			x = -1;
		}
		letter++;
		x++;
	}
	tetri->origin[0] = y;
	tetri->origin[1] = x;
}

void	set_point(t_tetri *tetri)
{
	int i;

	i = 0;
	while (tetri->tetri[i])
	{
		if (tetri->tetri[i] == '*')
			tetri->nb_point++;
		i++;
	}
}

void	set_coordinate(t_tetri *tetri)
{
	int point;
	int letter;
	int y;
	int x;

	letter = 0;
	y = 0;
	x = 0;
	point = 0;
	while (tetri->tetri[letter] != '\0')
	{
		if (tetri->tetri[letter] == '*')
		{
			tetri->point[point][0] = y;
			tetri->point[point][1] = x;
			point++;
		}
		if (tetri->tetri[letter] == '\n')
		{
			y++;
			x = -1;
		}
		letter++;
		x++;
	}
}
