#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"


// Static function prototypes
static FILE *  _load_map_file(const char * path);
static char ** _matrix_allocation(int lines, int columns);


// Function implementation
mapa_t * map_load(const char * map_file)
{
    mapa_t * mapa_ptr = (mapa_t*)malloc(sizeof(mapa_t));
    
    // Load map file
    FILE * file = _load_map_file(map_file);

    
    // Get number of columns of the matrix
    char line[201];
    int columns = 0;

    fscanf(file, "%s", line);
    columns = strlen(line);
    mapa_ptr->colunas = columns;

    
    // Get number of lines of the matrix
    int lines = 0;
    char character;
    
    fseek(file, 0, SEEK_SET);  // point to the beginning of the file
    character = fgetc(file);
    if(character != EOF)
    {
        lines++;
        while(character != EOF)
        {
            character = fgetc(file);
            if(character == '\n')
            {
                lines++;
            }
        }
    }
    else
    {
        printf("Map file is empty\n");
        exit(1);
    }
    mapa_ptr->linhas = lines;

    
    // Allocate memory for the matrix
    mapa_ptr->matriz = _matrix_allocation(lines, columns);


    // Populate the matrix
    fseek(file, 0, SEEK_SET);  // point to the beginning of the file
    for(int i = 0; i < mapa_ptr->linhas; i++)
    {
        for(int j = 0; j < (mapa_ptr->colunas + 1); j++)
        {
            character = fgetc(file);

            if(character != '\n' && character != EOF)
            {
                mapa_ptr->matriz[i][j] = character;
            }
        }
    }

    fclose(file);

    return mapa_ptr;
}


void map_print(mapa_t * mapa)
{
    for(int i = 0;i < mapa->linhas;i++)
    {
        printf("%s\n", mapa->matriz[i]);
    }
}


void map_end(mapa_t * mapa)
{
    for(int i = 0; i < mapa->linhas; i++)
    {
        free(mapa->matriz[i]);
    }
    free(mapa->matriz);
    free(mapa);
}


static FILE * _load_map_file(const char * path)
{
    FILE * file = fopen(path, "r");

    // If opening fails
    if(file == 0)
    {
        printf("Map file not found\n\n");
        exit(1);
    }

    return file;
}


static char ** _matrix_allocation(int lines, int columns)
{
    char ** matrix = (char**)malloc(sizeof(char*) * lines);
    
    for(int i = 0; i < lines; i++)
    {
        matrix[i] = (char*)malloc(sizeof(char) * (columns + 1));
    }

    return matrix;
}



// DELETE

void carrega_mapa(mapa_t * mapa)
{
    FILE * file;
    char linha[201];
    char caracter;

    file = fopen("pacman/mapas/mapa2.txt", "r");

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
    caracter = fgetc(file);
    if(caracter != EOF)
    {
        mapa->linhas++;
        while(caracter != EOF)
        {
            caracter = fgetc(file);
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
    aloca_mapa(mapa);

    // Escaniando todas as linhas do arquivo
    fseek(file, 0, SEEK_SET);  // Apontando para o início do arquivo
    for(int i = 0; i < mapa->linhas; i++)
    {
        for(int j = 0; j < (mapa->colunas + 1); j++)
        {
            caracter = fgetc(file);

            if(caracter != '\n' && caracter != EOF)
            {
                mapa->matriz[i][j] = caracter;
            }
        }
    }

    fclose(file);
}

void aloca_mapa(mapa_t * mapa)
{
    // Alocação de memória dinâmica
    mapa->matriz = (char**)malloc(sizeof(char*) * mapa->linhas);
    for(int i = 0; i < mapa->linhas; i++)
    {
        mapa->matriz[i] = (char*)malloc(sizeof(char) * (mapa->colunas + 1));
    }
}

void imprime_mapa(mapa_t * mapa)
{
    for(int i = 0;i < mapa->linhas;i++)
    {
        printf("%s\n", mapa->matriz[i]);
    }
}

void libera_mapa(mapa_t * mapa)
{
    // Free alocação dinâmica
    for(int i = 0; i < mapa->linhas; i++)
    {
        free(mapa->matriz[i]);
    }
    free(mapa->matriz);
}
