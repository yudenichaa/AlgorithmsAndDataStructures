#include "Matrix3d.h"

Matrix3D::Matrix3D() :
    matrix(std::array<std::array<int, 3>, 3>()) {}

Matrix3D::Matrix3D(int m11, int m12, int m13,
                   int m21, int m22, int m23,
                   int m31, int m32, int m33) :
    matrix(std::array<std::array<int, 3>, 3> {
           std::array<int, 3>{m11, m12, m13},
           std::array<int, 3>{m21, m22, m23},
           std::array<int, 3>{m31, m32, m33}}) {}

Matrix3D operator+(const Matrix3D &lhs, const Matrix3D &rhs) {
    Matrix3D result;
    for(size_t i = 0; i < 3; ++i)
        for(size_t j = 0; j < 3; ++j)
            result[i][j] = lhs[i][j] + rhs[i][j];
    return result;
}

Matrix3D& Matrix3D::operator+=(const Matrix3D &rhs) {
    for(size_t i = 0; i < 3; ++i)
        for(size_t j = 0; j < 3; ++j)
            this->matrix[i][j] += rhs[i][j];
    return *this;
}

Matrix3D operator-(const Matrix3D &lhs, const Matrix3D &rhs) {
    Matrix3D result;
    for(size_t i = 0; i < 3; ++i)
        for(size_t j = 0; j < 3; ++j)
            result[i][j] = lhs[i][j] - rhs[i][j];
    return result;
}

Matrix3D& Matrix3D::operator-=(const Matrix3D &rhs) {
    for(size_t i = 0; i < 3; ++i)
        for(size_t j = 0; j < 3; ++j)
            this->matrix[i][j] -= rhs[i][j];
    return *this;
}

Matrix3D operator*(const Matrix3D &lhs, const Matrix3D &rhs) {
    Matrix3D result;
    for(size_t i = 0; i < 3; ++i) {
        for(size_t j = 0; j < 3; ++j) {
            result[i][j] = 0;
            for(size_t k = 0; k < 3; ++k)
                result[i][j] += lhs[i][k] * rhs[k][j];
        }
    }
    return result;
}

Vector3D Matrix3D::operator*(const Vector3D &rhs) const {
    Vector3D result;
    result.setX(this->matrix[0][0] * rhs.getX() + this->matrix[0][1] * rhs.getY() + this->matrix[0][2] * rhs.getZ());
    result.setY(this->matrix[1][0] * rhs.getX() + this->matrix[1][1] * rhs.getY() + this->matrix[1][2] * rhs.getZ());
    result.setZ(this->matrix[2][0] * rhs.getX() + this->matrix[2][1] * rhs.getY() + this->matrix[2][2] * rhs.getZ());
    return result;
}

std::array<int, 3>& Matrix3D::operator[](size_t index) {
    return matrix[index];
}

const std::array<int, 3>& Matrix3D::operator[](size_t index) const {
    return matrix[index];
}

std::ostream& operator<<(std::ostream &os, const Matrix3D &m) {
    for(size_t i = 0; i < 3; ++i) {
        for(size_t j = 0; j < 3; ++j)
            os << m[i][j] << " ";
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream &is, Matrix3D &m) {
    is >> m[0][0] >> m[0][1] >> m[0][2]
            >> m[1][0] >> m[1][1] >> m[1][2]
            >> m[2][0] >> m[2][1] >> m[2][2];
    return is;
}
