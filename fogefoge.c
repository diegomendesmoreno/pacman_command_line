#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fogefoge.h"

// Funções
void ler_mapa(mapa_t * mapa)
{
    FILE * file;
    char str[201];
    char c;

    file = fopen("mapa.txt", "r");

    // Caso não consiga abrir o arquivo
    if(file == 0)
    {
        printf("Desculpe, arquivo de mapa não disponível\n\n");
        exit(1);
    }

    // Descoberta do número de colunas da matriz
    fscanf(file, "%s", str);
    mapa->colunas = strlen(str);

    // Descoberta do número de linhas da matriz
    fseek(file, 0, SEEK_SET);  // Apontando para o início do arquivo
    c = getc(file);
    if(c != EOF)
    {
        mapa->linhas++;
        while(c != EOF)
        {
            c = getc(file);
            if(c == '\n')
            {
                mapa->linhas++;
            }
        }
    }
    else
    {
        printf("Arquivo de mapa vazio\n");
        exit(1);
    }

    // Alocação de memória dinâmica da matriz do mapa
    aloca_mapa(mapa);

    // Escaniando todas as linhas do arquivo
    fseek(file, 0, SEEK_SET);  // Apontando para o início do arquivo
    for(int i = 0;i < mapa->linhas;i++)
    {
        fscanf(file, "%s", mapa->matriz[i]);
    }

    fclose(file);
}

void aloca_mapa(mapa_t * mapa)
{
    // Alocação de memória dinâmica
    mapa->matriz = (char**)malloc(sizeof(char*) * mapa->linhas);
    for(int i = 0;i < mapa->linhas;i++)
    {
        mapa->matriz[i] = (char*)malloc(sizeof(char) * (mapa->colunas + 1));
    }
}

void imprime_mapa(mapa_t * mapa)
{
    // Limpa o console
    printf("\e[1;1H\e[2J"); // Linux only
    
    // Imprime o mapa
    for(int i = 0;i < mapa->linhas;i++)
    {
        printf("%s\n", mapa->matriz[i]);
    }
}

void move_jogador(mapa_t * mapa, char comando)
{
    int x;
    int y;

    // Encontra o jogador @ no mapa
    for(int i = 0; i < mapa->linhas; i++)
    {
        for(int j = 0; j < mapa->colunas; j++)
        {
            if(mapa->matriz[i][j] == '@')
            {
                x = i;
                y = j;
                break;
            }
        }
    }

    // Movimenta o jogador segundo o comando
    switch(comando)
    {
        case 'w':   // up
        {
            if(mapa->matriz[x - 1][y] != '|' && mapa->matriz[x - 1][y] != '-')
            {
                mapa->matriz[x - 1][y] = '@';
                mapa->matriz[x][y] = '.';
            }
        }
        break;
        
        case 's':   // down
        {
            if(mapa->matriz[x + 1][y] != '|' && mapa->matriz[x + 1][y] != '-')
            {
                mapa->matriz[x + 1][y] = '@';
                mapa->matriz[x][y] = '.';
            }
        }
        break;
        
        case 'a':   // left
        {
            if(mapa->matriz[x][y - 1] != '|' && mapa->matriz[x][y - 1] != '-')
            {
                mapa->matriz[x][y - 1] = '@';
                mapa->matriz[x][y] = '.';
            }
        }
        break;
        
        case 'd':   // right
        {
            if(mapa->matriz[x][y + 1] != '|' && mapa->matriz[x][y + 1] != '-')
            {
                mapa->matriz[x][y + 1] = '@';
                mapa->matriz[x][y] = '.';
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

void libera_mapa(mapa_t * mapa)
{
    // Free alocação dinâmica
    for(int i = 0;i < mapa->linhas;i++)
    {
        free(mapa->matriz[i]);
    }
    free(mapa->matriz);
}

int acabou_jogo(void)
{
    return 0;
}
