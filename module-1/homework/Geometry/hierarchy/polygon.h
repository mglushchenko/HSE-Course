#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include <vector>

class Polygon: public Shape {
public:
    Polygon() = default;

    Polygon(std::vector<Point>& points) {
        _vertices = points;
    }

    int verticesCount() const {
        return _vertices.size();
    }

    std::vector<Point> getVertices() const {
        return _vertices;
    }

    double perimeter() const override;

    double area() const override;

    bool isCongruentTo(const Shape& another) const override;

    bool isSimilarTo(const Shape& another) const override;

    bool containsPoint(Point point) const override;

    void rotate(Point center, double angle) override;

    void reflex(Point center) override;

    void reflex(Line axis) override;

    void scale(Point center, double coefficient) override;

    bool operator==(const Shape& another) const override;

    virtual bool isConvex() const;

protected:
    std::vector<Point> _vertices;

    std::vector<double> getSides() const;

    std::vector<double> getAngles() const;
    double getAngle(Point vertex, Point p1, Point p2) const;

    bool approxEq(double val1, double val2) const;
};

#endif