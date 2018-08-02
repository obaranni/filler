#include "../../inc/filler.h"

void				init_cord(t_cord *cord)
{
	cord->x = -1;
	cord->y = -1;
}

int                 analizer(t_filler *f)
{
	init_cord(&f->step_cord);
	return (1);
}