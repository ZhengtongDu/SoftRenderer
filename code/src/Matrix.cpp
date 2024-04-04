#include "Matrix.h"

Matrix3d::Matrix3d(const Matrix3d &rhs)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            data[i][j] = rhs[i][j];
    }
};

Matrix3d &Matrix3d::operator=(const Matrix3d &rhs)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            data[i][j] = rhs[i][j];
    }
    return *this;
};

Matrix3d Matrix3d::GetIdentity() const
{
    Matrix3d ret;
    ret[0][0] = 1;
    ret[1][1] = 1;
    ret[2][2] = 1;
    return ret;
};

Matrix3d Matrix3d::operator-() const
{
    Matrix3d ret;
    for (int i = 0; i < 3; i++)
        ret[i] = -data[i];
    return ret;
};

Matrix3d Matrix3d::operator+(const Matrix3d &rhs) const
{
    Matrix3d ret;
    for (int i = 0; i < 3; i++)
        ret[i] = data[i] + rhs[i];
    return ret;
};

Matrix3d Matrix3d::operator-(const Matrix3d &rhs) const
{
    Matrix3d ret;
    for (int i = 0; i < 3; i++)
        ret[i] = data[i] - rhs[i];
    return ret;
};

Matrix3d Matrix3d::operator*(const double &rhs) const
{
    Matrix3d ret;
    for (int i = 0; i < 3; i++)
        ret[i] = rhs * data[i];
    return ret;
};

Vector3d Matrix3d::operator*(const Vector3d &rhs) const
{
    Vector3d ret;
    ret[0] = this->data[0][0] * rhs[0] + data[1][0] * rhs[1] + data[2][0] * rhs[2];
    ret[1] = this->data[0][1] * rhs[0] + data[1][1] * rhs[1] + data[2][1] * rhs[2];
    ret[2] = this->data[0][2] * rhs[0] + data[1][2] * rhs[1] + data[2][2] * rhs[2];
    return ret;
};

Matrix3d Matrix3d::operator*(const Matrix3d &rhs) const
{
    Matrix3d ret;
    for (int i = 0; i < 3; i++)
        ret[i] = *this * rhs[i];
    return ret;
};

Vector3d Matrix3d::operator[](const int idx) const
{
    if (idx == 0)
        return data[0];
    if (idx == 1)
        return data[1];
    if (idx == 2)
        return data[2];
    std::cout << "Matrix3d index invalid!" << std::endl;
    return data[0];
};

Vector3d &Matrix3d::operator[](const int idx)
{
    if (idx == 0)
        return data[0];
    if (idx == 1)
        return data[1];
    if (idx == 2)
        return data[2];
    std::cout << "Matrix3d index invalid!" << std::endl;
    return data[0];
};

bool Matrix3d::operator==(const Matrix3d &rhs) const
{
    return data[0] == rhs.data[0] && data[1] == rhs.data[1] && data[2] == rhs.data[2];
};

bool Matrix3d::operator!=(const Matrix3d &rhs) const
{
    return !(*this == rhs);
};

Matrix3d Matrix3d::inverse() const {
    double det = determinant();
    if (std::fabs(det) < epsilon) { // epsilon 应该是一个足够小的正数，用来判断浮点数是否接近0
        throw std::runtime_error("Matrix is not invertible, determinant is 0");
    }

    Matrix3d ret;

    // 计算代数余子式，然后转置
    ret[0][0] = (data[1][1] * data[2][2] - data[2][1] * data[1][2]) / det;
    ret[1][0] = -(data[1][0] * data[2][2] - data[1][2] * data[2][0]) / det;
    ret[2][0] = (data[1][0] * data[2][1] - data[1][1] * data[2][0]) / det;

    ret[0][1] = -(data[0][1] * data[2][2] - data[0][2] * data[2][1]) / det;
    ret[1][1] = (data[0][0] * data[2][2] - data[0][2] * data[2][0]) / det;
    ret[2][1] = -(data[0][0] * data[2][1] - data[0][1] * data[2][0]) / det;

    ret[0][2] = (data[0][1] * data[1][2] - data[0][2] * data[1][1]) / det;
    ret[1][2] = -(data[0][0] * data[1][2] - data[0][2] * data[1][0]) / det;
    ret[2][2] = (data[0][0] * data[1][1] - data[0][1] * data[1][0]) / det;

    return ret;
};

double Matrix3d::determinant() const
{
    return data[0][0] * (data[1][1] * data[2][2] - data[2][1] * data[1][2]) -
           data[1][0] * (data[0][1] * data[2][2] - data[2][1] * data[0][2]) +
           data[2][0] * (data[0][1] * data[1][2] - data[1][1] * data[0][2]);
};
