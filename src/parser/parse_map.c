/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:46:17 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 14:46:19 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"

void			fill_priorities_map(t_filler *f)
{
	int			i;
	int			j;

	i = 0;
	PRIOR = (int**)malloc(sizeof(int*) * MAP_Y + 1);
	while (i < MAP_Y)
	{
		j = 0;
		PRIOR[i] = (int*)malloc(sizeof(int) * MAP_X + 1);
		while (j < MAP_X)
		{
			if (MAP_F[i][j] == '.')
				PRIOR[i][j] = DOT;
			else if (ft_strchr(f->game.en_player, MAP_F[i][j]))
				PRIOR[i][j] = ENEMY;
			else if (ft_strchr(f->game.my_player, MAP_F[i][j]))
				PRIOR[i][j] = MY;
			j++;
		}
		i++;
	}
}

void			parse_map(t_filler *f, int *i)
{
	int			t;
	int			j;
	int			k;

	k = 0;
	while (k < MAP_Y)
	{
		j = 0;
		t = 0;
		while (f->input[*i][j] && !ft_strchr(MAPCHARS, f->input[*i][j]))
			j++;
		while (ft_strchr(MAPCHARS, f->input[*i][j]) && t < MAP_X)
		{
			MAP_F[k][t] = f->input[*i][j];
			j++;
			t++;
		}
		k++;
		(*i)++;
	}
}

void			find_map(t_filler *f, int *i)
{
	int			j;

	while (f->input[*i])
	{
		if (ft_strstr(f->input[*i], "Plateau"))
		{
			(*i) += 2;
			j = 0;
			MAP_F = (char **)malloc(sizeof(char*) * MAP_Y);
			while (j < MAP_Y)
			{
				MAP_F[j] = (char*)malloc(sizeof(char) * MAP_X + 100);
				j++;
			}
			parse_map(f, i);
			return ;
		}
		(*i)++;
	}
}
