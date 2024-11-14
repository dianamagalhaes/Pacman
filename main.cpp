#include <curses.h>
#include "PacMan.h"
#include "Maze.h"

// Função para perguntar ao jogador se ele quer jogar de novo
bool askPlayAgain() {
    clear();
    mvprintw(LINES / 2, COLS / 2 - 10, "Game Over! Quer jogar novamente? (s/n)");
    refresh();

    int ch;
    while (true) {
        ch = getch();
        if (ch == 's' || ch == 'S') {
            return true;  // Jogador quer jogar novamente
        } else if (ch == 'n' || ch == 'N') {
            return false; // Jogador quer sair
        }
    }
}

int main() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(200);

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK); // Pac-Man em amarelo
    init_pair(2, COLOR_WHITE, COLOR_BLACK);  // Pontos em branco
    init_pair(3, COLOR_BLUE, COLOR_BLACK);   // Paredes em azul
    init_pair(4, COLOR_RED, COLOR_BLACK);    // Fantasmas em vermelho

    bool playAgain = true;

    while (playAgain) {
        // Inicializa o Pac-Man e o labirinto a cada novo jogo
        PacMan pacman;
        Maze maze;

        int ch;
        bool gameOver = false;
        
        // Loop do jogo
        while (!gameOver) {
            clear();

            // Desenha o labirinto, pontos e fantasmas
            maze.draw();
            maze.updateGhosts();

            // Atualiza a posição e desenha o Pac-Man
            maze.updatePacManPosition(pacman);

            // Exibe a pontuação e instruções
            mvprintw(0, 0, "Pontuação: %d", maze.getScore());
            mvprintw(1, 0, "Movimenta o Pac-Man com as setas, 'q' para sair.");

            refresh();  // Atualiza o ecrã com todas as alterações

            // Lê o input do utilizador
            ch = getch();
            if (ch == 'q') {
                gameOver = true;
                break;
            }

            // Controla o movimento do Pac-Man
            char direction;
            if (ch == KEY_UP) direction = 'w';
            else if (ch == KEY_DOWN) direction = 's';
            else if (ch == KEY_LEFT) direction = 'a';
            else if (ch == KEY_RIGHT) direction = 'd';
            else continue;

            pacman.move(direction, maze);       // Move o Pac-Man
            maze.collectDot(pacman.getX(), pacman.getY());  // Coleta pontos

            // Verifica se houve colisão com um fantasma
            if (maze.isCollisionWithGhost(pacman.getX(), pacman.getY())) {
                clear();
                mvprintw(LINES / 2, COLS / 2 - 5, "Game Over!");  // Exibe "Game Over" no centro da tela
                refresh();
                napms(1000);  // Pausa por 2 segundos para que o jogador veja a mensagem
                gameOver = true;
            }
        }

        // Pergunta se o jogador quer jogar novamente
        playAgain = askPlayAgain();
    }

    endwin();  // Termina o modo curses
    return 0;
}
