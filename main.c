#include <stdio.h>
#include <stdlib.h>
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
    int t = prev_start();
    if (t == 0)
    {
        return 0;
    }
    Map *m = New_map();
    Snake *s = New_snake(m);
    refresh_map(m);
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
