#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <termios.h>
#include <pthread.h>
#include "main.h"

void init_pr()
{
    printf("**********************************\n");
    printf("      start!\n");
    printf("**********************************\n");
}

int prev_start()
{
    system("clear");
    init_pr();
    char t;
    while (1)
    {
        printf("  输入 0结束 1开始\n");
        scanf("%c", &t);
        if (t == '0')
            return 0;
        else if (t == '1')
        {
            system("clear");
            return 1;
        }
        else
            system("clear");
    }
}

int main(int argc, char const *argv[])
{
    int t = prev_start();
    int keyboard_sock = -1;
    if (t == 0)
    {
        return 0;
    }

    s = New_snake();
    f = New_food();

    refresh_map();
    pthread_t newthread;
    if (pthread_create(&newthread, NULL, keyboard_event, (void *)&keyboard_sock) != 0)
    {
        perror("pthread_create");
    }
    while (1)
    {
        printf("--prev-/n");
        sleep(1);
        printf("---111-/n");
        snake_move(s);
    }

    return 0;
}

void refresh_map()
{
    system("clear");
    free(m);
    m = New_map();
    m->map[s->h_p.top][s->h_p.left] = s->head;
    unsigned int len = s->body_len;
    struct snake_position *cur = &(s->b_p);
    while (len)
    {
        m->map[cur->top][cur->left] = s->body;
        cur = cur->next;
        len--;
    }
    if (!f->count)
    {
        generate_food_position();
    }
    m->map[f->f_p.top][f->f_p.left] = f->icon;
    int i, j;
    for (i = 0; i < row_map; i++)
    {
        for (j = 0; j < col_map; j++)
        {
            printf("%c", m->map[i][j]);
        }
    }
}

void *keyboard_event(void *e)
{
    while (1)
    {
        int n = 1;
        char c = getch();
        switch (c)
        {
        case 'w':
            s->direction = '0';
            snake_move(s);
            break;
        case 's':
            s->direction = '1';
            snake_move(s);
            break;
        case 'a':
            s->direction = '2';
            snake_move(s);
            break;
        case 'd':
            s->direction = '3';
            snake_move(s);
            break;
        default:
            n = 0;
            break;
        }
        if (n)
        {
            // printf("top=%d left=%d\n", s->h_p.top, s->h_p.left);
            refresh_map(m);
        }
    }
}

char getch()
{
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return (buf);
}