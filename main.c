// Jogo de Forca

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines de usuário

// Variáveis globais
// char mapa[200][200+1];
char **mapa;

// Protótipo de funções
void ler_mapa(void);

int main(void)
{
  ler_mapa();

  return 0;
}

// Funções
void ler_mapa(void)
{
    FILE *f;
    int colunas = 0;
    int linhas = 0;
    char str[201];
    char c;

    f = fopen("mapa.txt", "r");

    // Caso não consiga abrir o arquivo
    if(f == 0)
    {
        printf("Desculpe, arquivo de mapa não disponível\n\n");
        exit(1);
    }

    // Descoberta do número de colunas da matriz
    fscanf(f, "%s", str);
    colunas = strlen(str);

    // Descoberta do número de linhas da matriz
    fseek(f, 0, SEEK_SET);  // Volta o ponteiro do arquivo para voltar para a primeira posição
    c = getc(f);
    if(c != EOF)
    {
        ++linhas;
        while(c != EOF)
        {
            c = getc(f);
            if(c == '\n')
            {
                ++linhas;
            }
        }
    }
    else
    {
        printf("Arquivo de mapa vazio\n");
        exit(1);
    }

    // Alocação de memória dinâmica
    mapa = malloc(sizeof(char*) * linhas);
    for(int i = 0;i < linhas;i++)
    {
        mapa[i] = malloc(sizeof(char) * (colunas+1));
    }

    fseek(f, 0, SEEK_SET);  // Volta o ponteiro do arquivo para voltar para a primeira posição
    for(int i = 0;i < linhas;i++)
    {
        fscanf(f, "%s", mapa[i]);
    }

    for(int i = 0;i < linhas;i++)
    {
        printf("%s\n", mapa[i]);
    }

    fclose(f);

    // Free alocação dinâmica
    for(int i = 0;i < linhas;i++)
    {
        free(mapa[i]);
    }
    free(mapa);

    printf("\n\nMatriz %d x %d\n", linhas, colunas);//delete
}
