#include "Chess.h"
#include <iostream>
#include <cmath>

Chess::Chess() {
    board = new Board(8);
}

Chess::~Chess(){
    delete board;
}

void Chess::setup() {
    // White pieces
    Coordinate* c = new Coordinate(0, 0);
    board->placePiece(new Rook(Colour::WHITE), c);
    delete c;
    c = new Coordinate(1, 0);
    board->placePiece(new Knight(Colour::WHITE), c);
    delete c;
    c = new Coordinate(2, 0);
    board->placePiece(new Bishop(Colour::WHITE), c);
    delete c;
    c = new Coordinate(3, 0);
    board->placePiece(new Queen(Colour::WHITE), c);
    delete c;
    c = new Coordinate(4, 0);
    board->placePiece(new King(Colour::WHITE), c);
    delete c;
    c = new Coordinate(5, 0);
    board->placePiece(new Bishop(Colour::WHITE), c);
    delete c;
    c = new Coordinate(6, 0);
    board->placePiece(new Knight(Colour::WHITE), c);
    delete c;
    c = new Coordinate(7, 0);
    board->placePiece(new Rook(Colour::WHITE), c);
    delete c;

    for(int x=0; x<8; ++x) {
        c = new Coordinate(x, 1);
        board->placePiece(new Pawn(Colour::WHITE), c);
        delete c;
    }

    // Black pieces
    c = new Coordinate(0, 7);
    board->placePiece(new Rook(Colour::BLACK), c);
    delete c;
    c = new Coordinate(1, 7);
    board->placePiece(new Knight(Colour::BLACK), c);
    delete c;
    c = new Coordinate(2, 7);
    board->placePiece(new Bishop(Colour::BLACK), c);
    delete c;
    c = new Coordinate(3, 7);
    board->placePiece(new Queen(Colour::BLACK), c);
    delete c;
    c = new Coordinate(4, 7);
    board->placePiece(new King(Colour::BLACK), c);
    delete c;
    c = new Coordinate(5, 7);
    board->placePiece(new Bishop(Colour::BLACK), c);
    delete c;
    c = new Coordinate(6, 7);
    board->placePiece(new Knight(Colour::BLACK), c);
    delete c;
    c = new Coordinate(7, 7);
    board->placePiece(new Rook(Colour::BLACK), c);
    delete c;

    for(int x=0; x<8; ++x) {
        c = new Coordinate(x, 6);
        board->placePiece(new Pawn(Colour::BLACK), c);
        delete c;
    }
}

void Chess::playGame() {
    setup();
    bool over = false;
    Colour side = Colour::WHITE;
    std::string player;
    std::string source, destination;
    do {
        board->draw();
        player = (side == Colour::WHITE) ? "White" : "Black";
        std::cout << "[" + player + "]: Enter location of piece to move: ";
        std::cin >> source;
        std::cout << "[" + player + "]: Enter location of destination: ";
        std::cin >> destination;

        Coordinate* sourceSquare = new Coordinate(source);
        Coordinate* destinationSquare = new Coordinate(destination);

        if(board->movePiece(side, sourceSquare, destinationSquare)) {
            Piece* piece = board->getPiece(destinationSquare);
            Pawn* pawn = dynamic_cast<Pawn*>(piece);
            if(pawn != nullptr && pawn->promotable()) {
                std::string response;
                bool responseValid = false;
                do {
                    std::cout << "Do you want to promote your pawn? [Y/N]: ";
                    std::cin >> response;
                    if(response[0] == 'Y' || response[0] == 'N') {
                        responseValid = true;
                    } else {
                        std::cout << "Please enter either 'Y' or 'N'." << std::endl;
                    }
                } while(!responseValid);

                if(response[0] == 'Y') {
                    bool responseValid = false;
                    do {
                        std::cout << "What do you want to promote the pawn to? [Q,R,B,N]: ";
                        std::cin >> response;
                        if(response[0] == 'Q' || response[0] == 'R' || response[0] == 'B' || response[0] == 'N') {
                            delete piece;
                            responseValid = true;
                            switch(response[0]) {
                            case 'B': {
                                board->placePiece(new Bishop(side), destinationSquare);
                                break;
                            }
                            case 'R': {
                                board->placePiece(new Rook(side), destinationSquare);
                                break;
                            }
                            case 'N': {
                                board->placePiece(new Knight(side), destinationSquare);
                                break;
                            }
                            default:
                            case 'Q': {
                                board->placePiece(new Queen(side), destinationSquare);
                            }
                            }
                        } else {
                            std::cout << "Please enter either 'Q','R','B' or 'N'." << std::endl;
                        }
                    } while(!responseValid);
                }
            }
            side = (side == Colour::WHITE) ? Colour::BLACK : Colour::WHITE;
            if(board->checkmate(side)) {
                over = true;
            }
        } else {
            std::cerr << "Not a valid move. Please try again." << std::endl;
        }

    } while(!over);
    std::cout << "Game over! " << ((side == Colour::WHITE) ? "White" : "Black") << " checkmated " << ((side == Colour::WHITE) ? "Black" : "White") << ".";
}
