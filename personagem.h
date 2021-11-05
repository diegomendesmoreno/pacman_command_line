#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "mapa.h"

struct personagem_s
{
    char tipo;
    int  x;
    int  y;
};

typedef struct personagem_s personagem_t;

// Protótipo de funções
void encontra_personagem(mapa_t * mapa, personagem_t * personagem, char tipo_personagem);
void move_personagem(mapa_t * mapa, personagem_t * personagem, char comando);

#endif  // PERSONAGEM_H