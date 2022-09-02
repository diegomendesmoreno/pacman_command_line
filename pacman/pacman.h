#ifndef PACMAN_H
#define PACMAN_H

// Declaration of opaque type
typedef struct game_s game_t;

// Function prototype
game_t * pacman_load(const int map_number);
void     pacman_play(game_t * game);

#endif  // PACMAN_H