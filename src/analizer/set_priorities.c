#include "../../inc/filler.h"

int 				set_fanced_value(t_filler *f)
{
	int 			i;
	int 			j;

	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if (PRIOR[i][j] == 0)
			{
				if (MAP_X >= MAP_Y)
					PRIOR[i][j] = MAP_X;
				else
					PRIOR[i][j] = MAP_Y;
			}

			j++;
		}
		i++;
	}
	return (1);
}


int 				is_seted(t_filler *f)
{
	int 			i;
	int 			j;

	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			if (PRIOR[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

void		log_priorities2(t_filler *f)
{
	int		i;
	int		j;

	i = 0;
	while (i < MAP_Y)
	{
		j = 0;
		while (j < MAP_X)
		{
			printf("%2d ", f->game.priorities[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void				set_priorities(t_filler *f)
{
	int 			c;
	int				i;
	int 			j;
	int 			is_fence;

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
	while (!is_seted(f))
	{
		i = 0;
		is_fence = 1;
		while (i < MAP_Y) {
			j = 0;
			while (j < MAP_X)
			{
				if (PRIOR[i][j] == c)
				{
					is_fence = 0;
					calc_priority(f, i, j, c + 1);
				}
				j++;
			}
			i++;
		}
		if(is_fence)
			set_fanced_value(f);
		c++;
	}
}