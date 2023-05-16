#pragma once

struct food_position
{
    unsigned short top;
    unsigned short left;
};

struct food
{
    char icon;
    unsigned int count;
    struct food_position f_p;
};

typedef struct food Food;

Food *New_food();
void init_food(Food *f);
void generate_food_position();