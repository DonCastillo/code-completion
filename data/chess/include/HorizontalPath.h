#ifndef HORIZONTALPATH_H
#define HORIZONTALPATH_H

#include <IPathChecker.h>
#include <vector>

class HorizontalPath : public IPathChecker {
 public:
        HorizontalPath() {}
        virtual ~HorizontalPath() {}

    bool pathClear(Coordinate* start, Coordinate* destination,
                       std::vector<std::vector<Piece*>> board);
};

#endif // HORIZONTALPATH_H
