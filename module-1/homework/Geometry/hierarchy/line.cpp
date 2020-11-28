#include <vector>
#include "line.h"

bool Line::operator==(const Line &other) {
    return (p1 == other.p1 && p2 == other.p2) ||
            (p1 == other.p2 && p2 == other.p1);
}

bool Line::operator!=(const Line &other) {
    return !(*this == other);
}

Line::Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}

std::vector<double> Line::getEquationCoeffs() const {
    std::vector<double> coeffs;
    double a = p2.y - p1.y;
    coeffs.push_back(a);
    double b = p1.x - p2.x;
    coeffs.push_back(b);
    double c = -a * p1.x - b * p1.y;
    coeffs.push_back(c);
    return coeffs;
}
