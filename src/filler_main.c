#include "../inc/filler.h"

void 			free_input(t_filler *f)
{
	int 		i;

	i = 0;
	while (f->input[i])
	{
		free(f->input[i]);
		i++;
	}
	free(f->input);
	i = 0;
//	while (f->game->map)
}

void            game(t_filler *f)
{
	int 		i;

	i = 0;
	while (reader(f) && !i) /// && !i lishnee
    {
		if (validator(f))
		{
			free_input(f);
			break;
		}

		parser(f, i);
        analizer(f);

		f->step_cord.x = 0;
		f->step_cord.y = 0;

		responder(f);


        if (f->graph_mode)
            visualizer(f);
		free_input(f);
		i++;
    }
}

int             main(int argc, char **argv)
{
    t_filler    f;

    if (argc == 2 && ft_strcmp(argv[1], "3d") == 0)
        f.graph_mode = 1;
    else
        f.graph_mode = 0;
    game(&f);
}