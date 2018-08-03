#include "../../inc/filler.h"

void				calc_priority(t_filler *f, int i, int j)
{

}

void				set_priorities(t_filler *f)
{
	int				i;
	int 			j;

	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			calc_priority(f, i, j);
			j++;
		}
		i++;
	}
}

void				init_cord(t_cord *cord)
{
	cord->x = -1;
	cord->y = -1;
}

int                 analizer(t_filler *f)
{
	init_cord(&f->step_cord);

	set_priorities(f);
	return (1);
}