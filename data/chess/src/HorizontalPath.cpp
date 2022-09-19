#include "HorizontalPath.h"

bool HorizontalPath::pathClear(Coordinate* start, Coordinate* destination, std::vector<std::vector<Piece*>> board) {

    bool horizontal = (start->getY() == destination->getY()) && (abs(start->getX() - destination->getX()) >= 1);
    if(!horizontal) {
        return false;
    }

    int xOffset = (destination->getX() < start->getX()) ? -1 : 1;

    for(unsigned int x = start->getX() + xOffset;
            x != destination->getX(); x+= xOffset) {
        Piece* square = board[x][start->getY()];
        if(square->getSide() != Colour::NONE)
            return false;
    }
    return true;
}
