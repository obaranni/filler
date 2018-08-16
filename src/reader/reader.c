#include "../../inc/filler.h"

int					loop(t_filler *f, int *i, int filedesc)
{
	char            *buf;
	int             len;
	int 			to_end;


	while (get_next_line(filedesc, &buf) > 0)
	{
		len = (int)ft_strlen(buf);

		f->input[*i] = (char*)malloc(sizeof(char) * len + 1);
//		printf("%s\n", buf);
		ft_strcpy(f->input[*i], buf);
//		if (ft_strcmp(f->input[*i], buf) != 0)
//			printf("\n\n\nALLERT\n\n\n");
		if (ft_strncmp(buf, "Piece", 5) == 0)
		{
			ft_strdel(&buf);
			validate_figure_part(f, i);
			to_end = FIGF_Y;
			(*i)++;
			while (to_end > 0)
			{
				get_next_line(filedesc, &buf);
				len = (int) ft_strlen(buf);
//                if (ft_strlen(buf) != FIGF_Y - 1)
//                    printf("ALLERT\n");
				f->input[*i] = (char *) malloc(sizeof(char) * len + 1);
//				printf("%s\n", buf);
				ft_strcpy(f->input[*i], buf);
//				if (ft_strcmp(f->input[*i], buf) != 0)
//					printf("ALLERT\n");
				to_end--;
                ft_strdel(&buf);
				(*i)++;
			}
			return (1);
		}
		ft_strdel(&buf);
		(*i)++;
	}
	return (0);
}

int                 reader(t_filler *f, int *repeats, int fd)
{
    int             i;
	int 			res;

    i = 0;
	f->input = 0;
	MAP_F = 0;
	f->input = (char **)malloc(sizeof(char*) * 200);
	res = loop(f, &i, fd);
    f->input[i] = 0;
	return (res);
}