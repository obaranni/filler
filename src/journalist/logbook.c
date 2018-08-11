//
// Created by Oleksandr Barannik on 8/9/18.
//

#include "../../inc/filler.h"

void		log_priorities(t_filler *f)
{
	int		i;
	int		j;

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
	int		i;

	i = 0;
	while (i < MAP_Y) {
		fprintf(file, "%s\n", MAP_F[i]);
		i++;
	}
}

void		log_figure(t_filler *f)
{
	int		i;

	i = 0;
	while (i < FIGF_Y) {
		fprintf(file, "%s\n", FIGF_F[i]);
		i++;
	}
}

void		log_figure_short(t_filler *f)
{
	int		i;

	i = 0;
	while (i < FIGS_Y) {
		fprintf(file, "%s\n", FIGS_F[i]);
		i++;
	}
}

void		log_input(t_filler *f)
{
	int 	i;

	i = 0;
	while (f->input[i])
	{
		fprintf(file, "%s\n", f->input[i]);
		i++;
	}
}

void		logbook(t_filler *f, char *log_func)
{
	if (!ft_strcmp(log_func, "insert fig"))
		fprintf(file, "respond y %d    x %d\n", f->game.step_cord.x, f->game.step_cord.y);
	if (!ft_strcmp(log_func, "insert res"))
		fprintf(file, "respond y %d    x %d\n", f->game.step_cord.x, f->game.step_cord.y);
	if (!ft_strcmp(log_func, "input") || !ft_strcmp(log_func, "all"))
		log_input(f);
	if (!ft_strcmp(log_func, "prior") || !ft_strcmp(log_func, "all"))
		log_priorities(f);
	if (!ft_strcmp(log_func, "map") || !ft_strcmp(log_func, "all"))
		log_map(f);
	if (!ft_strcmp(log_func, "fig") || !ft_strcmp(log_func, "all"))
		log_figure(f);
	if (!ft_strcmp(log_func, "figs") || !ft_strcmp(log_func, "all"))
		log_figure_short(f);
	if (!ft_strcmp(log_func, "offset") || !ft_strcmp(log_func, "all"))
		fprintf(file, "offset x %d    y %d\n", FIG.offset.x, FIG.offset.y);
	if (!ft_strcmp(log_func, "respond") || !ft_strcmp(log_func, "all"))
		fprintf(file, "respond y %d    x %d\n", f->game.step_cord.x, f->game.step_cord.y);
}