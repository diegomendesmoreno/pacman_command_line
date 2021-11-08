#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "mapa.h"

#define NUMERO_MAX_FANTASMA 4

struct personagem_s
{
    char tipo;
    int  x;
    int  y;
};

typedef struct personagem_s personagem_t;

// Protótipo de funções
int carrega_personagens(mapa_t * mapa, personagem_t ** personagem);
int encontra_personagem(mapa_t * mapa, personagem_t * personagem, char tipo_personagem, int x_inicio, int y_inicio);
void move_personagem(mapa_t * mapa, personagem_t * personagem, char comando);
int tenta_movimentar(mapa_t * mapa, personagem_t * personagem, char comando);
char sorteia_comando(void);
void libera_personagens(personagem_t ** personagem, int quantidade_personagens);

#endif  // PERSONAGEM_H