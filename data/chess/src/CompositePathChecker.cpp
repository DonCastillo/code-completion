#include "CompositePathChecker.h"

CompositePathChecker::CompositePathChecker(IPathChecker* pc1, IPathChecker* pc2) :
    checker1{pc1} , checker2{pc2} {}


CompositePathChecker::~CompositePathChecker() {
    delete checker1;
    delete checker2;
}

bool CompositePathChecker::pathClear(Coordinate* start, Coordinate* destination,
                       std::vector<std::vector<Piece*>> board){
    return checker1->pathClear(start,destination,board) || checker2->pathClear(start,destination,board);
}
