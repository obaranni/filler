#include "../../inc/filler.h"

void				init_cord(t_cord *cord)
{
	cord->x = -1;
	cord->y = -1;
}

int                 analizer(t_filler *f)
{
	init_cord(&f->step_cord);

	set_priorities(f);
	int i = 0;
	while (i < MAP_Y) {
		printf("%s\n", MAP[i]);
		i++;
	}
	i = 0;
	while (i < FIG_Y) {
		printf("%s\n", FIG[i]);
		i++;
	}
	return (1);
}