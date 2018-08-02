//
// Created by Oleksandr Barannik on 8/1/18.
//

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H
#include "../libft/inc/libft.h"
#include <stdio.h>


typedef struct          s_cord
{
    int                 x;
    int                 y;
	char 				*x_str;
	char 				*y_str;
}                       t_cord;

typedef struct          s_filler
{
    int                 graph_mode;
    char                **input;
    t_cord              step_cord;
}                       t_filler;
int                     get_next_line(const int fd, char **line);
int						visualizer(t_filler *f);
int						responder(t_filler *f);
int                     analizer(t_filler *f);
int						validator(t_filler *f);
int                     reader(t_filler *f);
#endif //FILLER_FILLER_H
