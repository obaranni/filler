#include "../inc/filler.h"

int             main(int argc, char **argv)
{
    t_filler    f;

    if (argc == 2 && ft_strcmp(argv[1], "3d") == 0)
        f.graph_mode = 1;
    else
        f.graph_mode = 0;

    while (reader(&f))
    {
        printf(")");
    }
}