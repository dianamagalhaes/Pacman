#include <curses.h>

int main() {
    initscr();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    mvprintw(5, 5, "Este texto deve estar em amarelo");
    attroff(COLOR_PAIR(1));

    getch(); // Espera uma tecla para fechar
    endwin();
    return 0;
}
