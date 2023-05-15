#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "main.h"
#include "map.h"
#include "snake.h"

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
    init_keyboard();
    int t = prev_start();
    if (t == 0)
    {
        return 0;
    }

    Map *m = New_map();
    Snake *s = New_snake(m);
    refresh_map(m);

    while (1)
    {
        kbhit();
        printf("\n%d\n", readch());
    }
    close_keyboard();
    return 0;
}

void refresh_map(Map *m)
{
    int i, j;
    for (i = 0; i < row_map; i++)
    {
        for (j = 0; j < col_map; j++)
        {
            printf("%c", m->map[i][j]);
        }
    }
}

static struct termios initial_settings, new_settings;
static int peek_character = -1;

void init_keyboard()
{
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag |= ICANON;
    new_settings.c_lflag |= ECHO;
    new_settings.c_lflag |= ISIG;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
}

void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}

int kbhit()
{
    unsigned char ch;
    int nread;

    if (peek_character != -1)
        return 1;
    new_settings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0, &ch, 1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);
    if (nread == 1)
    {
        peek_character = ch;
        return 1;
    }
    return 0;
}

int readch()
{
    char ch;

    if (peek_character != -1)
    {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0, &ch, 1);
    return ch;
}
