/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 14:43:05 by obaranni          #+#    #+#             */
/*   Updated: 2018/08/24 14:43:06 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void			stroke(t_filler *f, int i)
{
	parser(f, i);
	analizer(f);
	logbook(f, "input");
	logbook(f, "map");
	logbook(f, "prior");
	logbook(f, "fig");
	logbook(f, "respond");
	logbook(f, "offset");
	responder(f);
	if (f->graph_mode)
		visualize_game(f);
}

void			game(t_filler *f)
{
	int			i;
	int			filedesc;

	i = 0;
	filedesc = 0;
	while (1)
	{
		if (reader(f, filedesc))
		{
			if (validator(f))
			{
				free_input(f);
				break ;
			}
			stroke(f, i);
			free_all(f);
			i++;
		}
		else
			break ;
	}
}

int				main(int argc, char **argv)
{
	t_filler	f;

	f.file = fopen("log.txt", "w");
	f.log_mode = 1;
	if (argc == 2 && ft_strcmp(argv[1], "3d") == 0)
		f.graph_mode = 1;
	else
		f.graph_mode = 0;
	game(&f);
	return (0);
}
