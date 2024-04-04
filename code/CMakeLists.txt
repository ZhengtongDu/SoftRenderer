cmake_minimum_required(VERSION 3.10)
project(SoftRenderer)

# 查找X11库
find_package(X11 REQUIRED)

# 包含X11库的头文件目录
include_directories(${X11_INCLUDE_DIR})

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 将源文件添加到此变量
set(SOURCE_FILES
    "src/main.cpp"
    "src/Application.cpp"
    # "src/Window.cpp"
    # 如果有其他源文件，也应该添加到这里
)

# 添加可执行文件
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# 包含头文件目录
target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/include"
    # 如果有其他依赖，也应该包含它们的头文件目录
)

# 链接X11库
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})