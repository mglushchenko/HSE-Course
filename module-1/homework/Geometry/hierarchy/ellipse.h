#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class Ellipse: public Shape {
public:
    Ellipse(Point f1, Point f2, double focDist);

    std::pair<Point,Point> focuses() const {
        return std::make_pair(f1, f2);
    }

    std::pair<Line, Line> directrices() const;

    double eccentricity() const;

    Point center() const;

    double perimeter() const override;

    double area() const override;

    bool operator==(const Shape& other) const override;

    bool isCongruentTo(const Shape& other) const override;

    bool isSimilarTo(const Shape& other) const override;

    bool containsPoint(Point point) const override;

    void rotate(Point center, double angle) override;

    void reflex(Point center) override;

    void reflex(Line axis) override;

    void scale(Point center, double coefficient) override;

protected:
    // called implicitly only during circle initialization
    Ellipse() = default;

private:
    Point f1;
    Point f2;
    double focDist;

    // half-axis
    double a, b;

    // focal distance
    double c;
};

#endif