#include "Maze.h"
#include <curses.h>  // PDCurses

Maze::Maze() : score(0) {
    // Inicializa o grid elemento a elemento para uma grid de 15x15

    std::vector<char> row1;
    row1.push_back('#'); row1.push_back('#'); row1.push_back('#'); row1.push_back('#'); row1.push_back('#');
    row1.push_back('#'); row1.push_back('#'); row1.push_back('#'); row1.push_back('#'); row1.push_back('#');
    row1.push_back('#'); row1.push_back('#'); row1.push_back('#'); row1.push_back('#'); row1.push_back('#');
    
    std::vector<char> row2;
    row2.push_back('#'); row2.push_back('.'); row2.push_back(' '); row2.push_back('.'); row2.push_back(' ');
    row2.push_back('.'); row2.push_back(' '); row2.push_back('.'); row2.push_back(' '); row2.push_back('.');
    row2.push_back(' '); row2.push_back('.'); row2.push_back(' '); row2.push_back('.'); row2.push_back('#');
    
    std::vector<char> row3;
    row3.push_back('#'); row3.push_back(' '); row3.push_back('#'); row3.push_back('#'); row3.push_back('#');
    row3.push_back(' '); row3.push_back('#'); row3.push_back('#'); row3.push_back('#'); row3.push_back(' ');
    row3.push_back('#'); row3.push_back('#'); row3.push_back('#'); row3.push_back(' '); row3.push_back('#');
    
    std::vector<char> row4;
    row4.push_back('#'); row4.push_back('.'); row4.push_back(' '); row4.push_back('.'); row4.push_back(' ');
    row4.push_back('.'); row4.push_back(' '); row4.push_back('.'); row4.push_back(' '); row4.push_back('.');
    row4.push_back(' '); row4.push_back('.'); row4.push_back(' '); row4.push_back('.'); row4.push_back('#');
    
    std::vector<char> row5;
    row5.push_back('#'); row5.push_back(' '); row5.push_back('#'); row5.push_back(' '); row5.push_back('#');
    row5.push_back(' '); row5.push_back('#'); row5.push_back(' '); row5.push_back('#'); row5.push_back(' ');
    row5.push_back('#'); row5.push_back(' '); row5.push_back('#'); row5.push_back(' '); row5.push_back('#');

    std::vector<char> row6;
    row6.push_back('#'); row6.push_back('.'); row6.push_back(' '); row6.push_back('.'); row6.push_back(' ');
    row6.push_back('.'); row6.push_back(' '); row6.push_back('.'); row6.push_back(' '); row6.push_back('.');
    row6.push_back(' '); row6.push_back('.'); row6.push_back(' '); row6.push_back('.'); row6.push_back('#');

    std::vector<char> row7;
    row7.push_back('#'); row7.push_back(' '); row7.push_back('#'); row7.push_back('#'); row7.push_back('#');
    row7.push_back(' '); row7.push_back('#'); row7.push_back('#'); row7.push_back('#'); row7.push_back(' ');
    row7.push_back('#'); row7.push_back('#'); row7.push_back('#'); row7.push_back(' '); row7.push_back('#');

    std::vector<char> row8;
    row8.push_back('#'); row8.push_back('.'); row8.push_back(' '); row8.push_back('.'); row8.push_back(' ');
    row8.push_back('.'); row8.push_back(' '); row8.push_back('.'); row8.push_back(' '); row8.push_back('.');
    row8.push_back(' '); row8.push_back('.'); row8.push_back(' '); row8.push_back('.'); row8.push_back('#');

    std::vector<char> row9;
    row9.push_back('#'); row9.push_back(' '); row9.push_back('#'); row9.push_back(' '); row9.push_back('#');
    row9.push_back(' '); row9.push_back('#'); row9.push_back(' '); row9.push_back('#'); row9.push_back(' ');
    row9.push_back('#'); row9.push_back(' '); row9.push_back('#'); row9.push_back(' '); row9.push_back('#');

    std::vector<char> row10;
    row10.push_back('#'); row10.push_back('.'); row10.push_back(' '); row10.push_back('.'); row10.push_back(' ');
    row10.push_back('.'); row10.push_back(' '); row10.push_back('.'); row10.push_back(' '); row10.push_back('.');
    row10.push_back(' '); row10.push_back('.'); row10.push_back(' '); row10.push_back('.'); row10.push_back('#');

    std::vector<char> row11;
    row11.push_back('#'); row11.push_back(' '); row11.push_back('#'); row11.push_back('#'); row11.push_back('#');
    row11.push_back(' '); row11.push_back('#'); row11.push_back('#'); row11.push_back('#'); row11.push_back(' ');
    row11.push_back('#'); row11.push_back('#'); row11.push_back('#'); row11.push_back(' '); row11.push_back('#');

    std::vector<char> row12;
    row12.push_back('#'); row12.push_back('.'); row12.push_back(' '); row12.push_back('.'); row12.push_back(' ');
    row12.push_back('.'); row12.push_back(' '); row12.push_back('.'); row12.push_back(' '); row12.push_back('.');
    row12.push_back(' '); row12.push_back('.'); row12.push_back(' '); row12.push_back('.'); row12.push_back('#');

    std::vector<char> row13;
    row13.push_back('#'); row13.push_back(' '); row13.push_back('#'); row13.push_back(' '); row13.push_back('#');
    row13.push_back(' '); row13.push_back('#'); row13.push_back(' '); row13.push_back('#'); row13.push_back(' ');
    row13.push_back('#'); row13.push_back(' '); row13.push_back('#'); row13.push_back(' '); row13.push_back('#');

    std::vector<char> row14;
    row14.push_back('#'); row14.push_back('.'); row14.push_back(' '); row14.push_back('.'); row14.push_back(' ');
    row14.push_back('.'); row14.push_back(' '); row14.push_back('.'); row14.push_back(' '); row14.push_back('.');
    row14.push_back(' '); row14.push_back('.'); row14.push_back(' '); row14.push_back('.'); row14.push_back('#');

    std::vector<char> row15;
    row15.push_back('#'); row15.push_back('#'); row15.push_back('#'); row15.push_back('#'); row15.push_back('#');
    row15.push_back('#'); row15.push_back('#'); row15.push_back('#'); row15.push_back('#'); row15.push_back('#');
    row15.push_back('#'); row15.push_back('#'); row15.push_back('#'); row15.push_back('#'); row15.push_back('#');

    // Adiciona cada linha ao grid
    grid.push_back(row1);
    grid.push_back(row2);
    grid.push_back(row3);
    grid.push_back(row4);
    grid.push_back(row5);
    grid.push_back(row6);
    grid.push_back(row7);
    grid.push_back(row8);
    grid.push_back(row9);
    grid.push_back(row10);
    grid.push_back(row11);
    grid.push_back(row12);
    grid.push_back(row13);
    grid.push_back(row14);
    grid.push_back(row15);
    addGhost(1, 1);
    addGhost(13, 13);
}

void Maze::addGhost(int x, int y) {
    ghosts.push_back(Ghost(x, y));
}

void Maze::updateGhosts() {
    for (auto& ghost : ghosts) {
        ghost.move(*this);  // Move cada fantasma aleatoriamente
    }
}


void Maze::draw() const {
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            char cell = grid[y][x];
            if (cell == '#') {
                attron(COLOR_PAIR(3));        // Paredes em azul
                mvaddch(y + 2, x, ACS_CKBOARD);  // Desenha paredes com um símbolo sólido
                attroff(COLOR_PAIR(3));
            } else if (cell == '.') {
                attron(COLOR_PAIR(2));        // Pontos em branco
                mvaddch(y + 2, x, ACS_BULLET);  // Desenha pontos como balas
                attroff(COLOR_PAIR(2));
            } else {
                mvaddch(y + 2, x, ' ');       // Espaços vazios
            }
        }
    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            char cell = grid[y][x];
            if (cell == '#') {
                attron(COLOR_PAIR(3));        // Paredes em azul
                mvaddch(y + 2, x, ACS_CKBOARD);  // Desenha paredes com um símbolo sólido
                attroff(COLOR_PAIR(3));
            } else if (cell == '.') {
                attron(COLOR_PAIR(2));        // Pontos em branco
                mvaddch(y + 2, x, ACS_BULLET);  // Desenha pontos como balas
                attroff(COLOR_PAIR(2));
            } else {
                mvaddch(y + 2, x, ' ');       // Espaços vazios
            }
        }
    }
    // Desenha os fantasmas
    for (const auto& ghost : ghosts) {
        attron(COLOR_PAIR(4));             // Cor dos fantasmas
        mvaddch(ghost.getY() + 2, ghost.getX(), 'G');  // Representa os fantasmas com 'G'
        attroff(COLOR_PAIR(4));
    }
    }

}

bool Maze::isWall(int x, int y) const {
    return grid[y][x] == '#';
}

bool Maze::collectDot(int x, int y) {
    if (grid[y][x] == '.') {
        grid[y][x] = ' ';
        score += 10;
        return true;
    }
    return false;
}
void Maze::updatePacManPosition(const PacMan& pacman) {
    int x = pacman.getX();
    int y = pacman.getY();
    char pacmanChar = pacman.getDirection();  // Obtém a direção atual do Pac-Man
    attron(COLOR_PAIR(1));                    // Ativa a cor amarela
    mvaddch(y + 2, x, pacmanChar);            // Desenha o Pac-Man com o "bonequinho" direcionado
    attroff(COLOR_PAIR(1));                   // Desativa a cor
}

bool Maze::isCollisionWithGhost(int pacmanX, int pacmanY) const {
    for (const auto& ghost : ghosts) {
        if (ghost.getX() == pacmanX && ghost.getY() == pacmanY) {
            return true;  // Colisão detectada
        }
    }
    return false;
}

int Maze::getScore() const {
    return score;
}
