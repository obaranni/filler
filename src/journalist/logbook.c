//
// Created by Oleksandr Barannik on 8/9/18.
//

#include "../../inc/filler.h"

void		log_priorities(t_filler *f)
{
	int i;
	int j;


	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			fprintf(file, "%2d ", f->game.priorities[i][j]);
			j++;
		}
		fprintf(file, "\n");
		i++;
	}
}

void		log_map(t_filler *f)
{
	int i;

	while (i < MAP_Y) {
		fprintf(file, "%s\n", MAP_F[i]);
		i++;
	}
}

void		log_figure(t_filler *f)
{
	int i;

	i = 0;
	while (i < FIGF_Y) {
		fprintf(file, "%s\n", FIGF_F[i]);
		i++;
	}
}

void		log_figure_short(t_filler *f)
{
	int i;

	i = 0;
	while (i < FIGS_Y) {
		fprintf(file, "%s\n", FIGS_F[i]);
		i++;
	}
}

void		log(t_filler *f, char *log_func)
{
	if (!ft_strcmp(log_func, "prior") || !ft_strcmp(log_func, "all"))
		log_priorities(f);
	else if (!ft_strcmp(log_func, "map") || !ft_strcmp(log_func, "all"))
		log_map(f);
	else if (!ft_strcmp(log_func, "fig") || !ft_strcmp(log_func, "all"))
		log_figure(f);
	else if (!ft_strcmp(log_func, "figs") || !ft_strcmp(log_func, "all"))
		log_figure_short(f);
	else if (!ft_strcmp(log_func, "offset") || !ft_strcmp(log_func, "all"))
		fprintf(file, "offset x %d    y %d\n", FIG.offset.x, FIG.offset.y);
}