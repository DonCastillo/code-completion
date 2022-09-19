#ifndef KNIGHT_H
#define KNIGHT_H

#include <Piece.h>
#include <vector>

class Knight : public Piece {
 public:
  Knight(Colour colour) : Piece(colour) {}
  virtual ~Knight() {}
  bool isValidMove(Coordinate* start, Coordinate* destination,
      std::vector<std::vector<Piece*>>* board);

          char getSymbol() const {
             if (side == Colour::WHITE) {
                return 'k';
            } else {
                return 'K';
            }
        }
};
#endif // KNIGHT_H
