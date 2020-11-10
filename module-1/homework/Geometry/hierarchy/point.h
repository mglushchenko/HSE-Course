struct Point {
    double x;
    double y;

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    bool operator==(const Point& other);
    bool operator!=(const Point& other);
};