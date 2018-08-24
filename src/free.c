/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:07:15 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 14:07:18 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void			free_input(t_filler *f)
{
	int			i;

	i = 0;
	while (f->input[i])
	{
		free(f->input[i]);
		i++;
	}
	free(f->input);
}

void			free_maps(t_filler *f)
{
	int			i;

	i = 0;
	while (i < MAP_Y)
	{
		free(MAP_F[i]);
		free(PRIOR[i]);
		i++;
	}
}

void			free_figs(t_filler *f)
{
	int			i;

	i = 0;
	while (i < FIGF_Y)
	{
		free(FIGF_F[i]);
		i++;
	}
	i = 0;
	while (i < FIGS_Y)
	{
		free(FIGS_F[i]);
		i++;
	}
}

void			free_all(t_filler *f)
{
	int			i;

	free_maps(f);
	free_figs(f);
	free_input(f);
	i = 0;
	while (i < ((MAP_X * MAP_Y) - 1))
	{
		free(f->game.figure.positions[i]);
		i++;
	}
	free(f->game.figure.positions);
	free(FIGS_F);
	free(PRIOR);
	free(MAP_F);
	free(FIGF_F);
}
