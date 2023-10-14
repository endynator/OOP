cmake_minimum_required(VERSION 3.28)

project(OOP)

find_package(fmt REQUIRED)

add_executable(OOP main.cpp)

target_link_libraries(OOP fmt::fmt)