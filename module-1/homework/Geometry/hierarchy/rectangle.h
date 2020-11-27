#include "polygon.h"

class Rectangle: Polygon {
public:
    Rectangle(Point p1, Point p2, double ratio);

    double perimeter() const override;

    double area() const override;

private:
    double a, b;
};