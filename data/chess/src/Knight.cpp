#include "Knight.h"

bool Knight::isValidMove(Coordinate* start, Coordinate* destination,
    std::vector<std::vector<Piece*>>* board) {

    unsigned int horizontal = abs(start->getX()-destination->getX());
    unsigned int vertical = abs(start->getY()-destination->getY());
    return (horizontal == 2 && vertical == 1) || (horizontal == 1 && vertical == 2);
}
