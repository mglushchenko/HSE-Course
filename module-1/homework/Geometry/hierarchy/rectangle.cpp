#include <cmath>
#include "rectangle.h"

Rectangle::Rectangle(Point p1, Point p2, double ratio) {
    _vertices.push_back(p1);
    double d = p1.distTo(p2);
    double longSide = sqrt(pow(d, 2) / pow(ratio, 2) - 1);
    double shortSide = ratio * longSide;
    // ???
}

double Rectangle::perimeter() const {
    return 2 * (a + b);
}

double Rectangle::area() const {
    return a * b;
}
