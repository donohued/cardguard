#ifndef TILE_H
#define TILE_H
#include <vector>

#include "deck.h"

class Tile
{
public:
    Tile(int x, int y);
    ~Tile();

public:
    int getValue();

protected:
    int posx;
    int posy;
    int value;

    Card* card;

private:
};

#endif