/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:27:18 by thallot           #+#    #+#             */
/*   Updated: 2019/10/14 13:03:04 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/filler.h"
#include <stdio.h>

void	free_all(t_filler *filler)
{
	int i;

	i = -1;
	while (++i < filler->map_h)
	{
		ft_memdel((void **)&(filler)->map[i]);
		ft_memdel((void **)&(filler)->heatmap[i]);
	}
	ft_memdel((void **)&(filler->heatmap));
	ft_memdel((void **)&(filler->map));
}

void	free_tetri(t_tetri *tetri)
{
	if (tetri->tetri != NULL)
		ft_strdel(&(tetri)->tetri);
}

char	*strjoinfree(char *s1, char *s2, int opt)
{
	char *tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	if (opt >= 1)
		ft_strdel(&tmp);
	if (opt >= 2)
		ft_strdel(&s2);
	return (s1);
}
