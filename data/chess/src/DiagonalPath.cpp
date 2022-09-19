#include "DiagonalPath.h"

bool DiagonalPath::pathClear(Coordinate* start, Coordinate* destination, std::vector<std::vector<Piece*>> board) {

    unsigned int diagonalX = abs(start->getX()-destination->getX());
    unsigned int diagonalY = abs(start->getY()-destination->getY());
    bool diagonal = abs(diagonalX - diagonalY) == 0;
    if(!diagonal) {
        return false;
    }

    int xOffset = (destination->getX() < start->getX()) ? -1 : 1;
    int yOffset = (destination->getY() < start->getY()) ? -1 : 1;

    for(unsigned int x = start->getX() + xOffset, y = start->getY() + yOffset;
            x != destination->getX() || y != destination->getY(); x+= xOffset, y += yOffset) {
        if(board[x][y]->getSide() != Colour::NONE)
            return false;
    }
    return true;
}
