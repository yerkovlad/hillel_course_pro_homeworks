cmake_minimum_required(VERSION 3.10)
project(UniversityCourses)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(UniversityCourses src/main.cpp src/Student.hpp src/Course.hpp)