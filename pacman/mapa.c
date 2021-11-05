#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void carrega_mapa(mapa_t * mapa)
{
    FILE * file;
    char linha[201];
    char caracter;

    file = fopen("pacman/mapas/mapa1.txt", "r");

    // Caso não consiga abrir o arquivo
    if(file == 0)
    {
        printf("Arquivo de mapa não disponível\n\n");
        exit(1);
    }

    // Descoberta do número de colunas da matriz
    fscanf(file, "%s", linha);
    mapa->colunas = strlen(linha);

    // Descoberta do número de linhas da matriz
    fseek(file, 0, SEEK_SET);  // Apontando para o início do arquivo
    caracter = getc(file);
    if(caracter != EOF)
    {
        mapa->linhas++;
        while(caracter != EOF)
        {
            caracter = getc(file);
            if(caracter == '\n')
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

    // Alocação da matriz do mapa
    aloca_mapa_matriz(mapa);

    // Escaniando todas as linhas do arquivo
    fseek(file, 0, SEEK_SET);  // Apontando para o início do arquivo
    for(int i = 0; i < mapa->linhas; i++)
    {
        fscanf(file, "%s", mapa->matriz[i]);
    }

    fclose(file);
}

void imprime_mapa(mapa_t * mapa)
{
    // Imprime o mapa
    for(int i = 0;i < mapa->linhas;i++)
    {
        printf("%s\n", mapa->matriz[i]);
    }
}

void aloca_mapa_matriz(mapa_t * mapa)
{
    // Alocação de memória dinâmica
    mapa->matriz = (char**)malloc(sizeof(char*) * mapa->linhas);
    for(int i = 0;i < mapa->linhas;i++)
    {
        mapa->matriz[i] = (char*)malloc(sizeof(char) * (mapa->colunas + 1));
    }
}

void libera_mapa_matriz(mapa_t * mapa)
{
    // Free alocação dinâmica
    for(int i = 0;i < mapa->linhas;i++)
    {
        free(mapa->matriz[i]);
    }
    free(mapa->matriz);
}
