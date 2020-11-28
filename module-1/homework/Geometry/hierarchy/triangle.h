#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"
#include "circle.h"

class Triangle: public Polygon {
public:
    Triangle(Point p1, Point p2, Point p3);

    double area() const override;

    Circle circumscribedCircle() const;

    Circle inscribedCircle() const;

private:
    Point intersection(const Line& v1, const Line& v2) const;
};

#endif