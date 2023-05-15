#pragma once

#include "map.h"

void init_pr();
int prev_start();
void refresh_map(Map *m);

void init_keyboard(void);
void close_keyboard(void);
int kbhit(void);
int readch(void);