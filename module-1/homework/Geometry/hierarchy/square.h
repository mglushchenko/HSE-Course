#include "rectangle.h"
#include "circle.h"

class Square: Rectangle {
public:
    Square(Point p1, Point p2);

    Circle circumscribedCircle();

    Circle inscribedCircle();
};