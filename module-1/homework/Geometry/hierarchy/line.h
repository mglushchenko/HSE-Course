#include "point.h"

struct Line {
    Point p1;
    Point p2;

    bool operator==(const Line& other);
    bool operator!=(const Line& other);
};