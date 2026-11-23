cmake_minimum_required(VERSION 3.16)

project(hello-qt6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(hello-qt6 main.cpp)

target_link_libraries(hello-qt6 PRIVATE Qt6::Widgets)
