#include "shape.h"

class Ellipse: Shape {
public:
    Ellipse(Point f1, Point f2, double focDist);

    std::pair<Point,Point> focuses() {
        return std::make_pair(f1, f2);
    }

    std::pair<Line, Line> directrices();

    double eccentricity();

    Point center();

private:
    Point f1;
    Point f2;
    double focDist;
};