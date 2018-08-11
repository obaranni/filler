#include "../../inc/filler.h"

void				set_cord(t_cord *cord, int x, int y)
{
	cord->x = x;
	cord->y = y;
}

void				create_pos_array(t_filler *f)
{
	int 			i;

	i = 0;
	POSITOINS = (t_fig_pos**)malloc(sizeof(t_fig_pos*) * ((MAP_X * MAP_Y) - 1));
	POSITOINS[0] = NULL;
	while (i < (MAP_X * MAP_Y) - 1)
	{
		POSITOINS[i] = (t_fig_pos*)malloc(sizeof(t_fig_pos));
		POSITOINS[i]->setted = 0;
		i++;
	}
}

t_fig_pos			*get_a_better_score(t_fig_pos **array)
{
	t_fig_pos		*better;
	int 			i;

	i = 0;
	if (array[i]->setted)
		better = array[i++];
	else
		return (NULL);
	while (array[i]->setted)
	{
		if (better && better->score > array[i]->score)
			better = array[i];
		i++;
	}
	return (better);
}

int                 analizer(t_filler *f)
{
	t_fig_pos		*best_pos;

	set_cord(&(f->game.step_cord), -1, -1);
	create_pos_array(f);
	set_priorities(f);
	brute_force(f);
	best_pos = get_a_better_score(POSITOINS);
	if (best_pos)
		set_cord(&(f->game.step_cord), best_pos->pos.x -
									   (f->game.figure.offset.x), best_pos->pos.y
																  - (f->game.figure.offset.y));
	return (1);
}