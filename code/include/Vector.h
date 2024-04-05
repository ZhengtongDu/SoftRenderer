#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cmath>
#include <vector>

const double epsilon = 1e-9;

class Vector2d;
class Vector3d;
class Vector4d;

class Vector2d
{
public:
    Vector2d(){x = 0,y = 0;};
    Vector2d(double _x, double _y):x(_x), y(_y){};
    Vector2d(const Vector2d& rhs){x = rhs.x, y = rhs.y;}
    Vector2d& operator=(const Vector2d& rhs){
        x = rhs.x, y = rhs.y;
        return *this;
    }
    Vector2d operator-() const;
    Vector2d operator +(const Vector2d& rhs) const;
    Vector2d operator -(const Vector2d& rhs) const;

    bool operator ==(const Vector2d& rhs) const;
    bool operator !=(const Vector2d& rhs) const;
    double operator *(const Vector2d& rhs) const;
    Vector2d operator *(const double& rhs) const;
    Vector2d operator /(const double& rhs) const;
    double operator[] (const int idx) const;
    double& operator[] (const int idx);
    friend Vector2d operator *(const double& lhs, const Vector2d& rhs);
    friend std::ostream &operator<< (std::ostream &output, const Vector2d& rhs);
    double dist() const;
    Vector2d normalize() const;
    Vector2d normalized();
    // member object
    double x, y;
};

class Vector3d
{
public:
    Vector3d(){x = 0,y = 0, z = 0;};
    Vector3d(double _x, double _y, double _z):x(_x), y(_y), z(_z){};
    Vector3d(const Vector3d& rhs){x = rhs.x, y = rhs.y, z = rhs.z;}
    Vector3d& operator=(const Vector3d& rhs){
        x = rhs.x, y = rhs.y, z = rhs.z;
        return *this;
    }
    Vector3d operator-() const;
    Vector3d operator +(const Vector3d& rhs) const;
    Vector3d operator -(const Vector3d& rhs) const;
    bool operator ==(const Vector3d& rhs) const;
    bool operator !=(const Vector3d& rhs) const;
    double operator *(const Vector3d& rhs) const;
    Vector3d operator *(const double& rhs) const;
    Vector3d operator /(const double& rhs) const;
    double operator[] (const int idx) const;
    double& operator[] (const int idx);
    friend Vector3d operator *(const double& lhs, const Vector3d& rhs);
    friend std::ostream &operator<< (std::ostream &output, const Vector3d& rhs);
    double dist() const;
    Vector3d normalize() const;
    Vector3d normalized();
    Vector3d cross(const Vector3d& rhs) const;
    Vector4d convertToVector4d() const;

    // member object
    double x, y, z;
};

class Vector4d
{
public:
    Vector4d(){x = 0,y = 0, z = 0, w = 0;};
    Vector4d(double _x, double _y, double _z):x(_x), y(_y), z(_z), w(1){};
    Vector4d(double _x, double _y, double _z, double _w):x(_x), y(_y), z(_z), w(_w){};
    Vector4d(const Vector4d& rhs){x = rhs.x, y = rhs.y, z = rhs.z, w = rhs.w;}
    Vector4d& operator=(const Vector4d& rhs){
        x = rhs.x, y = rhs.y, z = rhs.z, w = rhs.w;
        return *this;
    }
    Vector4d operator-() const;
    Vector4d operator +(const Vector4d& rhs) const;
    Vector4d operator -(const Vector4d& rhs) const;
    bool operator ==(const Vector4d& rhs) const;
    bool operator !=(const Vector4d& rhs) const;
    double operator *(const Vector4d& rhs) const;
    Vector4d operator *(const double& rhs) const;
    Vector4d operator /(const double& rhs) const;
    double operator[] (const int idx) const;
    double& operator[] (const int idx);
    friend Vector4d operator *(const double& lhs, const Vector4d& rhs);
    friend std::ostream &operator<< (std::ostream &output, const Vector4d& rhs);
    double dist() const;
    Vector4d normalize() const;
    Vector4d normalized();
    Vector3d convertToVector3d() const;

    // member object
    double x, y, z, w;
};

#endif // VECTOR_H