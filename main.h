#pragma once

#include "snake.h"
#include "map.h"
#include "food.h"

Map *m;
Snake *s;
Food *f;

void init_pr();
int prev_start();
void refresh_map();

char getch();
void *keyboard_event(void *e);
