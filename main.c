#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "menu.h"
#include "creditos.h"

int main(void) {

    const int largura_tela = 1920;
    const int altura_tela = 1080;
    InitWindow(largura_tela, altura_tela, "Chaves: em busca da chave perdida");

    SetTargetFPS(60);

    int tela_atual = 0;

    while (!WindowShouldClose())
    {
        
        switch (tela_atual)
        {
        case 0:
            tela_atual = rodarMenu(largura_tela, altura_tela);
            break;

        case 1:
            tela_atual = rodar_creditos(largura_tela, altura_tela);
            break;
        
        default:
            break;
        }    

    }
    
    CloseWindow();

    return 0;
}