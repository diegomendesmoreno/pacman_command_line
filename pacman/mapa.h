#ifndef MAPA_H
#define MAPA_H

enum controles_e
{
    CIMA     = 'w',
    ESQUERDA = 'a',
    BAIXO    = 's',
    DIREITA  = 'd'
};

enum elementos_mapa_e
{
    HEROI    = '@',
    FANTASMA = 'F',
    PAREDE   = '#',
    CHAO     = '#',
    VAZIO    = ' '
};

struct mapa_s
{
    char ** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa_s mapa_t;

// Protótipo de funções
void carrega_mapa(mapa_t * mapa);
void imprime_mapa(mapa_t * mapa);
void aloca_mapa_matriz(mapa_t * mapa);
void libera_mapa_matriz(mapa_t * mapa);

#endif  // MAPA_H