#include <vector>
#include <stack>

#include "card.h"

class Deck{
    public:
        Deck();
        ~Deck();

    public:
        void shuffle();
        void printDeck();
        Card* draw();
        

    protected:
        std::vector<Card*> deck;
        std::stack<Card*> shuffled;
};