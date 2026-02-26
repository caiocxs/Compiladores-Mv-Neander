#include <ncurses.h>

int main()
{
    int ch;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    printw("Pressione alguma tecla e a mesma será exibida em negrito.\n");
    ch = getch();

    if(ch == KEY_F(1)){
        printw("A tecla f1 foi pressionada!");
    } else {
        printw("A tecla que voce pressionou foi: ");
        attron(A_BOLD);
        addch(ch);
        attroff(A_BOLD);
    }
    
    refresh();
    getch();
    endwin();

    return 0;
}