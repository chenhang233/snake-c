#include "snake.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int static p_m[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

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

void move(Snake *s)
{
    // 0 top 1 bottom 2 left 3 right
    switch (s->direction)
    {
    case '0':
        move_head(&s->h_p, p_m[0]);
        break;
    case '1':
        move_head(&s->h_p, p_m[1]);
        break;
    case '2':
        move_head(&s->h_p, p_m[2]);
        break;
    case '3':
        move_head(&s->h_p, p_m[3]);
        break;

    default:
        perror("move error");
        exit(1);
        break;
    }
}

void move_head(struct snake_position *h_p, int *m[2])
{
    printf("m[0]=%d\n", m[0]);
    printf("m[1]=%d\n", m[1]);
    // *h_p->left
}

void move_body()
{
}