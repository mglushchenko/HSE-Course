#include "polygon.h"
#include "circle.h"

class Triangle: Polygon {
    Circle circumscribedCircle() const;

    Circle inscribedCircle() const;

private:
    Point intersection(const Line& v1, const Line& v2) const;
};