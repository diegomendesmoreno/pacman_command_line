#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

// #define DEBUG_MODE

// Declaration of game structure
struct jogo_s
{
    map_t * map;
    personagem_t * personagem[1 + NUMERO_MAX_FANTASMA];
    int numero_fantasmas;
};

const char * ascii_pacman_logo = "\n\
 _ __   __ _  ___ _ __ ___   __ _ _ __  \n\
| '_ \\ / _` |/ __| '_ ` _ \\ / _` | '_ \\ \n\
| |_) | (_| | (__| | | | | | (_| | | | |\n\
| .__/ \\__,_|\\___|_| |_| |_|\\__,_|_| |_|\n\
| |                                     \n\
|_|                                     \n\
\n";  // https://ascii.co.uk/art/pacman

const char * ascii_pacman_art = "\n\
──▒▒▒▒▒────▄████▄─────\n\
─▒─▄▒─▄▒──███▄█▀──────\n\
─▒▒▒▒▒▒▒─▐████──█──█──\n\
─▒▒▒▒▒▒▒──█████▄──────\n\
─▒─▒─▒─▒───▀████▀─────\n\
\n";  // https://hopemoji.com/text-art-ascii/pacman/


jogo_t * pacman_load(void)
{
    // Game initialization
    jogo_t * jogo_ptr = (jogo_t*)malloc(sizeof(jogo_t));

    // Map inialization
    jogo_ptr->map = map_load("pacman/maps/map_2.txt");

    // Characters inicialization
    jogo_ptr->numero_fantasmas = carrega_personagens(jogo_ptr->map, jogo_ptr->personagem);

    return jogo_ptr;
}


void pacman(jogo_t * jogo)
{
    while(!acabou_jogo(jogo))
    {
        carrega_tela(jogo);
        
        char comando;
        scanf(" %c", &comando);

        // Move Herói
        move_personagem(jogo->map, jogo->personagem[0], comando);

        // Move Fantasmas
        for(int i = 1; i <= jogo->numero_fantasmas; i++)
        {
            // Fazer inteligência artificial dos fantasmas
            move_personagem(jogo->map, jogo->personagem[i], ALEATORIO);
        }
    }

    termina_jogo(jogo);
}


void carrega_tela(jogo_t * jogo)
{
    // Cleans console
    printf("\e[1;1H\e[2J"); // Linux only
    
#ifdef DEBUG_MODE
    printf("\n\nDEBUG MODE\n\n");
    printf("Map     [%d][%d]\n", map_get_lines(jogo->map), map_get_columns(jogo->map));
    printf("Hero    [%d][%d]\n", jogo->personagem[0]->x, jogo->personagem[0]->y);
    for(int i = 1; i <= jogo->numero_fantasmas; i++)
    {
        printf("Ghost %d [%d][%d]\n", i,
                jogo->personagem[i]->x, jogo->personagem[i]->y);
    }
    printf("\n");
#else
    printf("%s\n", ascii_pacman_logo);
    printf("%s\n", ascii_pacman_art);
#endif
    
    map_print(jogo->map);
}


int acabou_jogo(jogo_t * jogo)
{
    int acabou = 0;

    for(int i = 1; i <= jogo->numero_fantasmas; i++)
    {
        if(jogo->personagem[0]->x == jogo->personagem[i]->x && 
           jogo->personagem[0]->y == jogo->personagem[i]->y)
        {
            acabou = 1;
            break;
        }
    }

    return acabou;
}


void termina_jogo(jogo_t * jogo)
{
    // Carrega a tela final
    carrega_tela(jogo);
    printf("\nBooooo it's over\n");

    // Freeing memory
    libera_personagens(jogo->personagem, (jogo->numero_fantasmas + 1));
    map_end(jogo->map);
    free(jogo);
}
