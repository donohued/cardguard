#include <iostream>
#include <time.h>

#include "war.h"

int main(int argc, char **argv)
{

    srand(time(NULL));

    Deck deck;
    deck.shuffle();
    
    War game;

    game.Play(deck);

    return 1;
}
