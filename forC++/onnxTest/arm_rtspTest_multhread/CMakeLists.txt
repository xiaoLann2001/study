cmake_minimum_required(VERSION 3.10)
project(rtspTestProject)

# 指定交叉编译器的路径
set(CMAKE_C_COMPILER "/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "/opt/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-g++")

# 设置C++编译标准
set(CMAKE_CXX_STANDARD 11)

# 设置源代码
set(SOURCES
    main.cpp
)

# 添加可执行文件
add_executable(rtspTest ${SOURCES})

# 查找并配置OpenCV 4
find_package(OpenCV 4 REQUIRED)
find_package(Threads REQUIRED)

# 添加链接的库文件
target_link_libraries(rtspTest PRIVATE ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

# 添加头文件目录
target_include_directories(rtspTest PRIVATE ${OpenCV_INCLUDE_DIRS})

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# 设置其他需要的文件（可选）
file(COPY model/best.onnx model/class.names DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build)

# 设置gdb调试
target_compile_options(rtspTest PRIVATE -g)