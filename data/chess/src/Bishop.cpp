#include "Bishop.h"

bool Bishop::isValidMove(Coordinate* start, Coordinate* destination,
        std::vector<std::vector<Piece*>>* board){

    return dChecker->pathClear(start, destination, *board);
}
