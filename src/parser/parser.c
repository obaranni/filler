#include "../../inc/filler.h"

void			find_player(t_filler *f)
{
	int 		i;

	i = 0;
	while (f->input[i])
	{
		if (ft_strstr(f->input[i], NAME))
		{
			i++;
			if (ft_strstr(f->input[i], "p1"))
			{
				f->game.my_player = "oO";
				f->game.en_player = "xX";
			}
			else
			{
				f->game.my_player = "xX";
				f->game.en_player = "oO";
			}
			return;
		}
		i++;
	}
}

int 			parser(t_filler *f, int i)
{
	if (!i)
		find_player(f);
	i = 0;
	find_map(f, &i);
	find_figure(f, &i);

	return (0);
}