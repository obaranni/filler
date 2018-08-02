#include "../../inc/filler.h"

int                 reader(t_filler *f)
{
    char            *buf;
    int             len;
    int             i;

    i = 0;
	f->input = 0;
	f->input = (char **)malloc(sizeof(char*) * 500);
    while (get_next_line(0, &buf))
    {
        len = (int)ft_strlen(buf);
		(f->input[i]) = (char*)malloc(sizeof(char) * len);
        ft_strcpy((f->input[i]), buf);
        free(buf);
        i++;
    }
    if (i)
        return (1);
    else
        return (0);
}