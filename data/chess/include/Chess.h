#ifndef CHESS_H
#define CHESS_H

#include <vector>
#include <string>
#include "Exceptions.h"
#include "Coordinate.h"
#include "Board.h"

class Chess {
 public:
    Chess();
    virtual ~Chess();

    /**
    * Place the pieces in their starting positions on the board.
    */
    void setup();

    /**
    * Start the game.
    */
    void playGame();

    Board* getBoard() {
        return board;
    }

 private:
    Board* board;
};
#endif // CHESS_H
