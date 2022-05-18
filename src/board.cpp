#include <iostream>
#include <string>

#include "board.h"

using namespace std;


Board::Board(int size)
{
    this->size = size;

    this->tileBoard.resize(size);
    for (int i = 0; i < size; i++){
        this->tileBoard[i].resize(size);
    }
    
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            Tile *tile = new Tile(i, j);
            this->tileBoard[i][j] = tile;
        }
    }
}

Board::~Board(){

}

void Board::print(){

    std::string output;

    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            std::cout << this->tileBoard[i][j]->getValue() << " ";
        }
        std::cout << std::endl;
    }
    
}

