#pragma once

#define row_map 25
#define col_map 55
#define mapSize row_map *col_map

struct map
{
    char map[row_map][col_map];
};

typedef struct map Map;

Map *New_map();
void init_map(Map *m);
