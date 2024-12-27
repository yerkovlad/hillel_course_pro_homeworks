cmake_minimum_required(VERSION 3.10)
project(SharedPtr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(MySharedPtr STATIC src/SharedPtr.hpp)

add_executable(SharedPtr src/main.cpp)

target_link_libraries(SharedPtr PRIVATE MySharedPtr)
