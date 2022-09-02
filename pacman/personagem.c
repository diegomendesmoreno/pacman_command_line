#include "personagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int carrega_personagens(map_t *map, personagem_t **personagem)
{
	int x_inicio = 0;
	int y_inicio = 0;
	int numero_fantasmas = 0;

	// Inicialização do Herói
	personagem[0] = (personagem_t *)malloc(sizeof(personagem_t));
	encontra_personagem(map, personagem[0], HEROI, x_inicio, y_inicio);

	// Inicialização dos Fantasmas
	for(int i = 1; i <= NUMERO_MAX_FANTASMA; i++)
    {
		personagem[i] = (personagem_t *)malloc(sizeof(personagem_t));
		if(encontra_personagem(map, personagem[i], FANTASMA, x_inicio, y_inicio))
        {
			free(personagem[i]);
			break;
		}
        else
        {
			x_inicio = personagem[i]->x;
			y_inicio = personagem[i]->y;
			numero_fantasmas++;
		}
	}

	return numero_fantasmas;
}

// Encontra o personagem no map
int encontra_personagem(
	map_t *map,
	personagem_t *personagem,
	char tipo_personagem,
	int x_inicio,
	int y_inicio)
{
	for (int i = x_inicio; i < map_get_lines(map); i++)
    {
		for (int j = 0; j < map_get_columns(map); j++)
        {
			// Começando após a última busca
			if(i == x_inicio && j <= y_inicio)
            {
				;
			}
            else if(map_get_position(map, i, j) == tipo_personagem)
            {
				personagem->tipo = tipo_personagem;
				personagem->x = i;
				personagem->y = j;

				return 0; // Não completou a busca na matriz toda
			}
		}
	}

	return 1; // Completou a busca na matriz toda
}

// Movimenta o personagem segundo o comando
void move_personagem(map_t *map, personagem_t *personagem, char comando)
{
	if(comando == ALEATORIO)
    {
		const int numero_tentativas = 10;

		comando = sorteia_comando();

		for(int i = 0; i < numero_tentativas; i++)
        {
			if(tenta_movimentar(map, personagem, comando))
            {
				break;
			}
            else
            {
				comando = sorteia_comando();
			}
		}
	}
    else
    {
		tenta_movimentar(map, personagem, comando);
	}
}

int tenta_movimentar(map_t *map, personagem_t *personagem, char comando)
{
	int movimento_feito = 0;

	switch (comando)
    {
    	case CIMA:
        {
    		if(map_get_position(map, personagem->x - 1, personagem->y) != PAREDE
            && map_get_position(map, personagem->x - 1, personagem->y) != CHAO)
            {
    			if(map_get_position(map, personagem->x, personagem->y) == personagem->tipo)
                {
                    map_set_character(map, personagem->x, personagem->y, VAZIO);
    			}
    
    			personagem->x--;
    			map_set_character(map, personagem->x, personagem->y, personagem->tipo);
    
    			movimento_feito = 1;
    		}
    	}
        break;
    
    	case BAIXO:
        {
    		if(map_get_position(map, personagem->x + 1, personagem->y) != PAREDE
            && map_get_position(map, personagem->x + 1, personagem->y) != CHAO)
            {
    			if(map_get_position(map, personagem->x, personagem->y) == personagem->tipo)
                {
    				map_set_character(map, personagem->x, personagem->y, VAZIO);
    			}
    
    			personagem->x++;
    			map_set_character(map, personagem->x, personagem->y, personagem->tipo);
    
    			movimento_feito = 1;
    		}
    	}
        break;
    
    	case ESQUERDA:
        {
    		if(map_get_position(map, personagem->x, personagem->y - 1) != PAREDE
            && map_get_position(map, personagem->x, personagem->y - 1) != CHAO)
            {
    			if(map_get_position(map, personagem->x, personagem->y) == personagem->tipo)
                {
    				map_set_character(map, personagem->x, personagem->y, VAZIO);
    			}
    
    			personagem->y--;
    			map_set_character(map, personagem->x, personagem->y, personagem->tipo);
    
    			movimento_feito = 1;
    		}
    	}
        break;
    
    	case DIREITA:
        {
    		if(map_get_position(map, personagem->x, personagem->y + 1) != PAREDE
            && map_get_position(map, personagem->x, personagem->y + 1) != CHAO)
            {
    			if(map_get_position(map, personagem->x, personagem->y) == personagem->tipo)
                {
    				map_set_character(map, personagem->x, personagem->y, VAZIO);
    			}
    
    			personagem->y++;
    			map_set_character(map, personagem->x, personagem->y, personagem->tipo);
    
    			movimento_feito = 1;
    		}
    	}
        break;
    
    	default:
        {
            ;
        }
        break;
	}

	return movimento_feito;
}

char sorteia_comando(void)
{
	char comandos[4] = {CIMA, ESQUERDA, BAIXO, DIREITA};
	int sorteio = 3;
	time_t t;

	srand((unsigned)time(&t));

	// Faz sorteio do index
	sorteio = rand() % 4;

	return comandos[sorteio];
}

void libera_personagens(personagem_t **personagem, int quantidade_personagens)
{
	// Free alocação dinâmica
	for(int i = 0; i < quantidade_personagens; i++)
    {
		free(personagem[i]);
	}
}
