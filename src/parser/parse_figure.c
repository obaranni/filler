#include "../../inc/filler.h"

void			parse_figure(t_filler *f, int i)
{
	int			t;
	int			j;
	int			k;

	k = 0;
	while (k < FIG_Y)
	{
		j = 0;
		t = 0;
		while (ft_strchr(FIGCHARS, f->input[i][j]) && t < FIG_X)
		{
			FIG[k][t] = f->input[i][j];
			j++;
			t++;
		}
		FIG[k][t] = 0;
		k++;
		i++;
	}
}

void			find_figure(t_filler *f, int *i)
{
	int 		j;

	j = 0;
	while (f->input[*i])
	{
		if (ft_strstr(f->input[*i], "Piece"))
		{
			(*i) += 1;
			FIG = (char **)malloc(sizeof(char*) * FIG_Y);
			while (j < FIG_Y)
			{
				FIG[j] = (char*)malloc(sizeof(char) * FIG_X);
				j++;
			}
			parse_figure(f, *i);
		}
		(*i)++;
	}
}