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

        // Move Herói
        move_personagem(jogo.mapa, jogo.personagem[0], comando);

        // Move Fantasmas
        for(int i = 1; i <= jogo.numero_fantasmas; i++)
        {
            // Fazer inteligência artificial dos fantasmas
            move_personagem(jogo.mapa, jogo.personagem[i], DIREITA);
        }
    }

    libera_mapa_matriz(jogo.mapa);
    return 0;
}
