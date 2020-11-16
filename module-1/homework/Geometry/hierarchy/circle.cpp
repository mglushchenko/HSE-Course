#include "circle.h"

Circle::Circle(Point center, double radius) {
    this->center = center;
    this->_radius = radius;
}

double Circle::perimeter() const {
    return 2 * PI * _radius;
}

double Circle::area() const {
    return PI * _radius * _radius;
}

bool Circle::operator==(const Shape& other) const {
    Circle c = dynamic_cast<const Circle&>(other);
    return center == c.center && _radius == c._radius;
}

bool Circle::isCongruentTo(const Shape &other) const {
    Circle c = dynamic_cast<const Circle&>(other);
    return _radius == c._radius;
}

// all circles are similar by nature
bool Circle::isSimilarTo(const Shape &other) const {
    return true;
}

bool Circle::containsPoint(Point point) const {
    return point.distTo(center) <= _radius;
}

void Circle::rotate(Point center, double angle) {
    this->center.rotate(center, angle);
}

void Circle::reflex(Point center) {
    this->center.reflex(center);
}

void Circle::reflex(Line axis) {
    center.reflex(axis);
}

// TODO: does it work like this??
void Circle::scale(Point center, double coefficient) {
    if (center != this->center) {
        _radius *= coefficient;
    }
}
