#ifndef GHOST_H
#define GHOST_H

class Maze;  // Declaração antecipada para evitar dependência circular

class Ghost {
private:
    int x, y;

public:
    Ghost(int startX, int startY);
    void move(const Maze& maze);  // Movimenta-se aleatoriamente
    int getX() const;
    int getY() const;
};

#endif
