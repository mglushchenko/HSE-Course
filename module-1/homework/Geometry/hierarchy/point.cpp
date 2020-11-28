#include <cmath>
#include <vector>
#include "line.h"

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

double Point::distTo(const Point& other) const {
    return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}

void Point::rotate(Point center, double angle) {
    double angleInRadians = angle * PI / 180;

    x -= center.x;
    y -= center.y;

    double sine = sin(angleInRadians);
    double cosine = cos(angleInRadians);
    double xRotated = x * cosine - y * sine;
    double yRotated = x * sine  + y * cosine;

    x = xRotated + center.x;
    y = yRotated + center.y;
}

void Point::reflex(Point center) {
    x = 2 * center.x - x;
    y = 2 * center.y - y;
}

void Point::reflex(Line axis) {
    std::vector<double> lineCoeffs = axis.getEquationCoeffs();
    double a = lineCoeffs[0], b = lineCoeffs[1], c = lineCoeffs[2];
    double ratio = -(a * x + b * y + c) / (a*a + b*b);
    double xIntersect = ratio * a + x;
    double yIntersect = ratio * b + y;

    reflex(Point(xIntersect, yIntersect));
}

void Point::scale(Point center, double coefficient) {
    double diffX = x - center.x;
    double diffY = y - center.y;

    x += diffX * coefficient;
    y += diffY * coefficient;
}
