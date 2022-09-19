#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include <vector>

class Board {
 public:
    Board() : Board(8) {}
    Board(unsigned int size);
    virtual ~Board();

    /**
    *   Move a piece on the board.
    *   @param side Colour of the side moving the piece.
    *   @param start The coordinate of the piece to move.
    *   @param destination The coordinate of where to move the piece.
    *   @return true if the move is valid, false otherwise.
    *   @throw invalid_location_error One of the locations is
    *       off of the board.
    *   @throw invalid_piece_error The player tried to move the
    *       other player's piece.
    *   @throw no_piece_error The player selected a board location that has no piece.
    */
    virtual bool movePiece(Colour side, Coordinate* start,
      Coordinate* destination);

    /**
    * Place a piece at a location on the board.
    * @param p The piece.
    * @param c A coordinate on the board.
    */
    virtual void placePiece(Piece* p, Coordinate* c);

    /**
    * Clear a location on the board.
    * @param c A coordinate on the board.
    */
    virtual void emptySpace(Coordinate* c);

    /**
    * Get the piece at location c.
    * @param c A location on the chessboard.
    */
    virtual Piece* getPiece(Coordinate* c);

    /**
    * Check if a player is checkmated.
    * @param side The player to check.
    */
    virtual bool checkmate(Colour side);

    /**
    * Draw the board.
    */
    void draw();

    std::vector<std::vector<Piece*>>* getBoard() {
        return &board;
    }

 protected:
    unsigned int size;
    std::vector<std::vector<Piece*>> board;
};

#endif // BOARD_H
