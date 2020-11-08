struct Point {
    double x;
    double y;

    bool operator==(const Point& other);
    bool operator!=(const Point& other);
};