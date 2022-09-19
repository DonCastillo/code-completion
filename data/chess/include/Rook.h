#ifndef ROOK_H
#define ROOK_H

#include <vector>
#include "CompositePathChecker.h"
#include <HorizontalPath.h>
#include <VerticalPath.h>

class Rook : public Piece {
 public:
        Rook(Colour colour) : Piece(colour) {}

        virtual ~Rook() {
            delete checker;
        }

        bool isValidMove(Coordinate* start, Coordinate* destination,
            std::vector<std::vector<Piece*>>* board);

        char getSymbol() const {
             if (side == Colour::WHITE) {
                return 'r';
            } else {
                return 'R';
            }
        }

 private:
    IPathChecker* checker = new CompositePathChecker(new HorizontalPath(),
        new VerticalPath());
};

#endif // ROOK_H
