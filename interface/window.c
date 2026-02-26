#include "window.h"

NWindow *create_window(int height, int width, int y, int x)
{
    NWindow *new_win = (NWindow *)malloc(sizeof(NWindow));

    new_win->height = height;
    new_win->width = width;
    new_win->pos_y = y;
    new_win->pos_x = x;

    new_win->win = newwin(height, width, y, x);
    box(new_win->win, 0, 0);
    wrefresh(new_win->win);

    return new_win;
}

void destroy_window(NWindow *window)
{
    box(window->win, ' ', ' ');
    wrefresh(window->win);
    delwin(window->win);
    free(window);
}

void activate_colors(NWindow* w, int color, char y, char x)
{
    w->color_id = color;

    wattron(w->win, COLOR_PAIR(color));
    box(w->win, y, x);
}
