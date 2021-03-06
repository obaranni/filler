/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:45:31 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 14:45:35 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"

void			parse_figure(t_filler *f, int i)
{
	int			t;
	int			j;
	int			k;

	k = 0;
	while (k < FIGF_Y)
	{
		j = 0;
		t = 0;
		while (ft_strchr(FIGCHARS, f->input[i][j]) && t < FIGF_X)
		{
			FIGF_F[k][t] = f->input[i][j];
			j++;
			t++;
		}
		k++;
		i++;
	}
}

void			find_figure(t_filler *f, int *i)
{
	int			j;

	j = 0;
	while (f->input[*i])
	{
		if (ft_strstr(f->input[*i], "Piece"))
		{
			(*i) += 1;
			FIGF_F = (char **)malloc(sizeof(char*) * FIGF_Y);
			while (j < FIGF_Y)
			{
				FIGF_F[j] = (char*)malloc(sizeof(char) * FIGF_X);
				j++;
			}
			parse_figure(f, *i);
		}
		(*i)++;
	}
}
