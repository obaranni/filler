/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 15:06:08 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 15:07:23 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/filler.h"

char			*find_word(char *str, char *word)
{
	return (ft_strstr(str, word));
}

void			validate_players_part(t_filler *f, int *i)
{
	*i = 0;
	(void)f;
}

void			validate_map_part(t_filler *f, int *i)
{
	char		*n;
	int			r;

	n = "zalupa";
	while (f->input[*i])
	{
		if ((n = find_word(f->input[*i], "Plateau")))
			break ;
		(*i)++;
	}
	r = 0;
	if (!n)
	{
		*i = -1;
		return ;
	}
	while (!ft_isdigit(n[r]))
		r++;
	MAP_Y = ft_atoi(n + r);
	while (ft_isdigit(n[r]))
		r++;
	MAP_X = ft_atoi(n + r);
}

void			validate_figure_part(t_filler *f, int *i)
{
	char		*n;
	int			r;

	n = "zalupa";
	while (f->input[*i])
	{
		if ((n = find_word(f->input[*i], "Piece")))
			break ;
		(*i)++;
	}
	if (!n)
	{
		*i = -1;
		return ;
	}
	r = 0;
	while (!ft_isdigit(n[r]))
		r++;
	FIGF_Y = ft_atoi(n + r);
	while (ft_isdigit(n[r]))
		r++;
	FIGF_X = ft_atoi(n + r);
}

int				validator(t_filler *f)
{
	int			i;

	i = 0;
	validate_players_part(f, &i);
	if (i == -1)
	{
		ft_putendl("Error in players part!");
		return (1);
	}
	validate_map_part(f, &i);
	if (i == -1)
	{
		ft_putendl("Error in map part!");
		return (1);
	}
	validate_figure_part(f, &i);
	if (i == -1)
	{
		ft_putendl("Error in figure part!");
		return (1);
	}
	return (0);
}
