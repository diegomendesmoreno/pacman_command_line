#include <stdio.h>
#include <stdlib.h>
#include "personagem.h"

// #define DEBUG

int carrega_personagens(mapa_t * mapa, personagem_t ** personagem)
{
    int x_inicio = 0;
    int y_inicio = 0;
    int numero_fantasmas = 0;

    // Inicialização do Herói
    personagem[0] = (personagem_t*)malloc(sizeof(personagem_t));
    encontra_personagem(mapa, personagem[0], HEROI, x_inicio, y_inicio);

#ifdef DEBUG
    printf("Herói [%d][%d]\n", personagem[0]->x, personagem[0]->y);
#endif

    // Inicialização dos Fantasmas
    for(int i = 1; i <= NUMERO_MAX_FANTASMA; i++)
    {
        personagem[i] = (personagem_t*)malloc(sizeof(personagem_t));
        if(encontra_personagem(mapa, personagem[i], FANTASMA, x_inicio, y_inicio))
        {
            free(personagem[i]);
            break;
        }
        else
        {
#ifdef DEBUG
            printf("Fantasma %d [%d][%d]\n", i, personagem[i]->x, personagem[i]->y);
#endif
            x_inicio = personagem[i]->x;
            y_inicio = personagem[i]->y;
            numero_fantasmas++;
        }
    }

#ifdef DEBUG
    printf("Há %d fantasmas\n", numero_fantasmas);
#endif

    return numero_fantasmas;
}

// Encontra o personagem no mapa
int encontra_personagem(mapa_t * mapa, personagem_t * personagem, char tipo_personagem, int x_inicio, int y_inicio)
{
    for(int i = x_inicio; i < mapa->linhas; i++)
    {
        for(int j = 0; j < mapa->colunas; j++)
        {
            // Começando após a última busca
            if(i == x_inicio && j <= y_inicio)
            {
                ;
            }
            else if(mapa->matriz[i][j] == tipo_personagem)
            {
                personagem->tipo = tipo_personagem;
                personagem->x = i;
                personagem->y = j;

                return 0;   // Não completou a busca na matriz toda
            }
        }
    }

    return 1;   // Completou a busca na matriz toda
}

// Movimenta o personagem segundo o comando
void move_personagem(mapa_t * mapa, personagem_t * personagem, char comando)
{
    switch(comando)
    {
        case CIMA:
        {
            if(mapa->matriz[personagem->x - 1][personagem->y] != PAREDE &&
               mapa->matriz[personagem->x - 1][personagem->y] != CHAO)
            {
                mapa->matriz[personagem->x][personagem->y] = VAZIO;

                personagem->x--;
                mapa->matriz[personagem->x][personagem->y] = personagem->tipo;
            }
        }
        break;
        
        case BAIXO:
        {
            if(mapa->matriz[personagem->x + 1][personagem->y] != PAREDE &&
               mapa->matriz[personagem->x + 1][personagem->y] != CHAO)
            {
                mapa->matriz[personagem->x][personagem->y] = VAZIO;

                personagem->x++;
                mapa->matriz[personagem->x][personagem->y] = personagem->tipo;
            }
        }
        break;
        
        case ESQUERDA:
        {
            if(mapa->matriz[personagem->x][personagem->y - 1] != PAREDE &&
               mapa->matriz[personagem->x][personagem->y - 1] != CHAO)
            {
                mapa->matriz[personagem->x][personagem->y] = VAZIO;
                
                personagem->y--;
                mapa->matriz[personagem->x][personagem->y] = personagem->tipo;
            }
        }
        break;
        
        case DIREITA:
        {
            if(mapa->matriz[personagem->x][personagem->y + 1] != PAREDE &&
               mapa->matriz[personagem->x][personagem->y + 1] != CHAO)
            {
                mapa->matriz[personagem->x][personagem->y] = VAZIO;

                personagem->y++;
                mapa->matriz[personagem->x][personagem->y] = personagem->tipo;
            }
        }
        break;
        
        default:
        {
            ;
        }
        break;
    }
}
