#ifndef POINT_H
#define POINT_H

struct Line;

struct Point {
    double PI = 3.1415926;

    double x;
    double y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    Point(const Point& other) {
        x = other.x;
        y = other.y;
    }

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    double distTo(const Point& other) const;

    void rotate(Point center, double angle);

    void reflex(Point center);

    void reflex(Line axis);

    void scale(Point center, double coefficient);
};

#endif