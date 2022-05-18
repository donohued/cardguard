#include <iostream>
#include <time.h>

#include "war.h"
#include "board.h"

int main(int argc, char **argv)
{

    srand(time(NULL));

    Deck deck;
    deck.shuffle();
    
    Board board(15);
    std::cout << "yes :)" << std::endl;
    board.print();


    //War game;
    //game.Play(deck);

    return 1;
}
