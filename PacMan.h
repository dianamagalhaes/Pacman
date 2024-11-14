#ifndef PACMAN_H
#define PACMAN_H

class Maze;  // Declaração antecipada para evitar dependência circular

class PacMan {
private:
    int x, y;
    char direction;  // Nova variável para armazenar a direção atual

public:
    PacMan();
    void move(char input, const Maze& maze);
    int getX() const;
    int getY() const;
    char getDirection() const;  // Novo método para obter a direção
};

#endif
