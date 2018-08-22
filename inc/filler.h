//
// Created by Oleksandr Barannik on 8/1/18.
//

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H
#include "../libft/inc/libft.h"
#include <stdio.h>
#include "../minilibx_macos/mlx.h"
#define NAME "obaranni.filler"
#define MAPCHARS ".xXoO"
#define WIN_W   1600
#define WIN_H   900
#define IMG_M_W 1000
#define IMG_LR_W 300
#define MAP_F	(f->game.map.field)
#define MAP_X	(f->game.map.field_size.x)
#define MAP_Y	(f->game.map.field_size.y)
#define FIGCHARS ".*"
#define POSITOINS (f->game.figure.positions)
#define	FIG		(f->game.figure)
#define FIGF	(f->game.figure.figure_full)
#define FIGF_F	(f->game.figure.figure_full.field)
#define FIGF_X	(f->game.figure.figure_full.field_size.x)
#define FIGF_Y	(f->game.figure.figure_full.field_size.y)
#define FIGS	(f->game.figure.figure_short)
#define FIGS_F	(f->game.figure.figure_short.field)
#define FIGS_X	(f->game.figure.figure_short.field_size.x)
#define FIGS_Y	(f->game.figure.figure_short.field_size.y)
#define PRIOR	(f->game.priorities)
#define ENEMY (-2)
#define MY (-1)
#define DOT (0)

FILE *file;

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

typedef struct			s_fig_pos
{
	t_cord				pos;
	int 				score;
	int					setted;
}						t_fig_pos;

typedef	struct			s_figure
{
	int 				min_x;
	int 				min_y;
	int 				max_x;
	int 				max_y;
	t_fig_pos			**positions;
	t_field				figure_full;
	t_field				figure_short;
	t_cord				offset;
}						t_figure;

typedef struct          s_win
{
    void                *mlx;
    void                *win;
    void                *img_r;
    void                *img_m;
    void                *img_l;
    char                *data_r;
    char                *data_m;
    char                *data_l;
    int                 size_line;
    int                 bpp;
    int                 endian;
}                       t_win;

typedef struct			s_game
{
	char 				*my_player;
	char 				*en_player;
	int 				**priorities;
	t_field				map;
	t_figure			figure;
	t_cord              step_cord;
}						t_game;

typedef struct          s_filler
{
    int                 graph_mode;
	int                 log_mode;
    char                **input;
    t_win               win;
	t_game				game;
}                       t_filler;
int                     get_next_line(const int fd, char **line);

void					logbook(t_filler *f, char *log_func);

void					cut_figure(t_filler *f);
void					fill_priorities_map(t_filler *f);
void					find_map(t_filler *f, int *i);
void					find_figure(t_filler *f, int *i);
int						parser(t_filler *f, int i);

void                    init_window(t_filler *f);
void                    visualize_players(t_filler *f);
int						visualize_game(t_filler *f);

int						responder(t_filler *f);

int						brute_force(t_filler *f);
void					set_priorities(t_filler *f);
int                     analizer(t_filler *f);

void					validate_figure_part(t_filler *f, int *i);
int						validator(t_filler *f);

int                     reader(t_filler *f, int fd);
#endif //FILLER_FILLER_H
