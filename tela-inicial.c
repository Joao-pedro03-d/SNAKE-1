#include <raylib.h>
#include <stdlib.h>
#include <stdio.h> 
#include "snake.h"

// TELA SELEÇÃO DE ESTILO COBRA
void openStyleSnake() {
    typedef enum { SNAKE_1, SNAKE_2, SNAKE_3, VOLTAR_MENU } SnakeOption;
    const int largura = 800;
    const int altura = 800;
    InitWindow(largura, altura, "Estilo Snake");
    SetTargetFPS(60);

    SnakeOption optionSelect = SNAKE_1; 
    int totalOptionsSnakes = 4; 

    Vector2 snakePositions[3] = {
        {(largura - 80) / 2 - 100, 250},  
        {(largura - 80) / 2, 250},        
        {(largura - 80) / 2 + 100, 250} 
    };

    bool selectingSnake = true;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_ENTER)) {
            if (selectingSnake) {
            } else {
                CloseWindow();
                return;
            }
        }

        if (selectingSnake) {
            if (IsKeyPressed(KEY_RIGHT)) {
                optionSelect = (optionSelect + 1) % totalOptionsSnakes; 
            }
            if (IsKeyPressed(KEY_LEFT)) {
                optionSelect = (optionSelect - 1 + totalOptionsSnakes) % totalOptionsSnakes; 
            }
            if (IsKeyPressed(KEY_DOWN)) {
                selectingSnake = false; 
            }
        } else {
            if (IsKeyPressed(KEY_UP)) {
                selectingSnake = true; 
            }
        }

        BeginDrawing();
        ClearBackground(BLUE); 

        DrawText("Escolha o Estilo da Snake", (largura - MeasureText("Escolha o Estilo da Snake", 40)) / 2, 100, 40, BLACK);
        
        for (int i = 0; i < totalOptionsSnakes - 1; i++) { 
            Color color = (optionSelect == i) ? BLACK : WHITE; 
            DrawRectangleV(snakePositions[i], (Vector2){80, 40}, color); 
        }

        Color backColor = selectingSnake ? DARKGRAY : RED;
        DrawText("VOLTAR", (largura - MeasureText("VOLTAR", 30)) / 2, 350, 30, backColor);

        EndDrawing();
    }
}


//TELA SELEÇÃO DE MAPAS
void openMapSelect() {
    typedef enum {MAP_1, MAP_2, MAP_3, MAP_4, VOLTAR} MapOption;

    const int largura = 800;
    const int altura = 800;
    InitWindow(largura, altura, "Escolha o mapa");
    SetTargetFPS(60);

    MapOption optionSelect = MAP_1; 
    int totalOptionsMaps = 5; 

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            optionSelect = (optionSelect + 1) % totalOptionsMaps;
        }
        if (IsKeyPressed(KEY_UP)) {
            optionSelect = (optionSelect - 1 + totalOptionsMaps) % totalOptionsMaps;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            switch (optionSelect) {
                case MAP_1:
                    break;
                case MAP_2:
                    break;
                case MAP_3:
                    break;
                case MAP_4:
                    break;
                case VOLTAR:
                    CloseWindow();
                    main();
                    break;
            }
        }

        BeginDrawing();
        ClearBackground(BLUE); 

        DrawText("MAPA 1", (largura - MeasureText("MAPA 1", 40)) / 2, 220, 40, optionSelect == MAP_1 ? WHITE : BLACK);
        DrawText("MAPA 2", (largura - MeasureText("MAPA 2", 40)) / 2, 270, 40, optionSelect == MAP_2 ? WHITE : BLACK);
        DrawText("MAPA 3", (largura - MeasureText("MAPA 3", 40)) / 2, 320, 40, optionSelect == MAP_3 ? WHITE : BLACK);
        DrawText("MAPA 4", (largura - MeasureText("MAPA 4", 40)) / 2, 370, 40, optionSelect == MAP_4 ? WHITE : BLACK);
        DrawText("VOLTAR", (largura - MeasureText("VOLTAR", 40)) / 2, 420, 40, optionSelect == VOLTAR ? WHITE : BLACK);

        EndDrawing();
    }
}

// TELA DO JOGO
void openGame() {
    typedef struct {
        float velocidade;
        float posicaoX;
        float posicaoY;

        bool vertical;
        
        Vector2 direcao;
    } Jogador;

    const int largura = 800;
    const int altura = 800;
    InitWindow(largura, altura, "GAME");
    SetTargetFPS(60);

    Jogador jogador;

    jogador.velocidade = largura / 300.0f;
    jogador.posicaoX = largura / 2.0f;
    jogador.posicaoY = (9.0f * altura) / 10.0f;
    jogador.vertical = false;
    jogador.direcao = (Vector2){1.0f, 0.0f};

    int largura_retangulo = 20;
    int altura_retangulo = 15;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_LEFT)) {
            jogador.direcao = (Vector2){-1.0f, 0.0f};
            jogador.vertical = false;  
        } 
        if (IsKeyPressed(KEY_RIGHT)) {
            jogador.direcao = (Vector2){1.0f, 0.0f};
            jogador.vertical = false;  
        }
        if (IsKeyPressed(KEY_UP)) {
            jogador.direcao = (Vector2){0.0f, -1.0f};
            jogador.vertical = true; 
        }
        if (IsKeyPressed(KEY_DOWN)) {
            jogador.direcao = (Vector2){0.0f, 1.0f};
            jogador.vertical = true; 
        }

        jogador.posicaoX += jogador.direcao.x * jogador.velocidade;
        jogador.posicaoY += jogador.direcao.y * jogador.velocidade;

        if (jogador.posicaoX < 0 || jogador.posicaoX + largura_retangulo > largura || jogador.posicaoY < 0 || jogador.posicaoY + altura_retangulo > altura) {
            CloseWindow(); 
        }


        BeginDrawing();
        ClearBackground(RAYWHITE); 

        Color verde = (Color){0, 255, 0, 255};
        Color vermelho = (Color){255, 0, 0, 255};

        if (jogador.vertical) {
            if (jogador.direcao.y < 0) {
                DrawRectangle(jogador.posicaoX, jogador.posicaoY, altura_retangulo, largura_retangulo, vermelho); 
                DrawRectangle(jogador.posicaoX, jogador.posicaoY + largura_retangulo, altura_retangulo, largura_retangulo, verde);
            }
            else {
                DrawRectangle(jogador.posicaoX, jogador.posicaoY + largura_retangulo, altura_retangulo, largura_retangulo, verde); 
                DrawRectangle(jogador.posicaoX, jogador.posicaoY, altura_retangulo, largura_retangulo, vermelho);  
            }
        } else {
            if (jogador.direcao.x < 0) {
                DrawRectangle(jogador.posicaoX, jogador.posicaoY, largura_retangulo, altura_retangulo, vermelho); 
                DrawRectangle(jogador.posicaoX + largura_retangulo, jogador.posicaoY, largura_retangulo, altura_retangulo, verde); 
            } else {
                DrawRectangle(jogador.posicaoX + largura_retangulo, jogador.posicaoY, largura_retangulo, altura_retangulo, vermelho); 
                DrawRectangle(jogador.posicaoX, jogador.posicaoY, largura_retangulo, altura_retangulo, verde); 
            }
        }

        EndDrawing();
    }

    CloseWindow();
}


int main(void) {
    typedef enum { MENU_PLAY, MENU_MAPS, MENU_STYLE_SNAKE, MENU_INFO, MENU_EXIT } MenuOption;
    const int largura = 800;
    const int altura = 800;
    InitWindow(largura, altura, "SNAKE");
    SetTargetFPS(60);

    Image bgImage = LoadImage("imagens/tela.png"); 
    Texture2D bgTexture = LoadTextureFromImage(bgImage);
    UnloadImage(bgImage); 

    MenuOption optionSelect = MENU_PLAY;
    int totalOptions = 5;

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_DOWN)) {
            optionSelect = (optionSelect + 1) % totalOptions;
        }
        if (IsKeyPressed(KEY_UP)) {
            optionSelect = (optionSelect - 1 + totalOptions) % totalOptions;
        }

        if (IsKeyPressed(KEY_ENTER)) {
            switch (optionSelect) {
                case MENU_PLAY:
                    CloseWindow();
                    openGame();
                    main();
                    break;
                case MENU_MAPS:
                    CloseWindow();
                    openMapSelect();
                    main();
                    break;
                case MENU_STYLE_SNAKE:
                    CloseWindow();
                    openStyleSnake();
                    main();
                    break;
                case MENU_INFO:
                    break;
                case MENU_EXIT:
                    CloseWindow();
                    break;
            }
        }

        BeginDrawing();

        Rectangle source = { 0, 0, bgTexture.width, bgTexture.height };
        Rectangle dest = { 0, 0, largura, altura }; 
        Color tint = WHITE; 

        if (!WindowShouldClose()) {
            DrawTexturePro(bgTexture, source, dest, (Vector2){ 0, 0 }, 0.0f, tint);
            DrawText("JOGAR", (largura - MeasureText("JOGAR", 40)) / 2, 220, 40, optionSelect == MENU_PLAY ? WHITE : BLACK);
            DrawText("MAPAS", (largura - MeasureText("MAPAS", 40)) / 2, 270, 40, optionSelect == MENU_MAPS ? WHITE : BLACK);
            DrawText("ESTILO", (largura - MeasureText("ESTILO", 40)) / 2, 320, 40, optionSelect == MENU_STYLE_SNAKE ? WHITE : BLACK);
            DrawText("INFORMAÇÕES", (largura - MeasureText("INFORMAÇÕES", 40)) / 2, 370, 40, optionSelect == MENU_INFO ? WHITE : BLACK);
            DrawText("SAIR", (largura - MeasureText("SAIR", 40)) / 2, 420, 40, optionSelect == MENU_EXIT ? WHITE : BLACK);
        }

        EndDrawing();
    }

    UnloadTexture(bgTexture);

    return 0;
}
