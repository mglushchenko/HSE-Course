#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"

class Rectangle: public Polygon {
public:
    Rectangle(Point p1, Point p2, double ratio);

    double perimeter() const override;

    double area() const override;

    Point center() const;

    std::pair<Line, Line> diagonals() const;

protected:
    // long and short side lengths
    double a, b;
};

#endif