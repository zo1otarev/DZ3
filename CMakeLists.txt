cmake_minimum_required(VERSION 3.17)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculator main.cpp header.h count.cpp RPN.cpp)