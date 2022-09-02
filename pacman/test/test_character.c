// Test file for character

// Includes
#include <stdio.h>
#include <stdlib.h>
#include "../personagem.h"


int main(void)
{
    printf("\n");
    printf("TEST 1\n");
    mapa_t * map_1 = map_load("pacman/mapas/mapa1.txt");
    map_print(map_1);
    map_end(map_1);

    return 0;
}
