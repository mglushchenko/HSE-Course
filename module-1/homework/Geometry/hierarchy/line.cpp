#include "line.h"

bool Line::operator==(const Line &other) {
    return (p1 == other.p1 && p2 == other.p2) ||
            (p1 == other.p2 && p2 == other.p1);
}

bool Line::operator!=(const Line &other) {
    return !(*this == other);
}
