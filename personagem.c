#include "personagem.h"

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
                break;
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
