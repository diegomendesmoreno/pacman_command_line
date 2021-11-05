#include <stdlib.h>
#include "personagem.h"

void carrega_personagens(mapa_t * mapa, personagem_t ** personagem)
{
    // Inicialização do Herói
    personagem[0] = (personagem_t*)malloc(sizeof(personagem_t));
    encontra_personagem(mapa, personagem[0], HEROI);

    // Inicialização dos Fantasmas
    // jogo->numero_fantasmas = encontra_personagem(jogo->mapa, jogo->personagem, FANTASMA);
    
    // printf("%c [%d][%d]\n", jogo->personagem[0]->tipo, jogo->personagem[0]->x, jogo->personagem[0]->y);
}

// Encontra o personagem no mapa
void encontra_personagem(mapa_t * mapa, personagem_t * personagem, char tipo_personagem)
{
    for(int i = 0; i < mapa->linhas; i++)
    {
        for(int j = 0; j < mapa->colunas; j++)
        {
            if(mapa->matriz[i][j] == tipo_personagem)
            {
                personagem->tipo = tipo_personagem;
                personagem->x = i;
                personagem->y = j;

                if(tipo_personagem == HEROI)
                {
                    break;
                }
                else
                {
                    
                }
            }
        }
    }
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
                mapa->matriz[personagem->x][personagem->y] = HEROI;
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
                mapa->matriz[personagem->x][personagem->y] = HEROI;
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
                mapa->matriz[personagem->x][personagem->y] = HEROI;
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
                mapa->matriz[personagem->x][personagem->y] = HEROI;
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
