cmake_minimum_required(VERSION 3.10)
project(OpenGLImageDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui OpenGL)

set(CMAKE_AUTOMOC ON)       # <--- 自动运行 moc
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(OpenGLImageDemo
    main.cpp
    ImageWidget.h
    ImageWidget.cpp
)

target_link_libraries(OpenGLImageDemo PRIVATE Qt5::Core Qt5::Widgets Qt5::Gui Qt5::OpenGL)
