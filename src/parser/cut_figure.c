/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:43:45 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 14:43:47 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"

void			extreme_points(t_filler *f)
{
	int			i;
	int			j;

	FIG.min_y = FIGF_Y;
	FIG.min_x = FIGF_X;
	FIG.max_y = 0;
	FIG.max_x = 0;
	i = 0;
	while (i < FIGF_Y)
	{
		j = 0;
		while (j < FIGF_X)
		{
			if (FIGF_F[i][j] == '*' && i < FIG.min_y)
				FIG.min_y = i;
			if (FIGF_F[i][j] == '*' && i > FIG.max_y)
				FIG.max_y = i;
			if (FIGF_F[i][j] == '*' && j < FIG.min_x)
				FIG.min_x = j;
			if (FIGF_F[i][j] == '*' && j > FIG.max_x)
				FIG.max_x = j;
			j++;
		}
		i++;
	}
}

void			short_figure_creating(t_filler *f)
{
	int			i;
	int			j;

	FIGS_X = (FIG.max_x - FIG.min_x) + 1;
	FIGS_Y = (FIG.max_y - FIG.min_y) + 1;
	FIGS_F = (char**)malloc(sizeof(char*) * FIGS_Y);
	i = 0;
	while (i < FIGS_Y)
	{
		FIGS_F[i] = (char*)malloc(sizeof(char) * FIGS_X);
		i++;
	}
	i = 0;
	while (i < FIGF_Y)
	{
		j = 0;
		while (j < FIGF_X)
		{
			if (i >= FIG.min_y && i <= FIG.max_y
				&& j >= FIG.min_x && j <= FIG.max_x)
				FIGS_F[i - FIG.min_y][j - FIG.min_x] = FIGF_F[i][j];
			j++;
		}
		i++;
	}
}

void			set_offset(t_filler *f)
{
	FIG.offset.x = FIG.min_x;
	FIG.offset.y = FIG.min_y;
}

void			cut_figure(t_filler *f)
{
	extreme_points(f);
	set_offset(f);
	short_figure_creating(f);
}
