#pragma once
#include <iostream>

class Vector3D {
public:
    Vector3D();
    Vector3D(int x_, int y_, int z_);
    friend Vector3D operator+(const Vector3D &lhs, const Vector3D &rhs);
    Vector3D& operator+=(const Vector3D &rhs);
    friend Vector3D operator-(const Vector3D &lhs, const Vector3D &rhs);
    Vector3D& operator-=(const Vector3D &rhs);
    friend Vector3D operator*(const Vector3D &lhs, const Vector3D &rhs);
    Vector3D& operator*=(const Vector3D &rhs);
    Vector3D& operator*=(int scalar);
    static int scalarProduct(const Vector3D &lhs, const Vector3D &rhs);
    friend Vector3D operator*(const Vector3D &lhs, int scalar);
    friend Vector3D operator*(int scalar, const Vector3D &rhs);
    friend std::ostream& operator<<(std::ostream &os, const Vector3D &v);
    friend std::istream& operator>>(std::istream &is, Vector3D &v);
    int getX() const;
    int getY() const;
    int getZ() const;
    void setX(int x_);
    void setY(int y_);
    void setZ(int z_);

private:
    int x;
    int y;
    int z;
};
