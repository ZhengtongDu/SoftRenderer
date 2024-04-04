/**
 * @file Application.h
 * @brief 用来调用程序的接口头文件
 *
 * 本头文件用来处理opengl相关初始化事项，进一步细分代码结构
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Window.h"

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
    ~Application(){};
    void Run();

    bool ChangeWindowWidth(const int _width)
    {
        m_width = _width;
        return true;
    }

    bool ChangeWindowHeight(const int _height)
    {
        m_height = _height;
        return true;
    }

private:
    // Renderer renderer;
    // EventHandler eventHandler;
    // 其他应用程序状态和逻辑

    void Init();
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
    void SendFrame2Image();
    void UpdateFrameBuffer();
    std::string m_windowName;
    int ***m_frameBuffer;
    int m_width, m_height;
};

#endif // !APPLICATION_H