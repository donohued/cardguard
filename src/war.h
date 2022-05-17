#include "deck.h"

class War{
    public:
        War();
        ~War();
    public:
        void Play(Deck &deck);
    protected:
        void Deal(Deck &deck);
        std::deque<Card*> playerDeck;
        std::deque<Card*> computerDeck;
    private:
        bool GameOver(int p, int c);
};