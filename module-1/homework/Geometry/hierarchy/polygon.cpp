#include <cmath>
#include "polygon.h"

bool Polygon::isConvex() const {
    Point p1 = _vertices[verticesCount() - 2];
    Point p2 = _vertices[verticesCount() - 1];
    Point p3 = _vertices[0];

    Point tmp1 = Point(p1.x - p2.x, p1.y - p2.y);
    Point tmp2 = Point(p3.x - p2.x, p3.y - p2.y);
    bool sign = (tmp1.x * tmp2.y - tmp1.y * tmp2.x) < 0;

    for (size_t i = 1; i < verticesCount(); ++i) {
        p1 = p2;
        p2 = p3;
        p3 = _vertices[i];

        tmp1 = Point(p1.x - p2.x, p1.y - p2.y);
        tmp2 = Point(p3.x - p2.x, p3.y - p2.y);
        bool currSign = (tmp1.x * tmp2.y - tmp1.y * tmp2.x) < 0;

        if (sign != currSign) {
            return false;
        }
    }
    return true;
}

double Polygon::perimeter() const {
    double res = 0;
    for (int i = 1; i < verticesCount(); ++i) {
        res += _vertices[i].distTo(_vertices[i-1]);
    }
    res += _vertices[0].distTo(_vertices[verticesCount() - 1]);
    return res;
}

double Polygon::area() const {
    double res = 0;
    int verticesCnt = verticesCount();
    for (int i = 0; i < verticesCnt; ++i) {
        res += _vertices[i].x * _vertices[i + 1].y;
    }
    res += _vertices[verticesCnt - 1].x * _vertices[0].y;

    for (int i = 0; i < verticesCnt; ++i) {
        res -= _vertices[i].y * _vertices[i + 1].x;
    }
    res -= _vertices[verticesCnt - 1].y * _vertices[0].x;

    return fabs(res / 2);
}

bool Polygon::operator==(const Shape& another) const {
    Polygon p = dynamic_cast<const Polygon &>(another);
    if (verticesCount() != p.verticesCount()) {
        return false;
    }

    int verticesCnt = verticesCount();
    int matchNum = -1;
    for (int i = 0; i < verticesCnt; ++i) {
        if (p._vertices[i] == _vertices[0]) {
            matchNum = i;
            break;
        }
    }

    if (matchNum == -1) {
        return false;
    }

    for (int i = 0; i < verticesCnt; ++i) {
        if (_vertices[i] != p._vertices[matchNum]) {
            return false;
        }
        ++matchNum;
        if (matchNum >= verticesCnt) {
            matchNum = 0;
        }
    }
    return true;
}

void Polygon::rotate(Point center, double angle) {
    for (Point& p: _vertices) {
        p.rotate(center, angle);
    }
}

void Polygon::reflex(Point center) {
    for (Point& p: _vertices) {
        p.reflex(center);
    }
}

void Polygon::reflex(Line axis) {
    for (Point& p: _vertices) {
        p.reflex(axis);
    }
}

bool Polygon::isCongruentTo(const Shape& another) const {
    Polygon p = dynamic_cast<const Polygon &>(another);
    if (verticesCount() != p.verticesCount()) {
        return false;
    }

    std::vector<double> sides = getSides();
    std::vector<double> otherSides = p.getSides();

    std::vector<double> angles = getAngles();
    std::vector<double> otherAngles = p.getAngles();

    std::vector<int> matches;
    for (size_t i = 0; i < otherSides.size(); ++i) {
        if (approxEq(otherSides[i], sides[0])) {
            matches.emplace_back(i);
        }
    }

    for (int m: matches) {
        int matchNum = m;
        bool mismatch = false;
        for (size_t i = 0; i < sides.size(); ++i) {
            if (!approxEq(sides[i], otherSides[matchNum])  ||
                !approxEq(angles[i], otherAngles[matchNum])) {
                mismatch = true;
                break;
            }
            ++matchNum;
            if (matchNum >= sides.size()) {
                matchNum = 0;
            }
        }
        if (!mismatch) {
            return true;
        }
    }
    return false;
}

bool Polygon::isSimilarTo(const Shape& another) const {
    Polygon p = dynamic_cast<const Polygon &>(another);
    if (verticesCount() != p.verticesCount()) {
        return false;
    }

    std::vector<double> sides = getSides();
    std::vector<double> otherSides = p.getSides();

    std::vector<double> angles = getAngles();
    std::vector<double> otherAngles = p.getAngles();

    std::vector<int> matches;
    for (size_t i = 0; i < otherSides.size(); ++i) {
        if (approxEq(otherSides[i], sides[0])) {
            matches.emplace_back(i);
        }
    }

    double coeff = sides[0] / otherSides[0];

    for (int m: matches) {
        int matchNum = m;
        bool mismatch = false;
        for (size_t i = 0; i < sides.size(); ++i) {
            if (!approxEq(sides[i], otherSides[matchNum] * coeff)  ||
                !approxEq(angles[i], otherAngles[matchNum])) {
                mismatch = true;
                break;
            }
            ++matchNum;
            if (matchNum >= sides.size()) {
                matchNum = 0;
            }
        }
        if (!mismatch) {
            return true;
        }
    }
    return false;
}

bool Polygon::containsPoint(Point point) const {
    Point p1 = _vertices[verticesCount() - 1];
    Point p2 = _vertices[0];

    double currAngle = getAngle(point, p1, p2);
    for (size_t i = 1; i < verticesCount(); ++i) {
        p1 = _vertices[i - 1];
        p2 = _vertices[i];

        if (approxEq(p1.distTo(p2), p1.distTo(point) + p2.distTo(point))) {
            return true;
        }

        currAngle += getAngle(point, p1, p2);
    }

    return approxEq(currAngle, 2 * PI);
}

void Polygon::scale(Point center, double coefficient) {
    for (Point& p: _vertices) {
        p.scale(center, coefficient);
    }
}

std::vector<double> Polygon::getSides() const {
    std::vector<double> sides;
    for (int i = 1; i < verticesCount(); ++i) {
        sides.emplace_back(_vertices[i].distTo(_vertices[i - 1]));
    }
    sides.emplace_back(_vertices[0].distTo(_vertices[verticesCount() - 1]));
    return sides;
}

std::vector<double> Polygon::getAngles() const {
    std::vector<double> angles;
    angles.emplace_back(getAngle(_vertices[verticesCount() - 1], _vertices[0], _vertices[1]));
    for (int i = 1; i < verticesCount() - 1; ++i) {
        angles.emplace_back(getAngle(_vertices[i], _vertices[i - 1], _vertices[i + 1]));
    }
    angles.emplace_back(getAngle(_vertices[verticesCount() - 2], _vertices[verticesCount() - 1], _vertices[0]));
    return angles;
}

double Polygon::getAngle(Point vertex, Point p1, Point p2) const {
    double segLen1 = vertex.distTo(p1);
    double segLen2 = vertex.distTo(p2);
    double chordLen = p1.distTo(p2);

    double cosine = (pow(segLen1, 2) + pow(segLen2, 2) - pow(chordLen, 2)) / (2 * segLen1 * segLen2);
    return acos(cosine);
}

bool Polygon::approxEq(double val1, double val2) const {
    return fabs(val1 - val2) < EPS;
}


