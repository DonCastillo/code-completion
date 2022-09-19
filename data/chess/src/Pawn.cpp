#include "Pawn.h"



bool Pawn::isValidMove(Coordinate* start, Coordinate* destination,
                       std::vector<std::vector<Piece*>>* board) {

    bool oneSpace = (side == Colour::WHITE) ? (destination->getY() - start->getY() == 1) : (start->getY() - destination->getY() == 1);
    bool twoSpace = false;
    if(abs(start->getY() - destination->getY()) == 2)
        twoSpace = (side == Colour::WHITE) ? start->getY() == 1 : start->getY() == 6;
    bool correctNumber = oneSpace || twoSpace;
    bool notSideways = (start->getX() == destination->getX());

    // Pawn promotion
    unsigned int backRank = (side == Colour::WHITE) ? 7 : 0;
    canPromote = destination->getY() == backRank;

    // Enpassant
    enPassantState = enPassant(start, destination, *board);// && !enPassantState;
    if(enPassantState) {
        int yOffset = (side == Colour::WHITE) ? -1 : 1;
        delete enPassantCoord;
        enPassantCoord = new Coordinate(destination->getX(), destination->getY() + yOffset);
    }

    Pawn* left;
    Pawn* right;
    unsigned int epRank = (side == Colour::WHITE) ? 4 : 3;
    right = (start->getX() != 0) ? dynamic_cast<Pawn*>((*board)[start->getX()-1][epRank]) : nullptr;
    left = (start->getX() != 7) ? dynamic_cast<Pawn*>((*board)[start->getX()+1][epRank]) : nullptr;


    bool enpassantValid = ((right != nullptr && *destination == *(right->enPassantCoord)) ||
                            (left != nullptr && *destination == *(left->enPassantCoord))) &&
                            (destination->getY() == 2 || destination->getY() == 5);

    if(enpassantValid) {
        int yOffset = (side == Colour::WHITE) ? -1 : 1;
        delete (*board)[destination->getX()][destination->getY()+yOffset];
        (*board)[destination->getX()][destination->getY()+yOffset] = new Piece(Colour::NONE);
    }

    bool capture = false;
    if(oneSpace && abs(start->getX()-destination->getX()) == 1) {
        capture = ((*board)[destination->getX()][destination->getY()]->getSide() != Colour::NONE) &&
                  (side != (*board)[destination->getX()][destination->getY()]->getSide());
    }

    if(!capture) {
        if((*board)[destination->getX()][destination->getY()]->getSide() != Colour::NONE) {
            return false;
        }
    }
    return (correctNumber && notSideways) || capture || enpassantValid;
}

bool Pawn::enPassant(Coordinate* start, Coordinate* destination, std::vector<std::vector<Piece*>> board) {

    bool whitePawnInitialTwo = start->getY() == 1 && destination->getY() == 3;
    bool blackPawnLeft = (start->getX() != 0) && (dynamic_cast<Pawn*>(board[start->getX()-1][3]) != nullptr);
    bool blackPawnRight = (start->getX() != 7) && (dynamic_cast<Pawn*>(board[start->getX()+1][3]) != nullptr);

    if(whitePawnInitialTwo && (blackPawnLeft || blackPawnRight)) {
        return true;
    }

    bool blackPawnInitialTwo = start->getY() == 6 && destination->getY() == 4;
    bool whitePawnRight = (start->getX() != 0) && (dynamic_cast<Pawn*>(board[start->getX()-1][4]) != nullptr);
    bool whitePawnLeft = (start->getX() != 7) && (dynamic_cast<Pawn*>(board[start->getX()+1][4]) != nullptr);

    if(blackPawnInitialTwo && (whitePawnLeft || whitePawnRight)) {
        return true;
    }
    return false;
}

bool Pawn::promotable() {
    return canPromote;
}
