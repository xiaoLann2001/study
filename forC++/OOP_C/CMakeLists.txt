cmake_minimum_required(VERSION 3.10)
project(OOP_C C)

# 设置 C 语言标准
set(CMAKE_C_STANDARD 99)

# 添加子目录中的源文件
set(SOURCES
    main.c
    class/Shape/Shape.c
    class/Rectangle/Rectangle.c
)

# 添加头文件搜索路径
include_directories(
    class/Shape
    class/Rectangle
)

# 生成可执行文件
add_executable(OOP_C ${SOURCES})
