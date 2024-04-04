#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"

class Matrix3d
{
public:
    Matrix3d()
    {
        for (int i = 0; i < 3; i++)
            data[i] = Vector3d();
    };
    Matrix3d(const Matrix3d& rhs);
    Matrix3d& operator=(const Matrix3d& rhs);
    ~Matrix3d(){};
    Matrix3d GetIdentity() const;
    Matrix3d operator-() const;
    Matrix3d operator+(const Matrix3d& rhs) const;
    Matrix3d operator-(const Matrix3d& rhs) const;
    Matrix3d operator*(const double& rhs) const;
    Vector3d operator*(const Vector3d& rhs) const;
    Matrix3d operator*(const Matrix3d& rhs) const;
    Vector3d operator[](const int idx) const;
    Vector3d& operator[](const int idx);
    bool operator==(const Matrix3d& rhs) const;
    bool operator!=(const Matrix3d& rhs) const;
    Matrix3d inverse() const;
    double determinant() const;
    Vector3d data[3]; // 列向量
};

class Matrix4d
{
public:
    Matrix4d()
    {
        for (int i = 0; i < 4; i++)
            data[i] = new Vector4d();
    };
    ~Matrix4d();
    Vector4d *data[4];
};

#endif // !MATRIX_H
