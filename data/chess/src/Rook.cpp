#include "Rook.h"

bool Rook::isValidMove(Coordinate* start, Coordinate* destination,
            std::vector<std::vector<Piece*>>* board) {

            return checker->pathClear(start, destination, *board);
}
