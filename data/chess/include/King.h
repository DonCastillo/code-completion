#ifndef KING_H
#define KING_H

#include <Piece.h>
#include "HorizontalPath.h"
#include <vector>


class King : public Piece {
 public:
    King(Colour colour);
    virtual ~King();
    bool isValidMove(Coordinate* start, Coordinate* destination,
                     std::vector<std::vector<Piece*>>* board);

    /**
    * Check if a King piece is in check.
    * @param board The game board.
    * @param kingCoord The coordinate of the King piece to check.
    * @return true If the King piece is in check, false otherwise.
    */
    bool isCheck(std::vector<std::vector<Piece*>>* board,
        Coordinate* kingCoord);

           char getSymbol() const {
             if (side == Colour::WHITE) {
                return 'k';
            } else {
                return 'K';
            }
        }

    void updateLocation(Coordinate* c);

 private:
    bool kingMoved;
    Coordinate* location;
    IPathChecker* pathChecker;
};

#endif // KING_H
