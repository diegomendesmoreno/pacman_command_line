#ifndef MAP_H
#define MAP_H


// Declaration of opaque type
typedef struct map_s map_t;


// Function prototype
map_t * map_load(const char * map_file);
void    map_print(map_t * map);
int     map_get_lines(map_t * map);
int     map_get_columns(map_t * map);
char    map_get_position(map_t * map, int x, int y);
void    map_set_character(map_t * map, int x, int y, int character);
void    map_end(map_t * map);


enum controles_e
{
    CIMA      = 'w',
    ESQUERDA  = 'a',
    BAIXO     = 's',
    DIREITA   = 'd',
    ALEATORIO = 0
};


enum elementos_map_e
{
    HEROI    = '@',
    FANTASMA = 'F',
    PAREDE   = '#',
    CHAO     = '#',
    VAZIO    = ' '
};


#endif  // MAP_H