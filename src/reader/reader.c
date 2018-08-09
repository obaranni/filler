#include "../../inc/filler.h"

int					loop(t_filler *f, int *i, int filedesc)
{
	char            *buf;
	int             len;
	int 			to_end;


	while (get_next_line(filedesc, &buf) > 0)
	{
		len = (int)ft_strlen(buf);
		f->input[*i] = (char*)malloc(sizeof(char) * len);
		ft_strcpy(f->input[*i], buf);
		if (ft_strncmp(buf, "Piece", 4) == 0)
		{
			free(buf);
			validate_figure_part(f, i);
			to_end = FIGF_Y;
			(*i)++;
			while (to_end > 0)
			{
				get_next_line(filedesc, &buf);
				free(buf);
				len = (int) ft_strlen(buf);
				f->input[*i] = (char *) malloc(sizeof(char) * len);
				ft_strcpy(f->input[*i], buf);
				to_end--;
				(*i)++;
			}
			return (1);
		}
		free(buf);
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
	i = 0;
	while (f->input[i])
	{
		fprintf(file, "%s\n", f->input[i]);
		i++;
	}
	return (res);
}