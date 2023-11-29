 /*
    ALGORITMO E ESTRUTURA DE DADOS I - PUC MINAS
    Trabalho de LAED-I / AED-I;
    ---------------------------
    Grupo:
        Luis Otavio Albergoni Santos;
        Gabriel Leite Soares Ramos;

    Projeto Desenvolvido:
        Baseado em um jogo classico, fizemos uma releitura do jogo batalha naval (ou battleship); usamos a biblioteta
        externa Raylib que possui modo grafico e funcoes uteis para o desenvolvimento de jogos.

    Objetivo:
        Nosso principal objetivo foi desenvolver algo que pudesse englobar o aprendizado de modo gráfico, funções, estruturas
        de dados e o funcionamento de bibliotecas externas. A releitura de um jogo classico é um bom jeito de aplicar pois usa
        extensivamente esses recursos.

    Mudanças ao longo do tempo:
        O jogo foi desenvolvido do zero;
        Adicão dos dados;
        Adicão de telas diferentes;
        Adicão da logica do jogo;
        Reconhecimento da matriz;
        Adição de imagens aos navios;
        Correcão de Erros;
        Adicao de musica;
*/

#include <stdio.h>
#include "raylib.h"

void retornadados();

    typedef struct{
    int tamanho;
    int hits;
    } embarcacao;

    int matriz[5][5] = {{0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,0,0}};

    //declaração de variaveis
    unsigned short int i=-1, j=-1; //linha/coluna
    unsigned short tela = 0; //variavel responsavel pela troca de tela
    unsigned short ammo=15; //qtde de tiros
    unsigned short pontos=0;
    unsigned short nope [25];
    bool desenha[11];



int main(void)
{
    embarcacao nav [4];
    nav [0].tamanho=1;
    nav[0].hits=0;
     //struc submarino
//---------------------------------------------------------
    nav [1].tamanho=5;
    nav[1].hits=0;
    //struct porta avioes
//--------------------------------------------------------
    nav [2].tamanho=2;
    nav[2].hits=0;
    //struct cruzador
//---------------------------------------------------------
    nav [3].tamanho=3;
    nav[3].hits=0;
     //struct  destroyer
//---------------------------------------------------------

     // Initialization
    //--------------------------------------------------------------------------------------
    const int width = 1700;
    const int height = 950;

    InitWindow(width, height, "BattleShip");
    SetTargetFPS(60);

    //carrega textura
    Texture2D b1 = LoadTexture("recursos/b1.png");
    Texture2D b2 = LoadTexture("recursos/b2.png");
    Texture2D b3 = LoadTexture("recursos/b3.png");
    Texture2D a1 = LoadTexture("recursos/a1.png");
    Texture2D a2 = LoadTexture("recursos/a2.png");
    Texture2D a3 = LoadTexture("recursos/a3.png");
    Texture2D a4 = LoadTexture("recursos/a4.png");
    Texture2D a5 = LoadTexture("recursos/a5.png");
    Texture2D c1 = LoadTexture("recursos/c1.png");
    Texture2D d1 = LoadTexture("recursos/d1.png");
    Texture2D d2 = LoadTexture("recursos/d2.png");

    InitAudioDevice();
    //carrega audio
    Music music = LoadMusicStream("recursos/piratesong.mp3");
    Music music1 = LoadMusicStream("recursos/battle.mp3");
    Music music2 = LoadMusicStream("recursos/win.mp3");
    Music music3 = LoadMusicStream("recursos/loser.mp3");




    //--------------------------------------------------------------------------------------

    // Loop prinipal do jogo
    while (!WindowShouldClose())    //Executa enquanto ESC ou o botão de Saaida nao e pressionado
    {
        // Update telas //tela inicial
        BeginDrawing();

        if (tela==0){
            UpdateMusicStream(music); //rmazena os dados na memória
            PlayMusicStream(music);
            DisableCursor();
            ClearBackground(BLACK);     //desenha tela
            DrawText("BattleShip", 660, 350, 70, BLUE);
            DrawText("Press Enter to start", 675, 430, 30, BLUE);
            DrawText("Press R to see how to play", 680, 480, 25, BLUE);
            DrawText("Gabriel && Luis", 1390, 900, 35, BLUE);

            if (IsKeyPressed (KEY_ENTER)){
                EnableCursor();
                tela=1; //tela jogo
                }
                if (IsKeyPressed(KEY_R))
                    tela=2; //tela regras
        }
        //tela jogo   //Atualiza logica do jogo
        if (tela==1){
                UpdateMusicStream(music1);
                PlayMusicStream(music1);

                ClearBackground (BLACK);
                DrawText ("BattleShip", 50,100,70,BLUE);
                DrawText(TextFormat("Ammo: %i", ammo), 50, 800, 40, BLUE);
                DrawText(TextFormat("Score: %i", pontos), 50, 700, 40, BLUE);
                DrawText ("Embarcações afundadas:", 50,200,30,WHITE);
                if (nav [0].tamanho==nav[0].hits)
                    DrawText ("Submarino", 50,250,25,RED);
                if (nav [2].tamanho==nav[2].hits)
                    DrawText ("Cruzador", 50,275,25,RED);
                if (nav [3].tamanho==nav[3].hits)
                    DrawText ("Destroyer", 50,300,25,RED);
                if (nav [1].tamanho==nav[1].hits)
                    DrawText ("Porta Aviões", 50,325,25,RED);

                DrawRectangle(521, 101, 648, 648, BLUE);

                //Coordenadas Verticais.
                DrawText("A", 460,140,50,WHITE);
                DrawText("B", 460,270,50,WHITE);
                DrawText("C", 460,400,50,WHITE);
                DrawText("D", 460,530,50,WHITE);
                DrawText("E", 460,660,50,WHITE);

                //Coordenadas Horizontais.
                DrawText("1", 570,40,50,WHITE);
                DrawText("2", 700,40,50,WHITE);
                DrawText("3", 830,40,50,WHITE);
                DrawText("4", 965,40,50,WHITE);
                DrawText("5", 1095,40,50,WHITE);

                //linha verticais.
                DrawRectangleLines(520, 100, 649, 649, WHITE);
                DrawLine(650, 100, 650, 750, WHITE);
                DrawLine(780, 100, 780, 750, WHITE);
                DrawLine(910, 100, 910, 750, WHITE);
                DrawLine(1040, 100, 1040, 750, WHITE);
                //linhas horizontais.
                DrawLine (520, 230, 1170, 230, WHITE);
                DrawLine (520, 360, 1170, 360, WHITE);
                DrawLine (520, 490, 1170, 490, WHITE);
                DrawLine (520, 620, 1170, 620, WHITE);

        //--------------------------------------------------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=520&&GetMouseY()>=100&&GetMouseX()<=650&&GetMouseY()<=230)){
                i=0; j=0;
                printf ("%d %d\n", i,j);
                nav[3].hits ++;
                pontos ++;
                desenha[0]=true;
                nope[0]++;
                if(nope[0]>1)
                {
                    nav[3].hits--;
                    pontos--;
                    ammo++;
                }
        }
                if ((i==0&&j==0)||(desenha[0]==true))
                DrawTexture(b1, 520, 130, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=650&&GetMouseY()>=100&&GetMouseX()<=780&&GetMouseY()<=230)){
                i=0; j=1;
                printf ("%d %d\n", i,j);
                nav[3].hits ++;
                pontos ++;
                desenha[1] =true;
                nope[1]++;
                if(nope[1]>1)
                {
                    nav[3].hits--;
                    pontos--;
                    ammo++;
                }
        }
            if ((i==0&&j==1) || (desenha[1]==true))
                DrawTexture(b2, 650, 130, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=780&&GetMouseY()>=100&&GetMouseX()<=910&&GetMouseY()<=230)){
                i=0; j=2;
                printf ("%d %d\n", i,j);
                nav[3].hits ++;
                pontos ++;
                desenha[2]=true;
                nope[2]++;
                if(nope[2]>1)
                {
                    nav[3].hits--;
                    pontos--;
                    ammo++;
                }
        }
            if ((i==0&&j==2)||(desenha[2]==true))
                DrawTexture(b3, 780, 130, WHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=910&&GetMouseY()>=100&&GetMouseX()<=1040&&GetMouseY()<=230)){
                i=0; j=3;
                printf ("%d %d\n", i,j);
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=1040&&GetMouseY()>=100&&GetMouseX()<=1170&&GetMouseY()<=230)){
                i=0; j=4;
                printf ("%d %d\n", i,j);
                nope[3]++;
                if(nope[3]>1)
                {
                    ammo++;
                }
        }
        //--------------------------------------------------------------------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=520&&GetMouseY()>=230&&GetMouseX()<=650&&GetMouseY()<=360)){
                i=1; j=0;
                printf ("%d %d\n", i,j);
                nope[4]++;
                if(nope[4]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=650&&GetMouseY()>=230&&GetMouseX()<=780&&GetMouseY()<=360)){
                i=1; j=1;
                printf ("%d %d\n", i,j);
                nope[5]++;
                if(nope[5]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=780&&GetMouseY()>=230&&GetMouseX()<=910&&GetMouseY()<=360)){
                i=1; j=2;
                printf ("%d %d\n", i,j);
                nope[6]++;
                if(nope[6]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=910&&GetMouseY()>=230&&GetMouseX()<=1040&&GetMouseY()<=360)){
                i=1; j=3;
                printf ("%d %d\n", i,j);
                nav[2].hits ++;
                pontos ++;
                desenha[3]=true;
                nope[7]++;
                if(nope[7]>1)
                {
                    nav[2].hits--;
                    pontos--;
                    ammo++;
                }
        }
        if ((i==1&&j==3)||(desenha[3]==true))
                DrawTexture(d1, 955, 260, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=1040&&GetMouseY()>=230&&GetMouseX()<=1170&&GetMouseY()<=360)){
                i=1; j=4;
                printf ("%d %d\n", i,j);
                nav[2].hits ++;
                pontos ++;
                desenha[4]=true;
                nope[8]++;
                if(nope[9]>1)
                {
                    nav[2].hits--;
                    pontos--;
                    ammo++;
                }
        }
        if ((i==1&&j==4)||(desenha[4]==true))
                DrawTexture(d2, 1038, 260, WHITE);
        //--------------------------------------------------------------------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=520&&GetMouseY()>=360&&GetMouseX()<=650&&GetMouseY()<=490)){
                i=2; j=0;
                printf ("%d %d\n", i,j);
                nope[10]++;
                if(nope[10]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=650&&GetMouseY()>=360&&GetMouseX()<=780&&GetMouseY()<=490)){
                i=2; j=1;
                printf ("%d %d\n", i,j);
                nope[11]++;
                if(nope[11]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=780&&GetMouseY()>=360&&GetMouseX()<=910&&GetMouseY()<=490)){
                i=2; j=2;
                printf ("%d %d\n", i,j);
                nav[0].hits ++;
                pontos ++;
                desenha[5]=true;
                nope[12]++;
                if(nope[12]>1)
                {
                    nav[0].hits--;
                    pontos--;
                    ammo++;
                }
        }
        if ((i==2&&j==2)||(desenha[5]==true))
                DrawTexture(c1, 827, 360, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=910&&GetMouseY()>=360&&GetMouseX()<=1040&&GetMouseY()<=490)){
                i=2; j=3;
                printf ("%d %d\n", i,j);
                nope[13]++;
                if(nope[13]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=1040&&GetMouseY()>=360&&GetMouseX()<=1170&&GetMouseY()<=490)){
                i=2; j=4;
                printf ("%d %d\n", i,j);
                nope[14]++;
                if(nope[14]>1)
                {
                    ammo++;
                }
        }
        //--------------------------------------------------------------------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=520&&GetMouseY()>=490&&GetMouseX()<=650&&GetMouseY()<=620)){
                i=3; j=0;
                printf ("%d %d\n", i,j);
                nope[15]++;
                if(nope[15]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=650&&GetMouseY()>=490&&GetMouseX()<=780&&GetMouseY()<=620)){
                i=3; j=1;
                printf ("%d %d\n", i,j);
                nope[16]++;
                if(nope[16]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=780&&GetMouseY()>=490&&GetMouseX()<=910&&GetMouseY()<=620)){
                i=3; j=2;
                printf ("%d %d\n", i,j);
                nope[17]++;
                if(nope[17]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=910&&GetMouseY()>=490&&GetMouseX()<=1040&&GetMouseY()<=620)){
                i=3; j=3;
                printf ("%d %d\n", i,j);
                nope[18]++;
                if(nope[18]>1)
                {
                    ammo++;
                }
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=1040&&GetMouseY()>=490&&GetMouseX()<=1170&&GetMouseY()<=620)){
                i=3; j=4;
                printf ("%d %d\n", i,j);
                nope[19]++;
                if(nope[19]>1)
                {
                    ammo++;
                }
        }
        //--------------------------------------------------------------------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=520&&GetMouseY()>=620&&GetMouseX()<=650&&GetMouseY()<=750)){
                i=4; j=0;
                printf ("%d %d\n", i,j);
                nav[1].hits ++;
                pontos ++;
                desenha[6]=true;
                nope[20]++;
                if(nope[20]>1)
                {
                    nav[1].hits--;
                    pontos--;
                    ammo++;
                }
        }
        if ((i==4&&j==0) || (desenha[6]==true))
                DrawTexture(a1, 520, 600, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=650&&GetMouseY()>=620&&GetMouseX()<=780&&GetMouseY()<=750)){
                i=4; j=1;
                printf ("%d %d\n", i,j);
                nav[1].hits ++;
                pontos ++;
                desenha[7]=true;
                nope[21]++;
                if(nope[21]>1)
                {
                    nav[1].hits--;
                    pontos--;
                    ammo++;
                }
        }
        if ((i==4&&j==1) || (desenha[7]==true))
                DrawTexture(a2, 650, 595, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=780&&GetMouseY()>=620&&GetMouseX()<=910&&GetMouseY()<=750)){
                i=4; j=2;
                printf ("%d %d\n", i,j);
                nav[1].hits ++;
                pontos ++;
                desenha[8]=true;
                nope[22]++;
                if(nope[22]>1)
                {
                    nav[1].hits--;
                    pontos--;
                    ammo++;
                }
        }
        if ((i==4&&j==2) || (desenha[8]==true))
                DrawTexture(a3, 779, 595, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=910&&GetMouseY()>=620&&GetMouseX()<=1040&&GetMouseY()<=750)){
                i=4; j=3;
                printf ("%d %d\n", i,j);
                nav[1].hits ++;
                pontos ++;
                desenha[9]=true;
                nope[23]++;
                if(nope[23]>1)
                {
                    nav[1].hits--;
                    pontos--;
                    ammo++;
                }
        }
        if ((i==4&&j==3) || (desenha[9]==true))
                DrawTexture(a4, 909, 595, WHITE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=1040&&GetMouseY()>=620&&GetMouseX()<=1170&&GetMouseY()<=750)){
                i=4; j=4;
                printf ("%d %d\n", i,j);
                nav[1].hits ++;
                pontos ++;
                desenha[10]=true;
                nope[24]++;
                if(nope[24]>1)
                {
                    nav[1].hits--;
                    pontos--;
                    ammo++;
                }
        }
        if ((i==4&&j==4) || (desenha[10]==true))
                DrawTexture(a5, 1039, 595, WHITE);

        //verifica se perdeu.
         if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)&&(GetMouseX()>=520&&GetMouseY()>=100&&GetMouseX()<=1170&&GetMouseY()<=750)) {
            ammo --;
                if (ammo==0)
                    tela=3;
            }
        //veriifica se ganhou
            if(pontos==11)
                tela=4;

            //zera o nope
            if(tela==3||tela==4){
                for(i=0; i<25; i++){
                    nope[i]=0;
                }
            }
        }
                if (tela==2){
                    if (IsKeyPressed(KEY_F))
                        tela=0;
                    UpdateMusicStream(music);
                    PlayMusicStream(music);
                    ClearBackground (BLACK);
                    DrawText ("How to play", 670,200,70,BLUE);
                    DrawText ("1 - Use left click to fire in a quadrant.", 450, 350, 40, BLUE);
                    DrawText ("2 - If you miss, the quadrant stays empty", 450, 400, 40, BLUE);
                    DrawText ("3 - If your ammo goes to zero, you lose.", 450, 450, 40, BLUE);
                    DrawText ("4 - Destroy all of the ships to win the game.", 450, 500, 40, BLUE);
                    DrawText ("Press F to return to title screen.", 450, 600, 50, BLUE);
                }

                if (tela==3){
                        DisableCursor();
                        UpdateMusicStream(music2);
                        PlayMusicStream(music2);
                        retornadados();
                        ClearBackground (RED);
                        DrawText("Game Over", 650,350,100,BLACK);
                        DrawText("Press Enter to restart", 720, 450, 30, BLACK);
                            for(i=0;i<25;i++){
                                desenha[i]=false;
                                nav[i].hits=0;
                                }
                    if (IsKeyPressed(KEY_ENTER))
                        tela=0;
                }

                if (tela==4){
                    DisableCursor ();
                    UpdateMusicStream(music2);
                    PlayMusicStream(music2);
                    retornadados();
                    ClearBackground(GREEN);
                    DrawText("Game Won!", 650,350,100,BLACK);
                    DrawText("Press Enter to return to title screen.", 610, 450, 30, BLACK);
                        for(i=0;i<25;i++){
                            desenha[i]=false;
                            nav[i].hits=0;
                            }
                    if (IsKeyPressed(KEY_ENTER))
                        tela=0;
                }

        EndDrawing();

        //----------------------------------------------------------------------------------
    }
    UnloadMusicStream(music); UnloadMusicStream(music1);UnloadMusicStream(music2);UnloadMusicStream(music3); //Descarrega musicas

    CloseAudioDevice();

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
void retornadados() {
    if (tela==4||tela==3){
    pontos = 0; ammo = 15;
    }
}
