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

Matrix3d Matrix3d::getIdentity() const
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
    throw std::runtime_error("Matrix3d index invalid!");
};

Vector3d &Matrix3d::operator[](const int idx)
{
    if (idx == 0)
        return data[0];
    if (idx == 1)
        return data[1];
    if (idx == 2)
        return data[2];
    throw std::runtime_error("Matrix3d index invalid!");
};

bool Matrix3d::operator==(const Matrix3d &rhs) const
{
    return data[0] == rhs.data[0] && data[1] == rhs.data[1] && data[2] == rhs.data[2];
};

bool Matrix3d::operator!=(const Matrix3d &rhs) const
{
    return !(*this == rhs);
};

Matrix3d Matrix3d::inverse() const
{
    double det = determinant();
    if (std::fabs(det) < epsilon)
    { // epsilon 应该是一个足够小的正数，用来判断浮点数是否接近0
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

Matrix4d::Matrix4d(const Matrix4d &rhs)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            data[i][j] = rhs[i][j];
    }
};

Matrix4d &Matrix4d::operator=(const Matrix4d &rhs)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            data[i][j] = rhs[i][j];
    }
    return *this;
};

Matrix4d Matrix4d::getIdentity() const
{
    Matrix4d ret;
    ret[0][0] = 1;
    ret[1][1] = 1;
    ret[2][2] = 1;
    ret[3][3] = 1;
    return ret;
};

Matrix4d Matrix4d::operator-() const
{
    Matrix4d ret;
    for (int i = 0; i < 4; i++)
        ret[i] = -data[i];
    return ret;
};

Matrix4d Matrix4d::operator+(const Matrix4d &rhs) const
{
    Matrix4d ret;
    for (int i = 0; i < 4; i++)
        ret[i] = data[i] + rhs[i];
    return ret;
};

Matrix4d Matrix4d::operator-(const Matrix4d &rhs) const
{
    Matrix4d ret;
    for (int i = 0; i < 4; i++)
        ret[i] = data[i] - rhs[i];
    return ret;
};

Matrix4d Matrix4d::operator*(const double &rhs) const
{
    Matrix4d ret;
    for (int i = 0; i < 4; i++)
        ret[i] = rhs * data[i];
    return ret;
};

Vector4d Matrix4d::operator*(const Vector4d &rhs) const
{
    Vector4d ret;
    ret[0] = this->data[0][0] * rhs[0] + data[1][0] * rhs[1] + data[2][0] * rhs[2] + data[3][0] * rhs[3];
    ret[1] = this->data[0][1] * rhs[0] + data[1][1] * rhs[1] + data[2][1] * rhs[2] + data[3][1] * rhs[3];
    ret[2] = this->data[0][2] * rhs[0] + data[1][2] * rhs[1] + data[2][2] * rhs[2] + data[3][2] * rhs[3];
    ret[3] = this->data[0][3] * rhs[0] + data[1][3] * rhs[1] + data[2][3] * rhs[2] + data[3][3] * rhs[3];
    return ret;
};

Matrix4d Matrix4d::operator*(const Matrix4d &rhs) const
{
    Matrix4d ret;
    for (int i = 0; i < 4; i++)
        ret[i] = *this * rhs[i];
    return ret;
};

Vector4d Matrix4d::operator[](const int idx) const
{
    if (idx == 0)
        return data[0];
    if (idx == 1)
        return data[1];
    if (idx == 2)
        return data[2];
    if (idx == 3)
        return data[3];
    throw std::runtime_error("Matrix4d index invalid!");
};

Vector4d &Matrix4d::operator[](const int idx)
{
    if (idx == 0)
        return data[0];
    if (idx == 1)
        return data[1];
    if (idx == 2)
        return data[2];
    if (idx == 3)
        return data[3];
    throw std::runtime_error("Matrix4d index invalid!");
};

bool Matrix4d::operator==(const Matrix4d &rhs) const
{
    return data[0] == rhs.data[0] && data[1] == rhs.data[1] && data[2] == rhs.data[2] && data[3] == rhs.data[3];
};

bool Matrix4d::operator!=(const Matrix4d &rhs) const
{
    return !(*this == rhs);
};

double Matrix4d::subDeterminant(const int excludeRow, const int excludeCol) const
{
    Matrix3d subMatrix;
    int subi = 0;
    for (int i = 0; i < 4; i++) {
        if (i == excludeRow) continue;
        int subj = 0;
        for (int j = 0; j < 4; j++) {
            if (j == excludeCol) continue;
            subMatrix[subi][subj] = data[i][j];
            subj++;
        }
        subi++;
    }
    return subMatrix.determinant();
};

Matrix4d Matrix4d::inverse() const {
    double det = determinant();
    if (std::fabs(det) < epsilon) {
        throw std::runtime_error("Matrix4d is not invertible, determinant is 0");
    }

    Matrix4d ret;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
            
            double subDet = subDeterminant(j, i); 

            ret.data[i][j] = sign * subDet / det;
        }
    }

    return ret;
};

double Matrix4d::determinant() const {
    double det = 0.0;
    
    for (int i = 0; i < 4; i++) {
        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        
        double subDet = subDeterminant(0, i);

        det += sign * data[0][i] * subDet;
    }
    
    return det;
};
