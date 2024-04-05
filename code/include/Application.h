/**
 * @file Application.h
 * @brief 用来调用程序的接口头文件
 *
 * 本头文件用来处理opengl相关初始化事项，进一步细分代码结构
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Renderer.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <cmath>
#include <cstdlib>
#include <string.h>

/**
 * @class Application
 * @brief 程序接口类，用于整合各个模块的内容
 *
 */
class Application
{
public:
    Application(const char *windowName = "Soft Renderer", const int _width = 800, const int _height = 600);
    ~Application()
    {
        for (int i = 0; i < m_width; i++)
        {
            for (int j = 0; j < m_height; j++)
                free(m_frameBuffer[i][j]);
            free(m_frameBuffer[i]);
            free(m_depthBuffer[i]);
        }
        free(m_frameBuffer);
        free(m_depthBuffer);
    };
    void run();

    bool changeWindowWidth(const int _width)
    {
        m_width = _width;
        return true;
    }

    bool changeWindowHeight(const int _height)
    {
        m_height = _height;
        return true;
    }

private:
    // Renderer renderer;
    // EventHandler eventHandler;
    // 其他应用程序状态和逻辑

    // Basic Settings
    void init();
    struct window
    {
        Window w;           // window
        XEvent event;       // event
        GC graphicsContext; // 图形上下文（Graphics Context）
        Display *display;   // display
        int screen;         // screen
        XImage *image;
        window(){};
        window(const char *_windowName, int _width, int _height);
    } m_window;
    void sendFrame2Image();

    // Setting Configs about WINDOWS
    std::string m_windowName;
    int ***m_frameBuffer;
    double **m_depthBuffer;
    int m_width, m_height;

    // Renderer Module
    Renderer m_renderer;
};

#endif // !APPLICATION_H