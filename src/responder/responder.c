#include "../../inc/filler.h"

int             responder(t_filler *f)
{
	ft_putnbr(f->game.step_cord.y);
	ft_putchar(32);
	ft_putnbr(f->game.step_cord.x);
	ft_putchar(10);
	return (1);
}

