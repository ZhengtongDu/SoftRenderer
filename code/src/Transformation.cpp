#include "Transformation.h"

Matrix4d Transformation::translate(const Matrix4d& trans, const Vector3d &v, bool warningOn) const
{
    Matrix4d translation = Matrix4d::getIdentity();
    translation[0][3] = v[0];
    translation[1][3] = v[1];
    translation[2][3] = v[2];
    return translation * trans;
};

Matrix4d Transformation::rotate(const Matrix4d& trans, const Vector3d& axis, const double& rotateAngle, bool warningOn) const
{
    if(axis.norm() < epsilon)
        if (warningOn)
            throw std::runtime_error("rotate value invalid!");
    
};

Matrix4d Transformation::rotateX(const Matrix4d& trans, const double& rotateAngle, bool warningOn) const
{
    Matrix4d rotation = Matrix4d::getIdentity();
    rotation[1][1] = cos(rotateAngle);
    rotation[1][2] = -sin(rotateAngle);
    rotation[2][1] = sin(rotateAngle);
    rotation[2][2] = cos(rotateAngle);
    return rotation * trans;
};

Matrix4d Transformation::rotateY(const Matrix4d& trans, const double& rotateAngle, bool warningOn) const
{
    Matrix4d rotation = Matrix4d::getIdentity();
    rotation[0][0] = cos(rotateAngle);
    rotation[0][2] = sin(rotateAngle);
    rotation[2][0] = -sin(rotateAngle);
    rotation[2][2] = cos(rotateAngle);
    return rotation * trans;
};

Matrix4d Transformation::rotateZ(const Matrix4d& trans, const double& rotateAngle, bool warningOn) const
{
    Matrix4d rotation = Matrix4d::getIdentity();
    rotation[0][0] = cos(rotateAngle);
    rotation[0][1] = -sin(rotateAngle);
    rotation[1][0] = sin(rotateAngle);
    rotation[1][1] = cos(rotateAngle);
    return rotation * trans;
};

Matrix4d Transformation::scale(const Matrix4d& trans, const double s, bool warningOn) const
{
    if (fabs(s) < epsilon)
        if (warningOn)
            throw std::runtime_error("Scale value invalid!");
    return s * trans;
};

Matrix4d Transformation::scale(const Matrix4d& trans, const Vector3d &s, bool warningOn) const
{
    for (int i = 0; i < 3; i++)
    {
        if (fabs(s[i]) < epsilon)
            if (warningOn)
                throw std::runtime_error("Scale value invalid!");
    }
    Matrix4d scaling = Matrix4d::getIdentity();
    scaling[0][0] = s[0];
    scaling[1][1] = s[1];
    scaling[2][2] = s[2];
    return scaling * trans;
};
