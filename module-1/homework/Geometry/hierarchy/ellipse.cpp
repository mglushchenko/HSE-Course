#include <utility>
#include <cmath>
#include "ellipse.h"

Ellipse::Ellipse(Point f1, Point f2, double focDist) {
    this->f1 = f1;
    this->f2 = f2;
    this->focDist = focDist;

    a = focDist / 2;
    c = f1.distTo(f2) / 2;
    b = sqrt(a*a - c*c);
}

double Ellipse::eccentricity() const {
    return c / a;
}

Point Ellipse::center() const {
    double x = (f1.x + f2.x) / 2;
    double y = (f1.y + f2.y) / 2;
    return Point(x, y);
}

std::pair<Line, Line> Ellipse::directrices() const {
    double ecc = eccentricity();
    double x1 = a / ecc;
    double x2 = -a / ecc;

    // directrices are vertical, so we can take arbitrary values for y
    Point p11 = Point(x1, 0);
    Point p12 = Point(x1, 1);
    Line d1 = Line(p11, p12);

    Point p21 = Point(x2, 0);
    Point p22 = Point(x2, 1);
    Line d2 = Line(p21, p22);

    return std::make_pair(d1, d2);
}

double Ellipse::perimeter() const {
    return 4 * (PI * a * b + (a - b)) / (a + b);
}

double Ellipse::area() const {
    return PI * a * b;
}

// has to be done with dynamic_cast because overriding in C++ doesn't work with covariance of parameter types
bool Ellipse::operator==(const Shape& other) const {
    Ellipse e = dynamic_cast<const Ellipse&>(other);
    return f1 == e.f1 && f2 == e.f2 && focDist == e.focDist;
}

bool Ellipse::isCongruentTo(const Shape& other) const {
    Ellipse e = dynamic_cast<const Ellipse&>(other);
    return a == e.a && b == e.b;
}

bool Ellipse::isSimilarTo(const Shape& other) const {
    Ellipse e = dynamic_cast<const Ellipse&>(other);
    return eccentricity() == e.eccentricity();
}

bool Ellipse::containsPoint(Point point) const {
    double xc = center().x;
    double yc = center().y;

    double equationRes = pow(point.x - xc, 2) / pow(a, 2) + pow(point.y - yc, 2) / pow(b, 2);
    return equationRes <= 1;
}

void Ellipse::rotate(Point center, double angle) {
    f1.rotate(center, angle);
    f2.rotate(center, angle);
}

void Ellipse::reflex(Point center) {
    f1.reflex(center);
    f2.reflex(center);
}

void Ellipse::reflex(Line axis) {
    f1.reflex(axis);
    f2.reflex(axis);
}

void Ellipse::scale(Point center, double coefficient) {
    f1.scale(center, coefficient);
    f2.scale(center, coefficient);

    focDist *= coefficient;
    a *= coefficient;
    b *= coefficient;
    c *= coefficient;
}


