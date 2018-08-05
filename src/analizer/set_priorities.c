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
			if (PRIOR[i][j] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void				calc_priority(t_filler *f, int i, int j, int c)
{
	int 			mx;
	int 			my;

	mx = MAP_X - 1;
	my = MAP_Y - 1;

	if (i - 1 >= 0 && PRIOR[i - 1][j] == 0)
		PRIOR[i - 1][j] = c;
	if (i + 1 <= my && PRIOR[i + 1][j] == 0)
		PRIOR[i + 1][j] = c;
	if (j - 1 >= 0 && PRIOR[i][j - 1] == 0)
		PRIOR[i][j - 1] = c;
	if (j + 1 <= mx && PRIOR[i][j + 1] == 0)
		PRIOR[i][j + 1] = c;
	if ((j - 1 >= 0 && i - 1 >= 0) && PRIOR[i - 1][j - 1] == 0)
		PRIOR[i - 1][j - 1] = c;
	if ((j + 1 <= mx && i - 1 >= 0) && PRIOR[i - 1][j + 1] == 0)
		PRIOR[i - 1][j + 1] = c;
	if ((j - 1 >= 0 && i + 1 <= my) && PRIOR[i + 1][j - 1] == 0)
		PRIOR[i + 1][j - 1] = c;
	if ((j + 1 <= mx && i + 1 <= my) && PRIOR[i + 1][j + 1] == 0)
		PRIOR[i + 1][j + 1] = c;
}

void				set_priorities(t_filler *f)
{
	int 			c;
	int				i;
	int 			j;

	i = 0;
	c = 1;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if (PRIOR[i][j] == ENEMY)
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
				if (PRIOR[i][j] == c)
					calc_priority(f, i, j, c + 1);
				j++;
			}
			i++;
		}
		c++;
	}
}