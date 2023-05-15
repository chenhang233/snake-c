#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Map *New_map()
{
    Map *m = (Map *)malloc(sizeof(Map));
    init_map(m);
    return m;
}

void init_map(Map *m)
{
    // memset(m->map, 0, sizeof(m->map));
    int i, j;
    for (i = 0; i < row_map; i++)
    {
        for (j = 0; j < col_map; j++)
        {
            if (j == col_map - 1)
            {
                m->map[i][j] = '\n';
            }
            else if (i == 0 || i == row_map - 1 || j == 0 || j == col_map - 2)
            {
                m->map[i][j] = 'X';
            }
            else
            {
                m->map[i][j] = ' ';
            };
        }
    }
}