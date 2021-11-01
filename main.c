// Jogo de Forca

// Includes
#include <stdio.h>
#include "fogefoge.h"

// Defines de usuário

// Variáveis globais
static mapa_t mapa;

// Protótipo de funções


int main(void)
{
    ler_mapa(&mapa);

    while(!acabou_jogo())
    {
        imprime_mapa(&mapa);

        char comando;
        scanf(" %c", &comando);

        move_jogador(&mapa, comando);
    }

    libera_mapa(&mapa);
    return 0;
}
