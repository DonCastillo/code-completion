#ifndef DIAGONALPATH_H
#define DIAGONALPATH_H

#include <IPathChecker.h>
#include <vector>

class DiagonalPath : public IPathChecker {
 public:
        DiagonalPath() {}
        virtual ~DiagonalPath() {}
    bool pathClear(Coordinate* start, Coordinate* destination,
                       std::vector<std::vector<Piece*>> board);
};

#endif // DIAGONALPATH_H
