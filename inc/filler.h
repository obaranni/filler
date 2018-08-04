//
// Created by Oleksandr Barannik on 8/1/18.
//

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H
#include "../libft/inc/libft.h"
#include <stdio.h>
#define NAME "obaranni.filler"
#define MAPCHARS ".xXoO"
#define MAP		(f->game.map.field)
#define MAP_X	(f->game.map.field_size.x)
#define MAP_Y	(f->game.map.field_size.y)
#define FIGCHARS ".*"
#define FIG		(f->game.figure.field)
#define FIG_X	(f->game.figure.field_size.x)
#define FIG_Y	(f->game.figure.field_size.y)

typedef struct          s_cord
{
    int                 x;
    int                 y;
	char 				*x_str;
	char 				*y_str;
}                       t_cord;

typedef struct			s_field
{
	char 				**field;
	t_cord				field_size;
}						t_field;

typedef struct			s_game
{
	char 				*my_player;
	char 				*en_player;
	t_field				map;
	t_field				figure;
}						t_game;

typedef struct          s_filler
{
    int                 graph_mode;
    char                **input;
    t_cord              step_cord;
	t_game				game;
}                       t_filler;
int                     get_next_line(const int fd, char **line);

void					find_map(t_filler *f, int *i);
void					find_figure(t_filler *f, int *i);
int						parser(t_filler *f, int i);

int						visualizer(t_filler *f);

int						responder(t_filler *f);

void					set_priorities(t_filler *f);
int                     analizer(t_filler *f);

int						validator(t_filler *f);

int                     reader(t_filler *f);
#endif //FILLER_FILLER_H
