#include <stdlib.h>
#include "fogefoge.h"

// Funções
void inicia_jogo(jogo_t * jogo)
{
    // Inicialização do Mapa
    jogo->mapa = (mapa_t*)malloc(sizeof(mapa_t));
    carrega_mapa(jogo->mapa);

    // Inicialização do Herói
    jogo->personagem = (personagem_t*)malloc(sizeof(personagem_t));
    encontra_personagem(jogo->mapa, jogo->personagem, HEROI);

    // Inicialização dos Fantasmas
    // jogo->numero_fantasmas = encontra_personagem(jogo->mapa, jogo->personagem, FANTASMA);
}

int acabou_jogo(void)
{
    return 0;
}
