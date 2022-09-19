#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

King::King(Colour colour) : Piece(colour) {
    kingMoved = false;
    location = nullptr;
    pathChecker = new HorizontalPath();
}

King::~King() {
    delete pathChecker;
}

bool King::isValidMove(Coordinate* start, Coordinate* destination,
                       std::vector<std::vector<Piece*>>* board) {

    if(isCheck(board, destination))
        return false;

    unsigned int diagonalX = abs(start->getX()-destination->getX());
    unsigned int diagonalY = abs(start->getY()-destination->getY());
    bool oneSquare = (diagonalX == 1) && (diagonalY == 1);
    bool diagonal = abs(diagonalX - diagonalY) == 0;

    bool horizontal = abs(start->getX() - destination->getX()) == 1;
    bool vertical = abs(start->getY() - destination->getY()) == 1;

    // Castling
    if (abs(start->getX() - destination->getX()) > 1 && !kingMoved) {
        unsigned int file = (side == Colour::WHITE) ? 0 : 7;
        if (start->getY() == file && (destination->getX() == 2 || destination->getX() == 6) &&
                pathChecker->pathClear(start, destination, *board)) {
            bool castle = true;
            if(start->getX() > destination->getX()) {
                for (unsigned int x=start->getX(); x>=destination->getX(); --x) {
                    Coordinate* c = new Coordinate(x, file);
                    if (isCheck(board, c)) {
                        castle = false;
                    }
                    delete c;
                }
            } else {
                for (unsigned int x=start->getX(); x<=destination->getX(); ++x) {
                    Coordinate* c = new Coordinate(x, file);
                    if (isCheck(board, c)) {
                        castle = false;
                    }
                    delete c;
                }
            }

            // Move rook
            if(castle) {
                unsigned int xRookOld = (destination->getX() == 2) ? 0 : 7;
                unsigned int xRookNew = (destination->getX() == 2) ? 3 : 5;
                Piece* rook = dynamic_cast<Rook*>((*board)[xRookOld][destination->getY()]);
                delete (*board)[xRookNew][destination->getY()];
                (*board)[xRookNew][destination->getY()] = rook;
                (*board)[xRookOld][destination->getY()] = new Piece(Colour::NONE);
            }
            return castle;
        }
    }

    return horizontal || vertical || (diagonal && oneSquare);
}

void King::updateLocation(Coordinate* c){

    if(location != nullptr){
        kingMoved = true;
    }
    location = c;
}

bool King::isCheck(std::vector<std::vector<Piece*>>* board, Coordinate* kingCoord) {

    bool check = false;
    for(unsigned int x = 0; x<board->size(); ++x) {
        for(unsigned int y = 0; y<(*board)[x].size(); ++y) {
            Piece* piece = (*board)[x][y];
            if(piece->getSide() == Colour::NONE) {
                continue;
            }
            bool isQueen = dynamic_cast<Queen*>(piece) != nullptr;
            bool isBishop = dynamic_cast<Bishop*>(piece) != nullptr;
            bool isKnight = dynamic_cast<Knight*>(piece) != nullptr;
            bool isRook = dynamic_cast<Rook*>(piece) != nullptr;
            bool isPawn = dynamic_cast<Pawn*>(piece) != nullptr;
            if(side != piece->getSide() && (isRook || isKnight ||
                                            isBishop || isQueen)) {
                Coordinate* c = new Coordinate(x, y);
                if(piece->isValidMove(c, kingCoord, board)) {
                    check = true;
                }
                delete c;
            } else if(isPawn) {
                // Simulate the king at the location for castle checking
                Piece* temp = (*board)[kingCoord->getX()][kingCoord->getY()];
                (*board)[kingCoord->getX()][kingCoord->getY()] = new King(side);
                Coordinate* c = new Coordinate(x, y);
                if(piece->isValidMove(c, kingCoord, board)) {
                    check = true;
                }
                delete c;
                delete (*board)[kingCoord->getX()][kingCoord->getY()];
                (*board)[kingCoord->getX()][kingCoord->getY()] = temp;
            }
        }
    }
    return check;
}

