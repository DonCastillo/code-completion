#ifndef IPATHCHECKER_H
#define IPATHCHECKER_H

#include "Coordinate.h"
#include "Piece.h"
#include <vector>

class IPathChecker {
 public:
    IPathChecker() {}
    virtual ~IPathChecker() {}
    virtual bool pathClear(Coordinate* start, Coordinate* destination,
                       std::vector<std::vector<Piece*>> board) = 0;
};

#endif // IPATHCHECKER_H
