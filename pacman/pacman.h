#ifndef PACMAN_H
#define PACMAN_H

#include "mapa.h"
#include "personagem.h"

// struct jogo_s
// {
//     mapa_t * mapa;
//     personagem_t * personagem[1 + NUMERO_MAX_FANTASMA];
//     int numero_fantasmas;
// };

// Declaration of opaque type
typedef struct jogo_s jogo_t;

// Protótipo de funções
jogo_t * inicia_jogo(void);
void     pacman(jogo_t * jogo);
void     carrega_tela(jogo_t * jogo);
int      acabou_jogo(jogo_t * jogo);
void     termina_jogo(jogo_t * jogo);

#endif  // PACMAN_H