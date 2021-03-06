#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <vector>

struct Line {
    Point p1;
    Point p2;

    Line(Point p1, Point p2);

    bool operator==(const Line& other);
    bool operator!=(const Line& other);

    std::vector<double> getEquationCoeffs() const;
};

#endif