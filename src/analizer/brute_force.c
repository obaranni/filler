#include "../../inc/filler.h"

int 				is_in_field(t_filler *f, int i, int j)
{
	if (i + 1 + FIGS_Y > MAP_Y || j + 1 + FIGS_X > MAP_X)
		return (0);
	return (1);
}

int 				is_intersection(t_filler *f, int i, int j)
{
	int 			inter;
	int 			j_base;
	int 			x;
	int 			y;

	j_base = j;
	y = 0;
	inter = 0;
	while (y < FIGS_Y)
	{
		x = 0;
		j = j_base;
		while (x < FIGS_X)
		{
			if (PRIOR[i][j] == MY && FIGS_F[y][x] == '*')
				inter++;
			if (inter > 1)
				return (0);
			x++;
			j++;
		}
		i++;
		y++;
	}
	if (inter == 0)
		return (0);
	return (1);
}

void 				calc_step_score(t_filler *f, int i, int j, t_fig_pos *pos)
{
	int 			j_base;
	int 			x;
	int 			y;

	j_base = j;
	y = 0;
	pos->score = 0;
	pos->pos.x = i;
	pos->pos.y = j;
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
	int 			k;

	if (is_in_field(f, i, j))
	{
		if (is_intersection(f, i, j))
		{
			k = 0;
			while (POSITOINS[i]->setted)
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
	int 			i;
	int 			j;
	int 			inserted;

	inserted = 0;
	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if (insert(f, i, j))
				inserted = 1;
			j++;
		}
		i++;
	}
	return (inserted);
}