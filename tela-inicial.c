#include <raylib.h>
#include "snake.h" 

typedef enum { MENU_PLAY, MENU_MAPS, MENU_STYLE_SNAKE, MENU_INFO, MENU_EXIT } MenuOption;

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "SNAKE");

    MenuOption currentOption = MENU_PLAY;
    int totalOptions = 5;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            currentOption = (currentOption + 1) % totalOptions;
        }
        if (IsKeyPressed(KEY_UP)) {
            currentOption = (currentOption - 1 + totalOptions) % totalOptions;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            switch (currentOption) {
                case MENU_PLAY:
                    break;
                case MENU_MAPS:
                    break;
                case MENU_STYLE_SNAKE:
                     OpenStyleSnake();
                    break;
                case MENU_INFO:
                    break;
                case MENU_EXIT:
                    CloseWindow();
                    break;
            }
        }

        BeginDrawing();
        ClearBackground(BLUE);

        DrawText("Menu Principal", (screenWidth - MeasureText("Menu Principal", 40)) / 2, 100, 40, DARKGRAY);
        DrawText("Jogar", (screenWidth - MeasureText("Jogar", 30)) / 2, 200, 30, currentOption == MENU_PLAY ? RED : DARKGRAY);
        DrawText("Mapas", (screenWidth - MeasureText("Mapas", 30)) / 2, 250, 30, currentOption == MENU_MAPS ? RED : DARKGRAY);
        DrawText("Estilo Snake", (screenWidth - MeasureText("Estilo Snake", 30)) / 2, 300, 30, currentOption == MENU_STYLE_SNAKE ? RED : DARKGRAY);
        DrawText("Informações", (screenWidth - MeasureText("Informações", 30)) / 2, 350, 30, currentOption == MENU_INFO ? RED : DARKGRAY);
        DrawText("Sair", (screenWidth - MeasureText("Sair", 20)) / 2, 400, 30, currentOption == MENU_EXIT ? RED : DARKGRAY);

        EndDrawing();
    }
    return 0;
}
