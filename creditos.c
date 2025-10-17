#include "raylib.h"
#include <stdlib.h>

int rodar_creditos(int larguraTela, int alturaTela) {

    int tela_atual_jogo = 1; // Isso significa que estamos nos créditos
    int sair_do_creditos = 0;

    // ativando as funções de áudio
    InitAudioDevice();

    // carregando a imagem de fundo
    Image tela_fundo = LoadImage("imagens/imagem_creditos.png");
    ImageResize(&tela_fundo, larguraTela, alturaTela);
    Texture2D tela_fundo_tex = LoadTextureFromImage(tela_fundo);

    // carregando a música
    Music musica_creditos = LoadMusicStream("musicas/musica_creditos.ogg");
    PlayMusicStream(musica_creditos);

    while (!WindowShouldClose() || !(sair_do_creditos))
    {
        
        UpdateMusicStream(musica_creditos);

        if(IsKeyPressed(KEY_W)) {

            sair_do_creditos = 1;
            tela_atual_jogo = 0;

        }

        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawTexture(tela_fundo_tex, 0, 0, WHITE);

        EndDrawing();

    }
    UnloadImage(tela_fundo);
    UnloadMusicStream(musica_creditos);

    CloseWindow();

    return tela_atual_jogo;
}