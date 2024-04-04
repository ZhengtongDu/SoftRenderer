#ifndef RENDERER_H
#define RENDERER_H 

#include <vector>
#include <iostream>
#include "Vector.h"

/**
 * @class Renderer
 * @brief 渲染模块类，被Application类调用，用于处理程序中和OpenGL有关部分的响应
 *
 */
class Renderer {
public:
    Renderer(){};
    Renderer(int*** _frameBuffer, double** m_depthBuffer);

    // TBD
    bool DrawPoint(int _x, int _y);
    bool DrawLine(int _x, int _y);
    bool DrawTriangle();

    int m_width, m_height;
    int*** m_frameBuffer;
    double** m_depthBuffer;
};

#endif // !RENDERER_H
