/*Função movimentação*/
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <raylib.h>





   int main(){

    int inicio_x =300;
    int inicio_y =300;
    int PAUSE=0;
    int posicao_X = inicio_x;
    int posicao_Y = inicio_y;
    int LARGURAeAlTURA =20;
    int flag_UP=0, flag_DOWN=0, flag_LEFT=0, flag_RIGHT=0;
        InitWindow(600, 600, "Quadrado");
        MOVE(PAUSE, inicio_x, inicio_y, posicao_X, posicao_Y, LARGURAeAlTURA, flag_UP, flag_DOWN, flag_LEFT, flag_RIGHT);




return 0;
}


   int MOVE(int PAUSE, int inicio_x, int inicio_y, int posicao_X, int posicao_Y, int LARGURAeAlTURA, int flag_UP, int flag_DOWN, int flag_LEFT, int flag_RIGHT){



   while (!WindowShouldClose()&&(PAUSE==0)){
		if(posicao_X<0||posicao_Y<0||posicao_Y+20>=600||posicao_X+20>=600){
			break;
		}

            if(IsKeyPressedRepeat(KEY_UP)&&(flag_UP==0)){
               posicao_Y-=5;
               flag_DOWN=1;
               flag_RIGHT=0;
               flag_LEFT=0;

            }
            if(IsKeyPressedRepeat(KEY_DOWN)&&(flag_DOWN==0)){
               posicao_Y+=5;
               flag_UP=1;
               flag_RIGHT=0;
               flag_LEFT=0;
            }
             if(IsKeyPressedRepeat(KEY_RIGHT)&&(flag_RIGHT==0)){
               posicao_X+=5;
               flag_LEFT=1;
               flag_UP=0;
               flag_DOWN=0;
            }
            if(IsKeyPressedRepeat(KEY_LEFT)&&(flag_LEFT==0)){
               posicao_X-=5;
               flag_RIGHT=1;
               flag_UP=0;
               flag_DOWN=0;
              }


                BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(posicao_X, posicao_Y, LARGURAeAlTURA, LARGURAeAlTURA, GREEN);
            EndDrawing();
        }
    }
