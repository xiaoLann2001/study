
cmake_minimum_required(VERSION 3.10)
project(videoTestmulthreadProject)

# 设置C++编译标准
set(CMAKE_CXX_STANDARD 11)

# 设置源代码
set(SOURCES
    main.cpp
)

# 添加可执行文件
add_executable(videoTest ${SOURCES})

# 查找并配置OpenCV 4
find_package(OpenCV 4 REQUIRED)
find_package(Threads REQUIRED)

# 添加链接的库文件
target_link_libraries(videoTest PRIVATE ${OpenCV_LIBS} ${CMAKE_THREAD_LIBS_INIT})

# 添加头文件目录
target_include_directories(videoTest PRIVATE ${OpenCV_INCLUDE_DIRS})

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build)

# 设置其他需要的文件（可选）
file(COPY model/best.onnx model/class.names DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/build)

# 设置gdb调试
target_compile_options(videoTest PRIVATE -g)