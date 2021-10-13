#include <iostream>
#include "Game.h"

int main()
{
    // init game
    Game game;

    // game loop
    while (game.running())
    {
        // Update   
        game.update();
        // Render
        game.render();
    }


    return EXIT_SUCCESS;
}