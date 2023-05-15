#pragma once

#include "map.h"

struct snake_position
{
    unsigned short top;
    unsigned short left;
    struct snake_position *next;
};

struct snake
{
    char head;
    struct snake_position h_p;
    char body;
    struct snake_position b_p;
    unsigned int body_len;
};

typedef struct snake Snake;

void init_snack(Snake *s);
Snake *New_snake(Map *m);
int Random_int_range(int min, int max);
void generate_snake_body(Snake *s);