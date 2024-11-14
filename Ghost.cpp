#include "Ghost.h"
#include "Maze.h"
#include <cstdlib>  // Para rand()
#include <ctime>    // Para srand() e time()

Ghost::Ghost(int startX, int startY) : x(startX), y(startY) {
    std::srand(std::time(0));  // Inicializa o gerador de números aleatórios
}

void Ghost::move(const Maze& maze) {
    // Direções possíveis
    int directions[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };  // Cima, Baixo, Esquerda, Direita
    int randomIndex = std::rand() % 4;

    // Tenta mover-se numa direção aleatória
    int newX = x + directions[randomIndex][0];
    int newY = y + directions[randomIndex][1];

    // Verifica se a posição não é uma parede
    if (!maze.isWall(newX, newY)) {
        x = newX;
        y = newY;
    }
}

int Ghost::getX() const {
    return x;
}

int Ghost::getY() const {
    return y;
}
