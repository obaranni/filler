#include "../../inc/filler.h"

#include <unistd.h>
#include <fcntl.h>
int                 reader(t_filler *f)
{
    char            *buf;
    int             len;
    int             i;

    i = 0;
	f->input = 0;
	MAP = 0;
	f->input = (char **)malloc(sizeof(char*) * 500);
	int filedesc = open("../vm.txt", O_RDONLY);
    while (get_next_line(filedesc, &buf))
    {
        len = (int)ft_strlen(buf);
		(f->input[i]) = (char*)malloc(sizeof(char) * len);
        ft_strcpy((f->input[i]), buf);
        free(buf);
        i++;
    }
    f->input[i] = 0;
	close(filedesc);
    if (i)
        return (1);
    else
        return (0);
}