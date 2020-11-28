#include "polygon.h"

class Rectangle: public Polygon {
public:
    Rectangle(Point p1, Point p2, double ratio);

    double perimeter() const override;

    double area() const override;

    Point center();

    std::pair<Line, Line> diagonals();

protected:
    // long and short side lengths
    double a, b;
};