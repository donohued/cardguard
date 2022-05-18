#ifndef BOARD_H
#define BOARD_H
#include <vector>

#include "deck.h"
#include "tile.h"

class Board
{
public:
    Board(int size);
    ~Board();

public:
    void print();
    void setTile(int x, int y, Card *card);
    void getTile();

protected:
    int size;
    std::vector<std::vector<Tile*>> tileBoard;
};

#endif