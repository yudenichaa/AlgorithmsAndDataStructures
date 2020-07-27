#pragma once
#include <iostream>
#include <vector>

template <typename T>
struct Point {
    T x;
    T y;
    template <typename K>
    friend std::istream& operator>>(std::istream &is, Point<K> &p);
    template <typename K>
    friend std::ostream& operator<<(std::ostream &os, const Point<K> &p);
};

std::vector<Point<double>> BezierCurve(const Point<int64_t> &p1, const Point<int64_t> &p2, const Point<int64_t> &p3);

template<typename T>
void sortOf3(T &first, T &second, T &third) {
    using std::swap;
    if(first > second)
        swap(first, second);
    if(first > third)
        swap(first, third);
    if(second > third)
        swap(second, third);
}

void calculateBezierPoints(std::vector<Point<double>> &BezierPoints, int64_t from, int64_t to,
                           const Point<int64_t> &p1, const Point<int64_t> &p2, const Point<int64_t> &p3);
void squareRoots(int64_t a, int64_t b, int64_t c, double &x1, double &x2);
inline double calculateY(double t, const Point<int64_t> &p1, const Point<int64_t> &p2, const Point<int64_t> &p3);

template <typename K>
std::ostream& operator<<(std::ostream &os, const Point<K> &p) {
    os << p.x << " " << p.y << "\n";
    return os;
}

template <typename K>
std::istream& operator>>(std::istream &is, Point<K> &p) {
    is >> p.x >> p.y;
    return is;
}
