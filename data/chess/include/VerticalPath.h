#ifndef VERTICALPATHCHECKER_H
#define VERTICALPATHCHECKER_H

#include <IPathChecker.h>
#include <vector>

class VerticalPath : public IPathChecker {
 public:
        VerticalPath() {}
        virtual ~VerticalPath() {}

    bool pathClear(Coordinate* start, Coordinate* destination,
                       std::vector<std::vector<Piece*>> board);
};

#endif // VERTICALPATHCHECKER_H
