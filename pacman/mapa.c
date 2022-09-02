#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

// Declaration of map structure
struct map_s
{
    char ** matrix;
    int lines;
    int columns;
};

// Static function prototypes
static FILE *  _load_map_file(const char * path);
static char ** _matrix_allocation(int lines, int columns);


// Function implementation
map_t * map_load(const char * map_file)
{
    map_t * map_ptr = (map_t*)malloc(sizeof(map_t));
    
    // Load map file
    FILE * file = _load_map_file(map_file);

    
    // Get number of columns of the matrix
    char line[201];
    int columns = 0;

    fscanf(file, "%s", line);
    columns = strlen(line);
    map_ptr->columns = columns;

    
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
    map_ptr->lines = lines;

    
    // Allocate memory for the matrix
    map_ptr->matrix = _matrix_allocation(lines, columns);


    // Populate the matrix
    fseek(file, 0, SEEK_SET);  // point to the beginning of the file
    for(int i = 0; i < map_ptr->lines; i++)
    {
        for(int j = 0; j < (map_ptr->columns + 1); j++)
        {
            character = fgetc(file);

            if(character != '\n' && character != EOF)
            {
                map_ptr->matrix[i][j] = character;
            }
        }
    }

    fclose(file);

    return map_ptr;
}


void map_print(map_t * map)
{
    for(int i = 0;i < map->lines;i++)
    {
        printf("%s\n", map->matrix[i]);
    }
}


int map_get_line(map_t * map)
{
    return map->lines;
}


int map_get_column(map_t * map)
{
    return map->columns;
}


char map_get_position(map_t * map, int x, int y)
{
    return map->matrix[x][y];
}


void map_end(map_t * map)
{
    for(int i = 0; i < map->lines; i++)
    {
        free(map->matrix[i]);
    }
    free(map->matrix);
    free(map);
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
