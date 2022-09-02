// Test file for map

// Includes
#include <stdio.h>
#include <stdlib.h>
#include "../mapa.h"


int main(void)
{
    printf("\n");
    printf("TEST 1\n");
    mapa_t * map_1 = map_load("pacman/mapas/mapa1.txt");
    map_print(map_1);
    map_end(map_1);

    printf("\n");
    printf("TEST 2\n");
    mapa_t * map_2 = map_load("pacman/mapas/mapa2.txt");
    map_print(map_2);
    map_end(map_2);

    printf("\n");
    printf("TEST 3\n");
    mapa_t * map_3 = map_load("pacman/mapas/mapa3.txt");
    map_print(map_3);
    map_end(map_3);

    return 0;
}
