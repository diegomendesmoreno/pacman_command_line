#ifndef FOGEFOGE_H
#define FOGEFOGE_H

struct mapa_s
{
    char ** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa_s mapa_t;

// Protótipo de funções
void ler_mapa(mapa_t * mapa);
void aloca_mapa(mapa_t * mapa);
void imprime_mapa(mapa_t * mapa);
void move_jogador(mapa_t * mapa, char comando);
void libera_mapa(mapa_t * mapa);
int  acabou_jogo(void);

#endif  // FOGEFOGE_H