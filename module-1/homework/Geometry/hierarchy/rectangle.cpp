#include <cmath>
#include "rectangle.h"

Rectangle::Rectangle(Point p1, Point p2, double ratio) {
    _vertices.push_back(p1);
    double d = p1.distTo(p2);
    a = sqrt(pow(d, 2) / pow(ratio, 2) - 1);
    b = ratio * a;

    double sine = a / d;
    double cosine = b / d;

    double diffX = p2.x - p1.x;
    double diffY = p2.y - p1.y;

    double upperRightX = a * (diffX * sine + diffY * cosine) / d;
    double upperRightY = a * (diffY * sine - diffX * cosine) / d;
    Point upperRight = Point(upperRightX, upperRightY);

    double lowerLeftX = b * (diffX * cosine - diffY * sine) / d;
    double lowerLeftY = b * (diffY * cosine + diffX * sine) / d;
    Point lowerLeft = Point(lowerLeftX, lowerLeftY);

    _vertices = {p1, lowerLeft, p2, upperRight};
}

double Rectangle::perimeter() const {
    return 2 * (a + b);
}

double Rectangle::area() const {
    return a * b;
}

Point Rectangle::center() const {
    double centerX = (_vertices[0].x + _vertices[2].x) / 2;
    double centerY = (_vertices[0].y + _vertices[2].y) / 2;
    return Point(centerX, centerY);
}

std::pair<Line, Line> Rectangle::diagonals() const {
    return std::make_pair(Line(_vertices[0], _vertices[2]), Line(_vertices[1], _vertices[3]));
}
