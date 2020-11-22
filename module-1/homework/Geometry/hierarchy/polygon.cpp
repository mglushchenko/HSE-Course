#include "polygon.h"

bool Polygon::isConvex() const {
    return false;
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
        res += _vertices[i].y * _vertices[i + 1].x;
    }
    res += _vertices[verticesCnt - 1].y * _vertices[0].x;

    return res;
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

bool Polygon::isCongruentTo(const Shape &another) const {
    return false;
}

bool Polygon::isSimilarTo(const Shape &another) const {
    return false;
}

bool Polygon::containsPoint(Point point) const {
    return false;
}

void Polygon::scale(Point center, double coefficient) {
    for (Point& p: _vertices) {
        p.scale(center, coefficient);
    }
}


