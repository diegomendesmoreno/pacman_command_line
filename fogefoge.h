#ifndef FOGEFOGE_H
#define FOGEFOGE_H

#include "mapa.h"
#include "personagem.h"

#define NUMERO_MAX_FANTASMA 3

struct jogo_s
{
    mapa_t * mapa;
    personagem_t * personagem;
    // personagem_t * personagem[1 + NUMERO_MAX_FANTASMA];
    int numero_fantasmas;
};

typedef struct jogo_s jogo_t;

// Protótipo de funções
void inicia_jogo(jogo_t * jogo);
// void move_personagem(jogo_t * jogo, char comando);
int  acabou_jogo(void);

#endif  // FOGEFOGE_H