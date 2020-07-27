#include "Algorithms/Geometry/BezierCurve.h"
#include <cmath>
#include <vector>

std::vector<Point<double>> BezierCurve(const Point<int64_t> &p1, const Point<int64_t> &p2, const Point<int64_t> &p3) {
    int64_t first = p1.x, second = p2.x, third = p3.x;
    sortOf3(first, second, third);
    std::vector<Point<double>> BezierPoints;
    calculateBezierPoints(BezierPoints, first, second, p1, p2, p3);
    calculateBezierPoints(BezierPoints, second + 1, third, p1, p2, p3);
    return BezierPoints;
}

void calculateBezierPoints(std::vector<Point<double>> &BezierPoints, int64_t from, int64_t to,
                           const Point<int64_t> &p1, const Point<int64_t> &p2, const Point<int64_t> &p3) {
    int64_t x1 = p1.x, x2 = p2.x, x3 = p3.x;
    int64_t a = x1 - 2 * x2 + x3;
    int64_t b = 2 * (x2 - x1);
    int64_t c;
    double t1, t2;
    for(int64_t x = from; x <= to; ++x) {
        c = x1 - x;
        squareRoots(a, b, c, t1, t2);
        if(t1 >= 0 && t1 <= 1)
            BezierPoints.push_back({static_cast<double>(x), calculateY(t1, p1, p2, p3)});
        else
            BezierPoints.push_back({static_cast<double>(x), calculateY(t2, p1, p2, p3)});
    }
}

void squareRoots(int64_t a, int64_t b, int64_t c, double &x1, double &x2) {
    if(a == 0) {
        if(b == 0)
            throw std::runtime_error("squareRoots. a and b is zero");
        x1 = x2 = -(static_cast<double>(c) / b);
        return;
    }
    int64_t d = b * b - 4 * a * c;
    if(d < 0)
        throw std::runtime_error("squareRoots. discriminant is less than zero");
    if(d == 0) {
        x1 = x2 = -(static_cast<double>(b) / (2 * a));
        return;
    }
    double sqrtOfD = std::sqrt(d);
    x1 = (-b + sqrtOfD) / (2 * a);
    x2 = (-b - sqrtOfD) / (2 * a);
}

inline double calculateY(double t, const Point<int64_t> &p1, const Point<int64_t> &p2, const Point<int64_t> &p3) {
    return (1 - t) * (1 - t) * p1.y + 2 * (1 - t) * t * p2.y + t * t * p3.y;
}
