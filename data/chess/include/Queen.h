#ifndef QUEEN_H
#define QUEEN_H

#include <vector>
#include <Piece.h>
#include "CompositePathChecker.h"
#include <HorizontalPath.h>
#include <VerticalPath.h>
#include <DiagonalPath.h>

class Queen : public Piece {
 public:
    Queen(Colour colour) : Piece(colour) {}
    virtual ~Queen() {
      delete checker;
    }

    bool isValidMove(Coordinate* start, Coordinate* destination,
                     std::vector<std::vector<Piece*>>* board);

            char getSymbol() const {
             if (side == Colour::WHITE) {
                return 'q';
            } else {
                return 'Q';
            }
        }


 private:
    IPathChecker* checker = new CompositePathChecker(new HorizontalPath(),
      new CompositePathChecker(new VerticalPath(), new DiagonalPath()));
};

#endif // QUEEN_H
