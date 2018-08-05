//
// Created by Oleksandr Barannik on 8/2/18.
//

#include "../../inc/filler.h"

void             validate_players_part(t_filler *f, int *i)
{
    *i = 0;
}

void             validate_map_part(t_filler *f, int *i)
{
	char		*n;

	n = "zalupa";
    while (f->input[*i])
	{
		if ((n = ft_strstr(f->input[*i], "Plateau")))
			break;
		(*i)++;
	}
	int r;
	r = 0;
	while (!ft_isdigit(n[r]))
		r++;
    MAP_Y = ft_atoi(n + r);
	while (ft_isdigit(n[r]))
		r++;
    MAP_X = ft_atoi(n + r);

}

void             validate_figure_part(t_filler *f, int *i)
{
	char		*n;

	n = "zalupa";
	while (f->input[*i])
	{
		if ((n = ft_strstr(f->input[*i], "Piece")))
			break;
		(*i)++;
	}
	int r;
	r = 0;
	while (!ft_isdigit(n[r]))
		r++;
	FIGF_Y = ft_atoi(n + r);
	while (ft_isdigit(n[r]))
		r++;
	FIGF_X = ft_atoi(n + r);
}

int             validator(t_filler *f)
{
    int         i;

    i = 0;
    validate_players_part(f, &i);
    if (i == -1)
    {
        printf("Error in players part!");
        return (1);
    }
    validate_map_part(f, &i);
    if (i == -1)
    {
        printf("Error in map part!");
        return (1);
    }
    validate_figure_part(f, &i);
    if (i == -1)
    {
        printf("Error in figure part!");
        return (1);
    }
    return (0);
}
