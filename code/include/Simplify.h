// 记录自己在抄代码过程中的困惑
// 1. barycentric的算法？
// 2. 用模板来特化SymmetricMatrix类

// This code is modified from https://github.com/sp4cerat/Fast-Quadric-Mesh-Simplification/blob/master/src.cmd/Simplify.h

#ifndef _SIMPLIFY_H_
#define _SIMPLIFY_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Vector.h"
#include "Matrix.h"

#include <float.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

Vector3d barycentric(const Vector3d &p, const Vector3d &a, const Vector3d &b, const Vector3d &c)
{
    Vector3d v0 = b - a;
    Vector3d v1 = c - a;
    Vector3d v2 = p - a;
    double d00 = v0 * v0;
    double d01 = v0 * v1;
    double d11 = v1 * v1;
    double d20 = v2 * v0;
    double d21 = v2 * v1;
    double denom = d00 * d11 - d01 * d01;
    double v = (d11 * d20 - d01 * d21) / denom;
    double w = (d00 * d21 - d01 * d20) / denom;
    double u = 1.0 - v - w;
    return Vector3d(u, v, w);
}

Vector3d interpolate(const Vector3d &p, const Vector3d &a, const Vector3d &b, const Vector3d &c, const Vector3d attrs[3])
{
    Vector3d bc = barycentric(p, a, b, c);
    Vector3d ret(0, 0, 0);
    ret += attrs[0] * bc.x;
    ret += attrs[1] * bc.y;
    ret += attrs[2] * bc.z;
    return ret;
}

double min(double a1, double a2)
{
    return fmin(a1, a2);
}

class SymmetricMatrix // 3-order
{
// functions
public:
    SymmetricMatrix(double c = 0)
    {
        for(int i = 0; i < 10; i++)
            m[i] = c;
    };
    ~SymmetricMatrix();

// data
public:
    double m[10]; // elements of matrix
};

// struct Triangle
// {
//     int v[3];
//     double err[4];
//     int deleted, dirty, attr;
//     glm::vec3 n;
//     // glm::vec3 uvs[3];
//     // int material;
// };

// struct Vertex
// {
//     glm::vec3 p;
//     int tstart, tcount;

// };

// struct Ref
// {
//     int tid, tvertex;
// };

// class Simplification
// {
// public:

// Simplification(){};
// ~Simplification(){};

// bool load_obj(const char* filename);

// private:

// };

// bool Simplification::load_obj(const char* filename)
// {

//     return true;
// };

#endif // !_SIMPLIFY_H_
