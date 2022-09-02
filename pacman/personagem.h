#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "map.h"

#define NUMERO_MAX_FANTASMA 4

// Declaration of personagem structure
struct personagem_s
{
    char tipo;
    int  x;
    int  y;
};

typedef struct personagem_s personagem_t;

// Protótipo de funções
int carrega_personagens(map_t * map, personagem_t ** personagem);
int encontra_personagem(map_t * map, personagem_t * personagem, char tipo_personagem, int x_inicio, int y_inicio);
void move_personagem(map_t * map, personagem_t * personagem, char comando);
int tenta_movimentar(map_t * map, personagem_t * personagem, char comando);
char sorteia_comando(void);
void libera_personagens(personagem_t ** personagem, int quantidade_personagens);

#endif  // PERSONAGEM_H