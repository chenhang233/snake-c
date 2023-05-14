#include "snake.h"
#include <stdlib.h>

Snake *New_snake(Map *m)
{
    Snake *s = (Snake *)malloc(sizeof(Snake));
    init_snack(s);
    m->map[s->h_p.top][s->b_p.left] = s->head;
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

void init_snack(Snake *s)
{
    s->head = '@';
    s->h_p.left = 2;
    s->h_p.top = 3;
    s->h_p.next = NULL;

    s->body = '#';
    s->body_len = 2;
    s->b_p.left = 2;
    s->b_p.top = 4;
    struct snake_position next;
    next.left = 2;
    next.top = 5;
    s->b_p.next = malloc(sizeof(next));
    s->b_p.next = &next;
}