#pragma once
#include <array>
#include <iostream>
#include "Vector3d.h"

class Matrix3D
{
public:
    Matrix3D();
    Matrix3D(int m11, int m12, int m13,
             int m21, int m22, int m23,
             int m31, int m32, int m33);

    friend Matrix3D operator+(const Matrix3D &lhs, const Matrix3D &rhs);
    Matrix3D& operator+=(const Matrix3D &rhs);
    friend Matrix3D operator-(const Matrix3D &lhs, const Matrix3D &rhs);
    Matrix3D& operator-=(const Matrix3D &rhs);
    friend Matrix3D operator*(const Matrix3D &lhs, const Matrix3D &rhs);
    Vector3D operator*(const Vector3D &rhs) const;
    std::array<int, 3>& operator[](size_t index);
    const std::array<int, 3>& operator[](size_t index) const;
    friend std::ostream& operator<<(std::ostream &os, const Matrix3D &m);
    friend std::istream& operator>>(std::istream &os, Matrix3D &m);

private:
    std::array<std::array<int, 3>, 3> matrix;
};
