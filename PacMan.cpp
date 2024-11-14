#include "PacMan.h"
#include "Maze.h"

PacMan::PacMan() : x(1), y(1), direction('>') {}

void PacMan::move(char input, const Maze& maze) {
    int newX = x, newY = y;

    if (input == 'w') {
        newY -= 1;
        direction = '^';  // Cima
    } else if (input == 's') {
        newY += 1;
        direction = 'v';  // Baixo
    } else if (input == 'a') {
        newX -= 1;
        direction = '<';  // Esquerda
    } else if (input == 'd') {
        newX += 1;
        direction = '>';  // Direita
    }

    // Movimento se não houver parede
    if (!maze.isWall(newX, newY)) {
        x = newX;
        y = newY;
    }
}

int PacMan::getX() const { return x; }
int PacMan::getY() const { return y; }
char PacMan::getDirection() const { return direction; }
