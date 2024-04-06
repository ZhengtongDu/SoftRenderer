#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include "Matrix.h"

// 统一旋转按弧度制

class Transformation
{
public:

Transformation(){};
~Transformation(){};
Transformation(const Transformation& rhs) = delete;
Transformation& operator=(const Transformation& rhs) = delete;

Matrix4d translate(const Matrix4d& trans, const Vector3d& v, bool warningOn = true) const;
Matrix4d rotate(const Matrix4d& trans, const Vector3d& axis, const double& rotateAngle, bool warningOn = true) const;
Matrix4d rotateX(const Matrix4d& trans, const double& rotateAngle, bool warningOn = true) const;
Matrix4d rotateY(const Matrix4d& trans, const double& rotateAngle, bool warningOn = true) const;
Matrix4d rotateZ(const Matrix4d& trans, const double& rotateAngle, bool warningOn = true) const;
Matrix4d scale(const Matrix4d& trans, const double s, bool warningOn = true) const;
Matrix4d scale(const Matrix4d& trans, const Vector3d& s, bool warningOn = true) const;

private:
};

#endif // !TRANSFORMATION_H