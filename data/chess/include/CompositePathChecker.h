#ifndef COMPOSITEPATHCHECKER_H
#define COMPOSITEPATHCHECKER_H

#include <IPathChecker.h>
#include <vector>

class CompositePathChecker : public IPathChecker {
 public:
        CompositePathChecker(IPathChecker* pc1, IPathChecker* pc2);
        virtual ~CompositePathChecker();

    bool pathClear(Coordinate* start, Coordinate* destination,
                       std::vector<std::vector<Piece*>> board);

 private:
    IPathChecker* checker1;
    IPathChecker* checker2;
};

#endif // COMPOSITEPATHCHECKER_H
