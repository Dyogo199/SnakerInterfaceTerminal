#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define WIDTH 40
#define HEIGHT 20
#define LOG_FILE "highscore.txt"

typedef struct {
    int x, y;
} Point;

typedef enum {
    UP, DOWN, LEFT, RIGHT
} Direction;

// Variáveis globais
Point snake[100];
int snake_length;
Point food;
Point obstacles[20];
int num_obstacles;
Direction dir;
int score = 0;
int high_score = 0;
int delay = 200; // Tempo entre os frames em ms
int game_over = 0;

// Função para desenhar as bordas, cobra, comida e obstáculos
void draw() {
    clear();

    // Bordas
    for (int i = 0; i < WIDTH; i++) mvaddch(0, i, '#');
    for (int i = 0; i < WIDTH; i++) mvaddch(HEIGHT - 1, i, '#');
    for (int i = 0; i < HEIGHT; i++) mvaddch(i, 0, '#');
    for (int i = 0; i < HEIGHT; i++) mvaddch(i, WIDTH - 1, '#');

    // Obstáculos
    for (int i = 0; i < num_obstacles; i++) mvaddch(obstacles[i].y, obstacles[i].x, 'X');

    // Cobra
    for (int i = 0; i < snake_length; i++) mvaddch(snake[i].y, snake[i].x, 'O');

    // Comida
    mvaddch(food.y, food.x, '@');

    // Pontuação e recorde
    mvprintw(0, WIDTH + 2, "Pontuação: %d", score);
    mvprintw(1, WIDTH + 2, "Recorde: %d", high_score);

    refresh();
}

// Função para inicializar a cobra e a comida
void initialize_game() {
    snake_length = 1;
    snake[0].x = WIDTH / 2;
    snake[0].y = HEIGHT / 2;
    dir = RIGHT;

    // Gerar comida
    food.x = rand() % (WIDTH - 2) + 1;
    food.y = rand() % (HEIGHT - 2) + 1;

    // Carregar recorde
    FILE *file = fopen(LOG_FILE, "r");
    if (file) {
        fscanf(file, "%d", &high_score);
        fclose(file);
    }

    // Gerar obstáculos
    num_obstacles = 5;
    for (int i = 0; i < num_obstacles; i++) {
        obstacles[i].x = rand() % (WIDTH - 2) + 1;
        obstacles[i].y = rand() % (HEIGHT - 2) + 1;
    }
}

// Função para processar entradas do jogador
void input() {
    int ch = getch();
    switch (ch) {
        case KEY_UP:    if (dir != DOWN) dir = UP; break;
        case KEY_DOWN:  if (dir != UP) dir = DOWN; break;
        case KEY_LEFT:  if (dir != RIGHT) dir = LEFT; break;
        case KEY_RIGHT: if (dir != LEFT) dir = RIGHT; break;
        case 'q':       game_over = 1; break;
    }
}

// Função para mover a cobra
void move_snake() {
    // Nova cabeça
    Point new_head = snake[0];
    switch (dir) {
        case UP:    new_head.y--; break;
        case DOWN:  new_head.y++; break;
        case LEFT:  new_head.x--; break;
        case RIGHT: new_head.x++; break;
    }

    // Verificar colisão com bordas
    if (new_head.x <= 0 || new_head.x >= WIDTH - 1 || new_head.y <= 0 || new_head.y >= HEIGHT - 1) {
        game_over = 1;
        return;
    }

    // Verificar colisão com o próprio corpo
    for (int i = 0; i < snake_length; i++) {
        if (new_head.x == snake[i].x && new_head.y == snake[i].y) {
            game_over = 1;
            return;
        }
    }

    // Verificar colisão com obstáculos
    for (int i = 0; i < num_obstacles; i++) {
        if (new_head.x == obstacles[i].x && new_head.y == obstacles[i].y) {
            game_over = 1;
            return;
        }
    }

    // Verificar se comeu a comida
    if (new_head.x == food.x && new_head.y == food.y) {
        score += 10;
        if (score > high_score) high_score = score;
        snake_length++;
        food.x = rand() % (WIDTH - 2) + 1;
        food.y = rand() % (HEIGHT - 2) + 1;
    }

    // Mover corpo
    for (int i = snake_length - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    snake[0] = new_head;
}

// Função para salvar o recorde
void save_high_score() {
    FILE *file = fopen(LOG_FILE, "w");
    if (file) {
        fprintf(file, "%d", high_score);
        fclose(file);
    }
}

// Função para escolher dificuldade
void choose_difficulty() {
    clear();
    mvprintw(HEIGHT / 2 - 1, WIDTH / 2 - 10, "Escolha a dificuldade:");
    mvprintw(HEIGHT / 2, WIDTH / 2 - 10, "1. Fácil");
    mvprintw(HEIGHT / 2 + 1, WIDTH / 2 - 10, "2. Médio");
    mvprintw(HEIGHT / 2 + 2, WIDTH / 2 - 10, "3. Difícil");
    refresh();

    int ch;
    while (1) {
        ch = getch();
        if (ch == '1') {
            delay = 300;
            break;
        } else if (ch == '2') {
            delay = 200;
            break;
        } else if (ch == '3') {
            delay = 100;
            break;
        }
    }
}

// Finalizar o jogo
void end_game() {
    save_high_score();
    clear();
    mvprintw(HEIGHT / 2, WIDTH / 2 - 5, "GAME OVER!");
    mvprintw(HEIGHT / 2 + 1, WIDTH / 2 - 7, "Pontuação Final: %d", score);
    refresh();
    getch();
    endwin();
}

int main() {
    srand(time(NULL));
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);

    choose_difficulty();
    initialize_game();

    while (!game_over) {
        draw();
        input();
        move_snake();
        napms(delay);
    }

    end_game();
    return 0;
}
