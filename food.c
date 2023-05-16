#include <stdio.h>
#include <stdlib.h>
#include "food.h"
#include "snake.h"
#include "main.h"

Food *New_food()
{
    Food *f = (Food *)malloc(sizeof(Food));
    init_food(f);
    return f;
}

void init_food(Food *f)
{
    f->icon = '*';
    f->count = 0;
};

void generate_food_position()
{
    sleep(1);
    int row = Random_int_range(1, row_map - 2);
    int col = Random_int_range(1, col_map - 2);
    int score = s->body_len + 1;
    char cur_icon = m->map[row][col];
    while (cur_icon != ' ' && score < mapSize)
    {
        sleep(1);
        row = Random_int_range(1, row_map - 2);
        col = Random_int_range(1, col_map - 2);
    }
    f->f_p.top = row;
    f->f_p.left = col;
    f->count++;
}