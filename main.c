//  _ __   __ _  ___ _ __ ___   __ _ _ __  
// | '_ \ / _` |/ __| '_ ` _ \ / _` | '_ \
// | |_) | (_| | (__| | | | | | (_| | | | |
// | .__/ \__,_|\___|_| |_| |_|\__,_|_| |_|
// | |                                     
// |_|

// Includes
#include <stdio.h>
#include "pacman/pacman.h"


int main(void)
{
    jogo_t * jogo = inicia_jogo();

    pacman(jogo);
    
    return 0;
}
