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
    char direction;
    char body;
    struct snake_position b_p;
    unsigned int body_len;
};

typedef struct snake Snake;

void init_snack(Snake *s);
Snake *New_snake();
int Random_int_range(int min, int max);
void generate_snake_body(Snake *s);
void snake_move(Snake *s);

void snake_move_head(Snake *s, int m[2]);
void snake_move_body(struct snake_position *b_p, int m[2], int h_top, int h_left);