#include "../../inc/filler.h"

void			cords_to_str(t_cord *cord)
{
	cord->x_str = ft_itoa(cord->x);
	cord->y_str = ft_itoa(cord->y);
}

void 			cords_free(t_cord *cord)
{
	free(cord->x_str);
	free(cord->y_str);
}

void			send_respond(t_cord *cord)
{
	write(1, cord->x_str, ft_strlen(cord->x_str));
	write(1, " ", 1);
	write(1, cord->y_str, ft_strlen(cord->y_str));
	write(1, "\n", 1);
}

int             responder(t_filler *f)
{
	cords_to_str(&f->step_cord);
	send_respond(&f->step_cord);
	cords_free(&f->step_cord);
	return (1);
}
