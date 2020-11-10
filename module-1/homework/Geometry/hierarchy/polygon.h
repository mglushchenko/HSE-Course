#include "shape.h"
#include <vector>

class Polygon: Shape {
public:
    Polygon(std::vector<Point>& points) {
        _vertices = points;
    }

    int verticesCount() const {
        return _vertices.size();
    }

    std::vector<Point> getVertices() const {
        return _vertices;
    }

    virtual bool isConvex() const;
private:
    std::vector<Point> _vertices;
};