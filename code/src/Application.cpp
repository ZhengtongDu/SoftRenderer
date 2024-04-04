#include "Application.h"
#include "Window.h"
#include <X11/Xlib.h>

const int delay = 50000; // 更新颜色的间隔时间，单位为微秒

Application::window::window(const char *windowName, int width, int height)
{
    // 打开与X服务器的连接
    display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        fprintf(stderr, "无法打开显示\n");
        exit(1);
    }

    screen = DefaultScreen(display);

    // 创建窗口
    w = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, (unsigned int)width, (unsigned int)height, 1,
                            BlackPixel(display, screen), WhitePixel(display, screen));

    // 设置窗口标题
    XStoreName(display, w, windowName);

    // 创建图形上下文
    graphicsContext = XCreateGC(display, w, 0, NULL);

    image = XCreateImage(display, DefaultVisual(display, screen), DefaultDepth(display, screen), ZPixmap, 0, nullptr, width, height, 32, 0);
    image->data = (char *)malloc(image->bytes_per_line * image->height);

    // 选择我们感兴趣的事件类型
    XSelectInput(display, w, ExposureMask | KeyPressMask);

    // 显示窗口
    XMapWindow(display, w);
}

Application::Application(const char *windowName, const int _width, const int _height) : m_windowName(windowName), m_width(_width), m_height(_height)
{
    Init();
}

void Application::SendFrame2Image()
{
    for (int x = 0; x < m_width; ++x)
    {
        for (int y = 0; y < m_height; ++y)
        {
            XPutPixel(m_window.image, x, m_height - 1 - y, (m_frameBuffer[x][y][0] % 256 << 16) | (m_frameBuffer[x][y][1] % 256 << 8) | m_frameBuffer[x][y][2] % 256 << 0);
        }
    }
}

void Application::Run()
{
    int y = 0;

    while (1)
    {
        // 检查事件队列中是否有事件
        while (XPending(m_window.display) > 0)
        {
            XNextEvent(m_window.display, &m_window.event);

            // // 绘制或重绘窗口
            // if (m_window.event.type == Expose)
            // {
            //     // 将图像绘制到窗口
            //     XPutImage(m_window.display, m_window.w, m_window.graphicsContext, m_window.image, 0, 0, 0, 0, m_width, m_height);
            // }
        }

        // 退出程序
        if (m_window.event.type == KeyPress)
        {
            break;
        }

        UpdateFrameBuffer();
        SendFrame2Image();
        XPutImage(m_window.display, m_window.w, m_window.graphicsContext, m_window.image, 0, 0, 0, 0, m_width, m_height);
        // 等待一段时间
        usleep(delay);
    }

    // 释放图形上下文资源
    XFreeGC(m_window.display, m_window.graphicsContext);

    // 关闭与X服务器的连接
    XCloseDisplay(m_window.display);
}

void Application::Init()
{
    m_window = window(m_windowName.c_str(), m_width, m_height);
    m_frameBuffer = new int **[m_width];
    for (int i = 0; i < m_width; i++)
    {
        m_frameBuffer[i] = new int *[m_height];
        for (int j = 0; j < m_height; j++)
        {
            m_frameBuffer[i][j] = new int[3];
            m_frameBuffer[i][j][0] = 255; // Red Value
            m_frameBuffer[i][j][1] = 255; // Green Value
            m_frameBuffer[i][j][2] = 255; // Blue Value
        }
    }
    m_depthBuffer = new double *[m_width];
    for (int i = 0; i < m_width; i++)
    {
        m_depthBuffer[i] = new double[m_height];
        for (int j = 0; j < m_height; j++)
            m_depthBuffer[i][j] = 0;
    }
}

void Application::UpdateFrameBuffer()
{

}
