#ifndef RENDERER_H
#define RENDERER_H 

#include <vector>
#include <iostream>
#include "Vector.h"
#include <algorithm>

/**
 * @class Renderer
 * @brief 渲染模块类，被Application类调用，用于处理程序中和OpenGL有关部分的响应
 *
 */
class Renderer {
public:
    Renderer(){};
    Renderer(int*** _frameBuffer, double** m_depthBuffer, int _width, int _height);


    bool setPixelColor(const int x, const int y, const Vector3i& color = Vector3i(255, 255, 255), bool warningOn = true);
    bool drawPoint(const Vector2d& p, const Vector3i& color = Vector3i(255, 255, 255));
    bool drawLine(const Vector2d& start, const Vector2d& end, const Vector3i& color = Vector3i(255, 255, 255));
    bool drawTriangle(const Vector2d& p1, const Vector2d& p2, const Vector2d& p3, const Vector3i& color = Vector3i(255, 255, 255), const bool isFilled = true);

    int m_width, m_height;
    int*** m_frameBuffer;
    double** m_depthBuffer;
};

#endif // !RENDERER_H
