// Jogo de Foge Foge

// Includes
#include <stdio.h>
#include "pacman/pacman.h"

// Defines de usuário

// Variáveis globais
static jogo_t jogo;


// Protótipo de funções


int main(void)
{
    inicia_jogo(&jogo);

    while(!acabou_jogo())
    {
        carrega_tela(&jogo);
        
        char comando;
        scanf(" %c", &comando);

        move_personagem(jogo.mapa, jogo.personagem[0], comando);
    }

    libera_mapa_matriz(jogo.mapa);
    return 0;
}
