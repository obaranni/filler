//
// Created by Oleksandr Barannik on 8/1/18.
//

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H
#include "../libft/libft.h"
#include <stdio.h>

typedef struct          s_filler {
    int                 graph_mode;

}                       t_filler;

int                     reader(t_filler *f);
#endif //FILLER_FILLER_H
