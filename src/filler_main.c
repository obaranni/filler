#include "../inc/filler.h"

#include <unistd.h>
#include <fcntl.h>


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
}

void			free_map(t_filler *f)
{
	int 		i;


	i = 0;
	////
//	while (i < MAP_Y)
//    {
//	   ft_putendl(MAP_F[i]);
//
//	    i++;
//    }
    ////
    i = 0;
	while (i < MAP_Y)
	{
        free(MAP_F[i]);
		free(PRIOR[i]);
		i++;
	}
	i = 0;
	while (i < FIGF_Y)
	{
		free(FIGF_F[i]);
		i++;
	}
	i = 0;
	while (i < FIGS_Y)
	{
		free(FIGS_F[i]);
		i++;
	}
	free(f->game.figure.positions);
	free(FIGS_F);
	free(PRIOR);
	free(MAP_F);
	free(FIGF_F);
}

void            game(t_filler *f)
{
	int 		i;
	int 		repeats;

	i = 0;
	repeats = -1;

	int filedesc;

//	filedesc = open("vm.txt", O_RDONLY);

	filedesc = 0;
	while (1)
    {
		if (reader(f, &repeats, filedesc))
		{
			if (validator(f))
			{
				free_input(f);
				break;
			}
			parser(f, i);
			analizer(f);
			logbook(f, "input");
			logbook(f, "prior");
			logbook(f, "respond");
			logbook(f, "offset");
			responder(f);
			if (f->graph_mode)
				visualizer(f);
			free_input(f);
			free_map(f);
		}
		else
			break ;

    }
	close(filedesc);
}

int             main(int argc, char **argv)
{
    t_filler    f;

	file = fopen("o.txt", "w");
	f.log_mode = 1;
    if (argc == 2 && ft_strcmp(argv[1], "3d") == 0)
        f.graph_mode = 1;
    else
        f.graph_mode = 0;
    game(&f);
//	while (1);
	return (0);
}