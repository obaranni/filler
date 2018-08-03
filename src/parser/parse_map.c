#include "../../inc/filler.h"

void			parse_map(t_filler *f, int *i)
{
	int			t;
	int			j;
	int			k;

	k = 0;
	while (k < MAP_Y)
	{
		j = 0;
		t = 0;
		while (f->input[*i][j] && !ft_strchr(MAPCHARS, f->input[*i][j]))
			j++;
		while (ft_strchr(MAPCHARS, f->input[*i][j]) && t < MAP_X)
		{
			MAP[k][t] = f->input[*i][j];
			j++;
			t++;
		}
		MAP[k][t] = 0;
		k++;
		(*i)++;
	}
}

void			find_map(t_filler *f, int *i)
{
	int 		j;

	j = 0;
	while (f->input[*i])
	{
		if (ft_strstr(f->input[*i], "Plateau"))
		{
			(*i) += 2;
			MAP = (char **)malloc(sizeof(char*) * MAP_Y);
			while (j < MAP_Y)
			{
				MAP[j] = (char*)malloc(sizeof(char) * MAP_X);
				j++;
			}
			parse_map(f, i);
			return ;
		}
		(*i)++;
	}
}