#include "snake.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

Snake *New_snake(Map *m)
{
    Snake *s = (Snake *)malloc(sizeof(Snake));
    init_snack(s);
    m->map[s->h_p.top][s->h_p.left] = s->head;
    unsigned int len = s->body_len;
    struct snake_position *cur = &(s->b_p);
    while (len)
    {
        m->map[cur->top][cur->left] = s->body;
        cur = cur->next;
        len--;
    }
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
    generate_snake_body(s);
}

void generate_snake_body(Snake *s)
{
    int p_m[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}};
    s->body = '#';
    s->body_len = 2;
    int b_len = s->body_len;
    int cur_rand = Random_int_range(0, 3);
    int s1 = *p_m[cur_rand];
    printf("%d\n", s1);
    printf("%d\n", *p_m[Random_int_range(0, 3)]);
    s->b_p.left += *p_m[cur_rand];
    s->b_p.top += *(p_m[cur_rand] + 1);
    b_len = 0;
    while (b_len)
    {
        struct snake_position next;
        next.left = 2;
        next.top = 5;
        s->b_p.next = malloc(sizeof(next));
        s->b_p.next = &next;
        b_len--;
    }
}