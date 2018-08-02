#include "../inc/filler.h"

void            game(t_filler *f)
{
    while (reader(f))
    {
        if (validator(f))
            break ;
        analizer(f);

		f->step_cord.x = 0;
		f->step_cord.y = 0;

		responder(f);


        if (f->graph_mode)
            visualizer(f);
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