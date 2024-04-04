#include "Vector.h"

// Vector2d

Vector2d Vector2d::operator-() const
{
    Vector2d(-x, -y);
};

Vector2d Vector2d::operator+(const Vector2d &rhs) const
{
    return Vector2d(x + rhs.x, y + rhs.y);
};

Vector2d Vector2d::operator-(const Vector2d &rhs) const
{
    return Vector2d(x - rhs.x, y - rhs.y);
};

bool Vector2d::operator==(const Vector2d &rhs) const
{
    return std::fabs(x - rhs.x) < epsilon && std::fabs(y - rhs.y) < epsilon;
};

bool Vector2d::operator!=(const Vector2d &rhs) const
{
    return !(*this == rhs);
};

double Vector2d::operator*(const Vector2d &rhs) const
{
    return x * rhs.x + y * rhs.y;
};

Vector2d Vector2d::operator*(const double &rhs) const
{
    return Vector2d(rhs * x, rhs * y);
};

Vector2d Vector2d::operator/(const double &rhs) const
{
    if (std::fabs(rhs) < epsilon)
        return Vector2d();
    return Vector2d(x / rhs, y / rhs);
};

Vector2d operator*(const double &lhs, const Vector2d &rhs)
{
    return lhs * rhs;
};

std::ostream &operator<< (std::ostream &output, const Vector2d& rhs)
{
    output << "(" << rhs.x << ", " << rhs.y << ")";
    return output;
}

double Vector2d::dist() const
{
    return sqrt(x * x + y * y);
};

Vector2d Vector2d::normalize() const
{
    double dis = this->dist();
    return *this / dis;
};

Vector2d Vector2d::normalized()
{
    double dis = this->dist();
    if (std::fabs(dis) >= epsilon)
        x = x / dis, y = y / dis;
    return *this;
};

// Vector3d

Vector3d Vector3d::operator-() const
{
    return Vector3d(-x, -y, -z);
};

Vector3d Vector3d::operator+(const Vector3d &rhs) const
{
    return Vector3d(x + rhs.x, y + rhs.y, z + rhs.z);
};

Vector3d Vector3d::operator-(const Vector3d &rhs) const
{
    return Vector3d(x - rhs.x, y - rhs.y, z - rhs.z);
};

bool Vector3d::operator==(const Vector3d &rhs) const
{
    return std::fabs(x - rhs.x) < epsilon && std::fabs(y - rhs.y) < epsilon && std::fabs(z - rhs.z) < epsilon;
};

bool Vector3d::operator!=(const Vector3d &rhs) const
{
    return !(*this == rhs);
};

double Vector3d::operator*(const Vector3d &rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z;
};

Vector3d Vector3d::operator*(const double &rhs) const
{
    return Vector3d(rhs * x, rhs * y, rhs * z);
};

Vector3d Vector3d::operator/(const double &rhs) const
{
    if (std::fabs(rhs) < epsilon)
        return Vector3d();
    return Vector3d(x / rhs, y / rhs, z / rhs);
};

double Vector3d::operator[](const int idx) const
{
    if(idx == 0)
        return x;
    if(idx == 1)
        return y;
    if(idx == 2)
        return z;
    std::cout << "vector3d index invalid!" << std::endl;
    return x;    
};

double& Vector3d::operator[](const int idx)
{
    if(idx == 0)
        return x;
    if(idx == 1)
        return y;
    if(idx == 2)
        return z;
    std::cout << "vector3d index invalid!" << std::endl;
    return x;    
};

Vector3d operator*(const double &lhs, const Vector3d &rhs)
{
    return lhs * rhs;
};

std::ostream &operator<< (std::ostream &output, const Vector3d& rhs)
{
    output << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return output;
}

double Vector3d::dist() const
{
    return sqrt(x * x + y * y + z * z);
};

Vector3d Vector3d::normalize() const
{
    return *this / this->dist();
};

Vector3d Vector3d::normalized()
{
    double dis = this->dist();
    if (std::fabs(dis) >= epsilon)
        x = x / dis, y = y / dis, z = z / dis;
    return *this;
};

Vector3d Vector3d::cross(const Vector3d &rhs) const
{
    return Vector3d(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
};

Vector4d Vector3d::convertToVector4d() const
{
    return Vector4d(x, y, z);
};

Vector4d Vector4d::operator-() const
{
    return Vector4d(-x, -y, -z, -w);
};

Vector4d Vector4d::operator+(const Vector4d &rhs) const
{
    return Vector4d(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs. w);
};

Vector4d Vector4d::operator-(const Vector4d &rhs) const
{
    return Vector4d(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
};

bool Vector4d::operator==(const Vector4d &rhs) const
{
    return std::fabs(x - rhs.x) < epsilon && std::fabs(y - rhs.y) < epsilon && std::fabs(z - rhs.z) < epsilon && (w - rhs.w) < epsilon;
};

bool Vector4d::operator!=(const Vector4d &rhs) const
{
    return !(*this == rhs);
};

double Vector4d::operator*(const Vector4d &rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
};

Vector4d Vector4d::operator*(const double &rhs) const
{
    return Vector4d(x * rhs, y * rhs, z * rhs, w * rhs);
};

Vector4d Vector4d::operator/(const double &rhs) const
{
    if (std::fabs(rhs) < epsilon)
        return Vector4d();
    return Vector4d(x / rhs, y / rhs, z / rhs, w / rhs);
};

double Vector4d::operator[](const int idx) const
{
    if(idx == 0)
        return x;
    if(idx == 1)
        return y;
    if(idx == 2)
        return z;
    if(idx == 3)
        return w;
    std::cout << "vector4d index invalid!" << std::endl;
    return x;    
};

Vector4d operator*(const double &lhs, const Vector4d &rhs){
    return lhs * rhs;
};

std::ostream &operator<< (std::ostream &output, const Vector4d& rhs)
{
    output << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ", " << rhs.w << ")";
    return output;
}

double Vector4d::dist() const
{
    return sqrt(x * x + y * y + z * z + w * w);
};

Vector4d Vector4d::normalize() const
{
    return *this / this->dist();
};

Vector4d Vector4d::normalized(){
    double dis = this->dist();
    if (std::fabs(dis) >= epsilon)
        x = x / dis, y = y / dis, z = z / dis, w = w / dis;
    return *this;
};

Vector3d Vector4d::convertToVector3d() const
{
    if(std::fabs(w) < epsilon) return Vector3d();
    return Vector3d(x, y, z) / w;
};
