#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"
#include "circle.h"

class Square: Rectangle {
public:
    Square(Point p1, Point p2);

    Circle circumscribedCircle() const;

    Circle inscribedCircle() const;
};

#endif