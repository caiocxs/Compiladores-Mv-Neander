#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    WINDOW *win;
    int height;
    int width;
    int pos_y;
    int pos_x;
    int color_id;
} NWindow;

NWindow* create_window(int height, int width, int y, int x);
void activate_colors(int color);
void destroy_window(NWindow* window);

#endif