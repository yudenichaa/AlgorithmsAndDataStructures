#include "Vector3d.h"

Vector3D::Vector3D() :
    x(0), y(0), z(0) {}

Vector3D::Vector3D(int x_, int y_, int z_) :
    x(x_), y(y_), z(z_) {}

Vector3D operator+(const Vector3D &lhs, const Vector3D &rhs) {
    return Vector3D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector3D& Vector3D::operator+=(const Vector3D &rhs) {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
}

Vector3D operator-(const Vector3D &lhs, const Vector3D &rhs) {
    return Vector3D(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vector3D& Vector3D::operator-=(const Vector3D &rhs) {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
}

Vector3D operator*(const Vector3D &lhs, const Vector3D &rhs) {
    return Vector3D(lhs.y * rhs.z - lhs.z * rhs.y,
                    lhs.z * rhs.x - lhs.x * rhs.z,
                    lhs.x * rhs.y - lhs.y * rhs.x);
}

Vector3D& Vector3D::operator*=(const Vector3D &rhs) {
    this->x = this->y * rhs.z - this->z * rhs.y;
    this->y = this->z * rhs.x - this->x * rhs.z;
    this->z = this->x * rhs.y - this->y * rhs.x;
    return *this;
}

Vector3D& Vector3D::operator*=(int scalar) {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}

int Vector3D::scalarProduct(const Vector3D &lhs, const Vector3D &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Vector3D operator*(const Vector3D &lhs, int scalar) {
    return Vector3D(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
}

Vector3D operator*(int scalar, const Vector3D &rhs) {
    return Vector3D(scalar * rhs.x, scalar * rhs.y, scalar * rhs.z);
}

std::ostream& operator<<(std::ostream &os, const Vector3D &v) {
    os << "{" << v.x << "; " << v.y << "; " << v.z << "}";
    return os;
}

std::istream& operator>>(std::istream &is, Vector3D &v) {
    is >> v.x >> v.y >> v.z;
    return is;
}

int Vector3D::getX() const {
    return x;
}

int Vector3D::getY() const {
    return y;
}

int Vector3D::getZ() const {
    return z;
}

void Vector3D::setX(int x_) {
    x = x_;
}

void Vector3D::setY(int y_) {
    y = y_;
}

void Vector3D::setZ(int z_) {
    z = z_;
}
