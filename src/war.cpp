#include <iostream>
#include <stack>

#include "war.h"

//TODO: make deck size a const?

War::War(){

    

}

War::~War(){

}

void War::Play(Deck &deck){

    deck.shuffle();
    Deal(deck);

    std::cout << "You have " << this->playerDeck.size() << " cards." << std::endl;
    std::cout << "Your opponent has " << this->computerDeck.size() << " cards." << std::endl;
    std::cout << "Press P to play a card and start the game. (press A to autoplay until there is a winner)" << std::endl;
    std::string input;
    std::cin >> input;

    bool hasWon = false;
    bool autoPlay = false;
    int battleValue;
    int rounds = 0;

    if (input.compare("P") == 0 || input.compare("p") == 0 || input.compare("A") == 0 || input.compare("a") == 0)
    {
        if(input.compare("A") == 0 || input.compare("a") == 0)
            autoPlay = true;

        std::stack<Card*> pHand;
        std::stack<Card*> cHand;
        
        while(!hasWon){    
            
            rounds++;
            //std::cout << "So this is a longer string to see more easily during the auto run, but basically the score is: " << this->playerDeck.size() << " vs " << this->computerDeck.size() << std::endl;

            pHand.push(this->playerDeck.back());
            this->playerDeck.pop_back();

            std::cout << "You play: ";
            pHand.top()->print();

            cHand.push(this->computerDeck.back());
            this->computerDeck.pop_back();

            std::cout << "They play: ";
            cHand.top()->print();

            //Check top of stack card values
            battleValue = pHand.top()->compareValue((Card)*cHand.top());

            while (battleValue == 0){

                std::cout << "There was a war!!" << std::endl;

                if(!autoPlay){
                    
                    std::cout << "Press any key to continue" << std::endl;
                    std::cin >> input;
                }

                if (this->playerDeck.size() < 2 || this->computerDeck.size() < 2)
                {
                    std::cout << "The battle cannot be fought" << std::endl;
                    if(this->playerDeck.size() == 0 || this->computerDeck.size() == 0){
                        hasWon = GameOver(this->playerDeck.size(), this->computerDeck.size());
                        break;
                    }
                    std::cout << "Final Stand!!!" << std::endl;
                    
                    pHand.push(this->playerDeck.back());
                    this->playerDeck.pop_back();
                    cHand.push(this->computerDeck.back());
                    this->computerDeck.pop_back();

                    std::cout << "Your top card: ";
                    pHand.top()->print();

                    std::cout << "Their top card: ";
                    cHand.top()->print();

                    battleValue = pHand.top()->compareValue((Card)*cHand.top());
                    break;

                }
                

                pHand.push(this->playerDeck.back());
                this->playerDeck.pop_back();
                pHand.push(this->playerDeck.back());
                this->playerDeck.pop_back();

                cHand.push(this->computerDeck.back());
                this->computerDeck.pop_back();
                cHand.push(this->computerDeck.back());
                this->computerDeck.pop_back();

                std::cout << "Each player has placed " << cHand.size() << " cards" << std::endl;

                std::cout << "You play: ";
                pHand.top()->print();

                std::cout << "They play: ";
                cHand.top()->print();

                battleValue = pHand.top()->compareValue((Card)*cHand.top());
            }         

            if (battleValue < 0){

                std::cout << "The computer has the high card." << std::endl;

                while ((cHand.size() + pHand.size()) > 0){
                    this->computerDeck.push_front(pHand.top());
                    pHand.pop();
                    this->computerDeck.push_front(cHand.top());
                    cHand.pop();
                }

                std::cout << "You have: " << this->playerDeck.size() << " cards." << std::endl;                
                std::cout << "The computer has: " << this->computerDeck.size() << " cards." << std::endl;

                
            }else if(battleValue > 0){
                std::cout << "You have the high card." << std::endl;

                while ((cHand.size() + pHand.size()) > 0){
                    this->playerDeck.push_front(cHand.top());
                    cHand.pop();
                    this->playerDeck.push_front(pHand.top());
                    pHand.pop();
                }

                std::cout << "You have: " << this->playerDeck.size() << " cards." << std::endl;                
                std::cout << "The computer has: " << this->computerDeck.size() << " cards." << std::endl;

                
            }

            if(hasWon = GameOver(this->playerDeck.size(), this->computerDeck.size())){
                break;
            }

            //choose to continue if not game over, otherwise... break???

            if(!autoPlay){
                std::cout << "Press P to play a card, press F to forfiet the game." << std::endl;
                std::cin >> input;
                if(input.compare("F") == 0 || input.compare("f") == 0){
                    break;
                }
            }
            

        }
    }

    if (hasWon)
    {
        //Output of winner here.
        if(this->playerDeck.size() == 0){
            std::cout << "You Lose!!!" << std::endl;
        }else{
            std::cout << "You Win!!!" << std::endl;
        }

        std::cout << "This game took: " << rounds << " rounds!" << std::endl;
    }else{
        std::cout << "The game has been forfeit with a score of " << this->playerDeck.size() <<" (you) to " << this->computerDeck.size() << " (cpu)." << std::endl;
    }
    
}



void War::Deal(Deck &deck){

    std::cout << "Dealing the deck..." << std::endl;

    int deckSize = ((Card::Suit::SPADE + 1) * (Card::Value::ACE + 1));

    for (int i = 0; i < deckSize/2; i++)
    {
        this->playerDeck.push_back(deck.draw());
        //std::cout << "Player got";
        //this->playerHand.top()->print();

        this->computerDeck.push_back(deck.draw());
        //std::cout << "Comp got";
        //this->computerHand.top()->print();
    }
}

bool War::GameOver(int p, int c){
    if(p == 0 || c == 0)
        return true;
    return false;
}