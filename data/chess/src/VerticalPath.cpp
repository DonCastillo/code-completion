#include "VerticalPath.h"

bool VerticalPath::pathClear(Coordinate* start, Coordinate* destination, std::vector<std::vector<Piece*>> board) {

    bool vertical = (start->getX() == destination->getX()) && (abs(start->getY() - destination->getY()) >= 1);
    if(!vertical){
        return false;
    }

    int yOffset = (destination->getY() < start->getY()) ? -1 : 1;

    for(unsigned int y = start->getY() + yOffset;
            y != destination->getY(); y+= yOffset) {
        if(board[start->getX()][y]->getSide() != Colour::NONE)
            return false;
    }
    return true;
}
