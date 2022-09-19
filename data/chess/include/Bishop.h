#ifndef BISHOP_H
#define BISHOP_H

#include <vector>
#include <Queen.h>
#include "DiagonalPath.h"

class Bishop : public Piece {
 public:
    Bishop(Colour colour) : Piece(colour) {}

    virtual ~Bishop() {
        delete dChecker;
    }

    bool isValidMove(Coordinate* start, Coordinate* destination,
        std::vector<std::vector<Piece*>>* board);

        char getSymbol() const {
             if (side == Colour::WHITE) {
                return 'b';
            } else {
                return 'B';
            }
        }
 private:
    IPathChecker* dChecker = new DiagonalPath();
};

#endif // BISHOP_H
