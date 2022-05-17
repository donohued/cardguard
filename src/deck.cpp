#include <iostream>
#include <random>
#include <algorithm>
#include <stack>

#include "deck.h"

static std::random_device rd;
static std::mt19937 rng(rd());

Deck::Deck(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            Card *card = new Card((Card::Suit)i, (Card::Value)j);
            this->deck.push_back(card);
        }
    }
}

Deck::~Deck(){
    for (int i = 0; i < this->deck.size(); i++)
    {
        delete this->deck[i];
    }
}

Card* Deck::draw(){
    Card* top = this->shuffled.top();
    this->shuffled.pop();
    return top;
}

void Deck::shuffle(){

    while(this->shuffled.size() > 0){
        this->shuffled.pop();
    }

    std::shuffle(this->deck.begin(), this->deck.end(), rng);

    for(int i = 0; i < this->deck.size(); i++){
        this->shuffled.push(this->deck[i]);
    }

}