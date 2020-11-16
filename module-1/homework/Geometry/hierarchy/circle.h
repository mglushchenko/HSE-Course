#include "ellipse.h"

class Circle: Ellipse {
public:
    Circle(Point center, double radius);

    double radius() const {
        return _radius;
    }

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

private:
    Point center;
    double _radius;
};