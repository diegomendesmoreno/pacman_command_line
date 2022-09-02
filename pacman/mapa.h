#ifndef MAPA_H
#define MAPA_H

// Declaration of opaque type
typedef struct map_s map_t;

// Function prototype
map_t * map_load(const char * map_file);
void    map_print(map_t * map);
int     map_get_line(map_t * map);
int     map_get_column(map_t * map);
char    map_get_position(map_t * map, int x, int y);
void    map_end(map_t * map);



enum controles_e
{
    CIMA      = 'w',
    ESQUERDA  = 'a',
    BAIXO     = 's',
    DIREITA   = 'd',
    ALEATORIO = 0
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
void aloca_mapa(mapa_t * mapa);
void imprime_mapa(mapa_t * mapa);
void libera_mapa(mapa_t * mapa);

#endif  // MAPA_H