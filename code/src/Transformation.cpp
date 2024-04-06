#include "Transformation.h"

Matrix4d Transformation::translate(const Matrix4d& trans, const Vector3d &v, bool warningOn) const
{

};

Matrix4d Transformation::rotate(const Matrix4d& trans, const Vector3d& axis, const double& rotateAngle, bool warningOn) const
{
    if(axis.norm() < epsilon)
        if (warningOn)
            throw std::runtime_error("rotate value invalid!");
    
};

Matrix4d Transformation::rotateX(const Matrix4d& trans, const double& rotateAngle, bool warningOn) const
{

};

Matrix4d Transformation::rotateY(const Matrix4d& trans, const double& rotateAngle, bool warningOn) const
{

};

Matrix4d Transformation::rotateZ(const Matrix4d& trans, const double& rotateAngle, bool warningOn) const
{

};

Matrix4d Transformation::scale(const Matrix4d& trans, const double s, bool warningOn) const
{
    if (fabs(s) < epsilon)
        if (warningOn)
            throw std::runtime_error("Scale value invalid!");

};

Matrix4d Transformation::scale(const Matrix4d& trans, const Vector3d &s, bool warningOn) const
{
    for (int i = 0; i < 3; i++)
    {
        if (fabs(s[i]) < epsilon)
            if (warningOn)
                throw std::runtime_error("Scale value invalid!");

    }

};
