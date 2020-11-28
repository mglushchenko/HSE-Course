#include <cmath>
#include "triangle.h"

Triangle::Triangle(Point p1, Point p2, Point p3) {
    _vertices.emplace_back(p1);
    _vertices.emplace_back(p2);
    _vertices.emplace_back(p3);
}

Circle Triangle::circumscribedCircle() const {
    // find two center perpendiculars
    double middleX = (_vertices[0].x + _vertices[1].x) / 2;
    double middleY = (_vertices[0].y + _vertices[1].y) / 2;
    Point middle1 = Point(middleX, middleY);

    middleX = (_vertices[1].x + _vertices[2].x) / 2;
    middleY = (_vertices[1].y + _vertices[2].y) / 2;
    Point middle2 = Point(middleX, middleY);

    // using the fact that scalar product of 2 orthogonal vectors is 0
    Point vec1 = Point(_vertices[0].x - _vertices[1].x, _vertices[0].y - _vertices[1].y);
    Point vec2 = Point(_vertices[1].x - _vertices[2].x, _vertices[1].y - _vertices[2].y);

    Point perp1 = Point(vec1.y, -vec1.x);
    Point perp2 = Point(vec2.y, -vec2.x);

    Point end1 = Point(middle1.x + perp1.x, middle1.y + perp1.y);
    Point end2 = Point(middle2.x + perp2.x, middle2.y + perp2.y);

    Line centerPerp1 = Line(middle1, end1);
    Line centerPerp2 = Line(middle2, end2);

    // find intersection and radius
    Point center = intersection(centerPerp1, centerPerp2);
    double radius = center.distTo(_vertices[0]);
    return Circle(center, radius);
}

Circle Triangle::inscribedCircle() const {
    // find two bisectors
    double ratio = _vertices[0].distTo(_vertices[1]) / _vertices[1].distTo(_vertices[2]);
    double x = (_vertices[0].x + ratio * _vertices[2].x) / (1 + ratio);
    double y = (_vertices[0].y + ratio * _vertices[2].y) / (1 + ratio);
    Line bisector1 = Line(_vertices[1], Point(x, y));

    ratio = _vertices[0].distTo(_vertices[1]) / _vertices[0].distTo(_vertices[2]);
    x = (_vertices[1].x + ratio * _vertices[2].x) / (1 + ratio);
    y = (_vertices[1].y + ratio * _vertices[2].y) / (1 + ratio);
    Line bisector2 = Line(_vertices[0], Point(x, y));

    // find intersection
    Point center = intersection(bisector1, bisector2);

    // find radius
    double a = _vertices[0].distTo(_vertices[1]);
    double b = _vertices[1].distTo(_vertices[2]);
    double c = _vertices[2].distTo(_vertices[0]);

    double semiPerimeter = (a + b + c) / 2;

    double radius = sqrt((semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c) / semiPerimeter);

    return Circle(center, radius);
}

Point Triangle::intersection(const Line& v1, const Line& v2) const {
    std::vector<double> coeffs1 = v1.getEquationCoeffs();
    std::vector<double> coeffs2 = v2.getEquationCoeffs();

    double intersectX = (coeffs1[1] * coeffs2[2] - coeffs2[1] * coeffs1[2]) /
            (coeffs1[0] * coeffs2[1] - coeffs2[0] * coeffs1[1]);
    double intersectY = (coeffs2[0] * coeffs1[2] - coeffs1[0] * coeffs2[2]) /
            (coeffs1[0] * coeffs2[1] - coeffs2[0] * coeffs1[1]);

    return Point(intersectX, intersectY);
}

// Heron's formula
double Triangle::area() const {
    double a = _vertices[0].distTo(_vertices[1]);
    double b = _vertices[1].distTo(_vertices[2]);
    double c = _vertices[2].distTo(_vertices[0]);

    double s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}
