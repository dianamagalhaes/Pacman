#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "PacMan.h"
#include "Ghost.h"

class Maze {
private:
    std::vector<std::vector<char> > grid;
    int score;
    std::vector<Ghost> ghosts;

public:
    Maze();
    void draw() const;
    bool isWall(int x, int y) const;
    bool collectDot(int x, int y);
    void updatePacManPosition(const PacMan& pacman);
    int getScore() const;
    
    void addGhost(int x, int y);
    void updateGhosts();
    bool isCollisionWithGhost(int pacmanX, int pacmanY) const;  // Nova função de verificação de colisão
};

#endif

