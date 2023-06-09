#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "map.h"
#include "personagem.h"

// #define DEBUG_MODE

// Declaration of game structure
struct game_s
{
    map_t * map;
    personagem_t * personagem[1 + GHOST_MAX_NUMBER];
    int ghost_quantity;
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


// Static function prototypes
static void _load_screen(game_t * game);
static int  _is_it_over(game_t * game);
static void _game_over(game_t * game);


game_t * pacman_load(const int map_number)
{
    // Game initialization
    game_t * game_ptr = (game_t*)malloc(sizeof(game_t));

    // Map inialization
    switch(map_number)
    {
        case 1:
        {
            game_ptr->map = map_load("pacman/maps/map_1.txt");
        }
        break;

        case 2:
        {
            game_ptr->map = map_load("pacman/maps/map_2.txt");
        }
        break;

        case 3:
        {
            game_ptr->map = map_load("pacman/maps/map_3.txt");
        }
        break;

        default:
        {
            printf("Invalid map number\n");
            free(game_ptr);
            exit(1);
        }
        break;
    }

    // Characters inicialization
    game_ptr->ghost_quantity = carrega_personagens(game_ptr->map, game_ptr->personagem);

    return game_ptr;
}


void pacman_play(game_t * game)
{
    while(!_is_it_over(game))
    {
        _load_screen(game);
        
        char command;
        scanf(" %c", &command);

        // Hero movement
        move_personagem(game->map, game->personagem[0], command);

        // Ghost movement
        for(int i = 1; i <= game->ghost_quantity; i++)
        {
            move_personagem(game->map, game->personagem[i], ALEATORIO);
        }
    }

    _game_over(game);
}


static void _load_screen(game_t * game)
{
    // Cleans console
    printf("\e[1;1H\e[2J"); // Linux only
    
#ifdef DEBUG_MODE
    printf("\n\nDEBUG MODE\n\n");
    printf("Map     [%d][%d]\n", map_get_lines(game->map), map_get_columns(game->map));
    printf("Hero    [%d][%d]\n", game->personagem[0]->x, game->personagem[0]->y);
    for(int i = 1; i <= game->ghost_quantity; i++)
    {
        printf("Ghost %d [%d][%d]\n", i,
                game->personagem[i]->x, game->personagem[i]->y);
    }
    printf("\n");
#else
    printf("%s\n", ascii_pacman_logo);
    printf("%s\n", ascii_pacman_art);
#endif
    
    map_print(game->map);
}


static int _is_it_over(game_t * game)
{
    int its_over = 0;

    for(int i = 1; i <= game->ghost_quantity; i++)
    {
        if(game->personagem[0]->x == game->personagem[i]->x &&
           game->personagem[0]->y == game->personagem[i]->y)
        {
            its_over = 1;
            break;
        }
    }

    return its_over;
}


static void _game_over(game_t * game)
{
    // Load final screen
    _load_screen(game);
    printf("\nBooooo it's over\n");

    // Freeing memory
    libera_personagens(game->personagem, (game->ghost_quantity + 1));
    map_end(game->map);
    free(game);
}
