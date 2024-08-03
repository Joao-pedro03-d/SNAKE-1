#include <raylib.h>
#include "snake.h"

void OpenStyleSnake() {
    typedef enum { SNAKE_1, SNAKE_2, SNAKE_3, VOLTAR_MENU} SnakeOption;
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Estilo Snake");

    SnakeOption currentOption = SNAKE_1;
    int totalOptionsSnakes = 4;

    while (!WindowShouldClose()) {
    
        if (IsKeyPressed(KEY_DOWN)) {
            currentOption = (currentOption + 1) % totalOptionsSnakes;
        }
        if (IsKeyPressed(KEY_UP)) {
            currentOption = (currentOption - 1 + totalOptionsSnakes) % totalOptionsSnakes;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            switch (currentOption) {
                case SNAKE_1:
                    break;
                case SNAKE_2:
                    break;
                case SNAKE_3:
                    break;
                case VOLTAR_MENU:
                    CloseWindow();
                    return;
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE); 

        DrawText("Escolha o Estilo Snake", (screenWidth - MeasureText("Escolha o Estilo Snake", 40)) / 2, 100, 40, DARKGRAY);
        DrawText("Estilo 1", (screenWidth - MeasureText("Estilo 1", 30)) / 2, 200, 30, currentOption == SNAKE_1 ? RED : DARKGRAY);
        DrawText("Estilo 2", (screenWidth - MeasureText("Estilo 2", 30)) / 2, 250, 30, currentOption == SNAKE_2 ? RED : DARKGRAY);
        DrawText("Estilo 3", (screenWidth - MeasureText("Estilo 3", 30)) / 2, 300, 30, currentOption == SNAKE_3 ? RED : DARKGRAY);
        DrawText("Voltar ao Menu", (screenWidth - MeasureText("Voltar ao Menu", 30)) / 2, 350, 30, currentOption == VOLTAR_MENU ? RED : DARKGRAY);

        EndDrawing();
    }
}