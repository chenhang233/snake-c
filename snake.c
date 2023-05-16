#include "snake.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int static p_m[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

Snake *New_snake()
{
    Snake *s = (Snake *)malloc(sizeof(Snake));
    init_snack(s);
    return s;
}

int Random_int_range(int min, int max)
{
    time_t t;
    srand((unsigned)time(&t));
    int r = rand() % max;
    while (r < min)
    {
        r = rand() % max;
    }
    return r;
}

void init_snack(Snake *s)
{
    int row = Random_int_range(1, row_map - 2);
    int col = Random_int_range(1, col_map - 2);
    printf("snake head position: row: %d col: %d \n", row, col);

    s->head = '@';
    s->h_p.left = col;
    s->h_p.top = row;
    s->h_p.next = NULL;
    s->direction = '0';
    generate_snake_body(s);
}

void generate_snake_body(Snake *s)
{
    s->body = '#';
    s->body_len = 1;
    // int b_len = s->body_len;
    int cur_rand = Random_int_range(0, 3);

    s->b_p.left = *(p_m[cur_rand] + 1) + s->h_p.left;
    s->b_p.top += *p_m[cur_rand] + s->h_p.top;
    s->b_p.next = NULL;
}

void snake_move(Snake *s)
{
    // 0 top 1 bottom 2 left 3 right
    switch (s->direction)
    {
    case '0':
        snake_move_head(&s->h_p, p_m[0]);
        snake_move_body(&s->b_p, p_m[0]);
        break;
    case '1':
        snake_move_head(&s->h_p, p_m[1]);
        snake_move_body(&s->b_p, p_m[1]);
        break;
    case '2':
        snake_move_head(&s->h_p, p_m[2]);
        snake_move_body(&s->b_p, p_m[2]);
        break;
    case '3':
        snake_move_head(&s->h_p, p_m[3]);
        snake_move_body(&s->b_p, p_m[3]);
        break;

    default:
        break;
    }
}

void snake_move_head(struct snake_position *h_p, int m[2])
{
    h_p->top += m[0];
    h_p->left += m[1];
}

void snake_move_body(struct snake_position *b_p, int m[2])
{
    struct snake_position *cur = b_p;
    while (cur != NULL)
    {
        cur->top += m[0];
        cur->left += m[1];
        cur = cur->next;
    }
}