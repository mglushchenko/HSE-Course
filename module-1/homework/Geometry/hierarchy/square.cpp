#include "square.h"

Square::Square(Point p1, Point p2)
        : Rectangle(p1, p2, 1) {

}

Circle Square::circumscribedCircle() const {
    Point centerPoint = center();
    double radius = _vertices[0].distTo(_vertices[2]) / 2;
    return Circle(centerPoint, radius);
}

Circle Square::inscribedCircle() const {
    Point centerPoint = center();
    double radius = a / 2;
    return Circle(centerPoint, radius);
}
