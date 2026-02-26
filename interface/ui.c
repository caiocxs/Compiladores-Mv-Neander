#include "ui.h"
#include "window.h"
#include "position.h"

int max_y, max_x;

int main()
{
    initscr(); // init main stdscr

    getmaxyx(stdscr, max_y, max_x);

    cbreak();    // unactivate line buffering, no need to enter
    noecho();    // hides user input
    curs_set(1); // 0 - hides, 1 - show, 2 - bold cursor
    refresh();
    keypad(stdscr, TRUE);

    if (has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support colors.");
        return 1;
    }

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    attron(COLOR_PAIR(1));

    refresh();

    // (lines, coluns, y, x)
    NWindow *w1 = create_window(10, 30, get_position_y(10), get_position_x(30));
    box(w1->win, '|', '-'); // (window, ch_y, ch_x), 0 - default
    mvwprintw(w1->win, 1, 2, "I'm the window 1!");

    wrefresh(w1->win);

    attroff(COLOR_PAIR(1));

    getch();
    destroy_window(w1);
    endwin();

    return 0;
}