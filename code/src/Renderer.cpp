#include "Renderer.h"

Renderer::Renderer(int ***_frameBuffer, double **_depthBuffer, int _width, int _height)
    : m_frameBuffer(_frameBuffer), m_depthBuffer(_depthBuffer), m_width(_width), m_height(_height)
{
}

bool Renderer::setPixelColor(const int x, const int y, const Vector3i &color, bool warningOn)
{
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
    {
        if(warningOn == true)
            throw std::runtime_error("setPixelColor coordinate invalid!");
        return false;
    }
    m_frameBuffer[x][y][0] = color[0];
    m_frameBuffer[x][y][1] = color[1];
    m_frameBuffer[x][y][2] = color[2];
    return true;
};

bool Renderer::drawPoint(const Vector2d &p, const Vector3i &color)
{
    if (p[0] < 0 || p[0] >= m_width && p[1] < 0 && p[1] >= m_height)
    {
        throw std::runtime_error("drawPoint coordinate invalid!");
        return false;
    }
    return setPixelColor((int)p[0], (int)p[1], color, false);
};

bool Renderer::drawLine(const Vector2d &start, const Vector2d &end, const Vector3i &color)
{
    if (start == end)
    {
        setPixelColor((int)start[0], (int)start[1], color);
        return true;
    }
    int x1 = start[0], x2 = end[0], y1 = start[1], y2 = end[1];
    int dx = x2 - x1, dy = y2 - y1, p;
    if (abs(dy) <= abs(dx)) // |k| <= 1 
    {
        if (dx < 0)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
            dx *= -1, dy *= -1;
        }
        p = 2 * dy - dx;
        for (; x1 <= x2; x1++)
        {
            if (p >= 0)
            {
                setPixelColor(x1, y1, color, false);
                p += 2 * dy - 2 * dx;
            }
            else
            {
                y1++;
                setPixelColor(x1, y1, color, false);
                p += 2 * dy;
            }
        }
    }
    else
    {
        if (dy < 0)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
            dx *= -1, dy *= -1;
        }
        p = 2 * dx - dy;
        for (; y1 <= y2; y1++)
        {
            if (p >= 0)
            {
                setPixelColor(x1, y1, color, false);
                p += 2 * dx - 2 * dy;
            }
            else
            {
                x1++;
                setPixelColor(x1, y1, color, false);
                p += 2 * dx;
            }
        }
    }
    return true;
};

bool isInTriangle(const double x, const double y, const Vector2d &p1, const Vector2d &p2, const Vector2d &p3)
{
    Vector2d e1(x - p1[0], y - p1[1]), e2(x - p2[0], y - p2[1]), e3(x - p3[0], y - p3[1]), v1 = p2 - p1, v2 = p3 - p2, v3 = p1 - p3;
    double c1 = e1.cross(v1), c2 = e2.cross(v2), c3 = e3.cross(v3);
    return (c1 >= 0 && c2 >= 0 && c3 >= 0) || (c1 <= 0 && c2 <= 0 && c3 <= 0);
};

bool Renderer::drawTriangle(const Vector2d &p1, const Vector2d &p2, const Vector2d &p3, const Vector3i &color, const bool isFilled)
{
    int minx = m_width - 1, maxx = 0, miny = m_height - 1, maxy = 0;
    maxx = std::max(maxx, (int)p1[0]), maxy = std::max(maxy, (int)p1[1]);
    maxx = std::max(maxx, (int)p2[0]), maxy = std::max(maxy, (int)p2[1]);
    maxx = std::max(maxx, (int)p3[0]), maxy = std::max(maxy, (int)p3[1]);
    minx = std::min(minx, (int)p1[0]), miny = std::min(miny, (int)p1[1]);
    minx = std::min(minx, (int)p2[0]), miny = std::min(miny, (int)p2[1]);
    minx = std::min(minx, (int)p3[0]), miny = std::min(miny, (int)p3[1]);
    
    for(int i = std::max(minx, 0); i < std::min(maxx, m_width); i++)
        for(int j = std::max(miny, 0); j < std::min(maxy, m_height); j++)
        {
            if(isInTriangle(i, j, p1, p2, p3)){
                setPixelColor(i, j, color, false);
            }
        }
    return true;
};
