#ifndef PACMAN_H
#define PACMAN_H

#include "mapa.h"
#include "personagem.h"

#define NUMERO_MAX_FANTASMA 3

struct jogo_s
{
    mapa_t * mapa;
    personagem_t * personagem[1 + NUMERO_MAX_FANTASMA];
    int numero_fantasmas;
};

typedef struct jogo_s jogo_t;

// Protótipo de funções
void inicia_jogo(jogo_t * jogo);
void carrega_tela(jogo_t * jogo);
int  acabou_jogo(void);

#endif  // PACMAN_H