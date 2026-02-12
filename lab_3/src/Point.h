#pragma once

#include <cmath>

class Point {
public:
    int x;
    int y;

public:
    double len(Point p) {
        return sqrt(pow((p.x - this->x),2) + pow((p.y - this->y),2));
    }
};
