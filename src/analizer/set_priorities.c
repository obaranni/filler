#include "../../inc/filler.h"

int 				is_seted(t_filler *f)
{
	int 			i;
	int 			j;

	i = 0;
	j = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if (MAP[i][j] == '.')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void				calc_priority(t_filler *f, int i, int j, char c)
{
	int 			mx;
	int 			my;

	mx = MAP_X - 1;
	my = MAP_Y - 1;
	if (c == 'O')
		c++;
	if (i - 1 >= 0 && MAP[i - 1][j] == '.')
		MAP[i - 1][j] = c;
	if (i + 1 <= my && MAP[i + 1][j] == '.')
		MAP[i + 1][j] = c;
	if (j - 1 >= 0 && MAP[i][j - 1] == '.')
		MAP[i][j - 1] = c;
	if (j + 1 <= mx && MAP[i][j + 1] == '.')
		MAP[i][j + 1] = c;
	if ((j - 1 >= 0 && i - 1 >= 0) && MAP[i - 1][j - 1] == '.')
		MAP[i - 1][j - 1] = c;
	if ((j + 1 <= mx && i - 1 >= 0) && MAP[i - 1][j + 1] == '.')
		MAP[i - 1][j + 1] = c;
	if ((j - 1 >= 0 && i + 1 <= my) && MAP[i + 1][j - 1] == '.')
		MAP[i + 1][j - 1] = c;
	if ((j + 1 <= mx && i + 1 <= my) && MAP[i + 1][j + 1] == '.')
		MAP[i + 1][j + 1] = c;
}

void				set_priorities(t_filler *f)
{
	char 			c;
	int				i;
	int 			j;

	i = 0;
	c = 48;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if (ft_strchr(f->game.en_player, MAP[i][j]))
				calc_priority(f, i, j, c);
			j++;
		}
		i++;
	}
	while (is_seted(f))
	{
		i = 0;
		while (i < MAP_Y) {
			j = 0;
			while (j < MAP_X)
			{
				if (MAP[i][j] == c)
					calc_priority(f, i, j, c + 1);
				if (c == 'O')
					c++;
				j++;
			}
			i++;
		}
		c++;
	}
}