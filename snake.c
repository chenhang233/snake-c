#include "snake.h"
#include <stdlib.h>

Snake *New_snake(Map *m)
{
    Snake *s = (Snake *)malloc(sizeof(Snake));
    init_snack(s);
    m->map[s->h_p.top][s->b_p.left] = s->head;
    unsigned int len = s->body_len;
    struct snake_position *cur = s->body;
    while (len)
    {
        m->map[] len--;
    }

    return s;
}

void init_snack(Snake *s)
{
    s->head = "@";
    s->h_p.left = 2;
    s->h_p.top = 3;
    s->h_p.next = NULL;

    s->body = "#";
    s->body_len = 1;
    s->b_p.left = 2;
    s->b_p.top = 4;
}