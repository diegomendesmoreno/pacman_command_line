#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

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

void inicia_jogo(jogo_t * jogo)
{
    // Inicialização do Mapa
    jogo->mapa = (mapa_t*)malloc(sizeof(mapa_t));
    carrega_mapa(jogo->mapa);

    // Inicialização de personagens
    carrega_personagens(jogo->mapa, jogo->personagem);
}

void carrega_tela(jogo_t * jogo)
{
    // Limpa o console
    printf("\e[1;1H\e[2J"); // Linux only

    printf("%s\n", ascii_pacman_logo);
    printf("%s\n", ascii_pacman_art);
    
    imprime_mapa(jogo->mapa);
}

int acabou_jogo(void)
{
    return 0;
}
