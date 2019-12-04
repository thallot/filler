/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:26:26 by thallot           #+#    #+#             */
/*   Updated: 2019/10/14 14:15:10 by thallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <string.h>
# include <limits.h>
# include "../libft/libft.h"

/*
******************************** Structures ************************************
*/

typedef struct		s_filler
{
	int		player;
	int		error;
	int		map_h;
	int		map_w;
	int		piece_h;
	int		piece_w;
	char	letter;
	char	adv;
	char	**map;
	int		**heatmap;
	int		origin[2];
	int		init_tab;
	int		init_origin;
	int		play;
	int		nb_block;
	int		tmp;
}					t_filler;

typedef struct		s_tetri
{
	int		width;
	int		height;
	char	*tetri;
	int		origin[2];
	int		point[20][2];
	int		nb_point;
	int		reel_h;
	int		reel_w;
}					t_tetri;

/*
******************************** Fonctions *************************************
*/

int					get_map_size(t_filler *filler, char *line);
int					get_player(t_filler *filler);
int					get_map(t_filler *filler, char *line);
int					get_tetri(t_tetri *tetri, char *line);

void				set_origin_tetri(t_tetri *tetri);
void				set_point(t_tetri *tetri);
void				set_coordinate(t_tetri *tetri);
void				set_reel_size(t_tetri *tetri);

void				free_all(t_filler *filler);
void				free_tetri(t_tetri *tetri);
char				*strjoinfree(char *s1, char *s2, int opt);

void				place_heat(t_filler *filler, int i, int j);
int					heatmap(t_filler *filler);
void				create_heatmap(t_filler *filler);

int					check_place(t_tetri *tetri, t_filler *filler, int i, int j);
int					check_place_rev(t_tetri *tetri, t_filler *filler,
					int i, int j);
int					find_place(t_tetri *tetri, t_filler *filler);

int					print_result(t_filler *filler, int i, int j);
#endif
