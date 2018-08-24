/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_priorities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:54:23 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 14:55:47 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"

int					set_fanced_value(t_filler *f)
{
	int				i;
	int				j;

	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if (PRIOR[i][j] == 0)
			{
				if (MAP_X >= MAP_Y)
					PRIOR[i][j] = MAP_X;
				else
					PRIOR[i][j] = MAP_Y;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int					is_seted(t_filler *f)
{
	int				i;
	int				j;

	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if (PRIOR[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void				calc_priority(t_filler *f, int i, int j, int c)
{
	int				mx;
	int				my;

	mx = MAP_X - 1;
	my = MAP_Y - 1;
	if (i - 1 >= 0 && PRIOR[i - 1][j] == 0)
		PRIOR[i - 1][j] = c;
	if (i + 1 <= my && PRIOR[i + 1][j] == 0)
		PRIOR[i + 1][j] = c;
	if (j - 1 >= 0 && PRIOR[i][j - 1] == 0)
		PRIOR[i][j - 1] = c;
	if (j + 1 <= mx && PRIOR[i][j + 1] == 0)
		PRIOR[i][j + 1] = c;
	if ((j - 1 >= 0 && i - 1 >= 0) && PRIOR[i - 1][j - 1] == 0)
		PRIOR[i - 1][j - 1] = c;
	if ((j + 1 <= mx && i - 1 >= 0) && PRIOR[i - 1][j + 1] == 0)
		PRIOR[i - 1][j + 1] = c;
	if ((j - 1 >= 0 && i + 1 <= my) && PRIOR[i + 1][j - 1] == 0)
		PRIOR[i + 1][j - 1] = c;
	if ((j + 1 <= mx && i + 1 <= my) && PRIOR[i + 1][j + 1] == 0)
		PRIOR[i + 1][j + 1] = c;
}

void				set_around_enemy(t_filler *f)
{
	int				i;
	int				j;

	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if (PRIOR[i][j] == ENEMY)
				calc_priority(f, i, j, 1);
			j++;
		}
		i++;
	}
}

void				set_priorities(t_filler *f)
{
	int				c;
	int				i;
	int				j;
	int				is_fence;

	set_around_enemy(f);
	c = 0;
	while (!is_seted(f) && ++c)
	{
		i = -1;
		is_fence = 1;
		while (++i < MAP_Y)
		{
			j = -1;
			while (++j < MAP_X)
			{
				if (PRIOR[i][j] == c)
					is_fence = 0;
				if (PRIOR[i][j] == c)
					calc_priority(f, i, j, c + 1);
			}
		}
		if (is_fence)
			set_fanced_value(f);
	}
}
