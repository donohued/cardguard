#include <iostream>
#include <string>

#include "tile.h"

Tile::Tile(int x, int y){
    this->posx = x;
    this->posy = y;
    this->value = rand() % 89 + 10;
}

Tile::~Tile(){

}

int Tile::getValue(){

    return this->value;
}

