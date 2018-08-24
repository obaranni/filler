/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:35:14 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 14:35:37 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"

int					is_in_field(t_filler *f, int i, int j)
{
	if (i + FIGS_Y > MAP_Y || j + FIGS_X > MAP_X)
		return (0);
	return (1);
}

int					is_intersection(t_filler *f, int i, int j)
{
	int				inter;
	int				j_base;
	int				x;
	int				y;

	y = 0;
	inter = 0;
	j_base = j;
	while (y < FIGS_Y)
	{
		x = 0;
		j = j_base;
		while (x < FIGS_X)
		{
			if (PRIOR[i][j] == MY && FIGS_F[y][x] == '*')
				inter++;
			if (PRIOR[i][j] == ENEMY && FIGS_F[y][x] == '*')
				return (0);
			x++;
			j++;
		}
		i++;
		y++;
	}
	return (inter);
}

void				calc_step_score(t_filler *f, int i, int j, t_fig_pos *pos)
{
	int				j_base;
	int				x;
	int				y;

	y = 0;
	pos->score = 0;
	pos->pos.x = j;
	pos->pos.y = i;
	j_base = j;
	while (y < FIGS_Y)
	{
		x = 0;
		j = j_base;
		while (x < FIGS_X)
		{
			if (PRIOR[i][j] > 0 && FIGS_F[y][x] == '*')
				pos->score += PRIOR[i][j];
			x++;
			j++;
		}
		i++;
		y++;
	}
}

int					insert(t_filler *f, int i, int j)
{
	int				k;

	if (is_in_field(f, i, j))
	{
		if (is_intersection(f, i, j) == 1)
		{
			k = 0;
			while (POSITOINS[k]->setted)
				k++;
			POSITOINS[k]->setted = 1;
			calc_step_score(f, i, j, POSITOINS[k]);
			return (1);
		}
		return (0);
	}
	return (0);
}

int					brute_force(t_filler *f)
{
	int				i;
	int				j;

	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			insert(f, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
