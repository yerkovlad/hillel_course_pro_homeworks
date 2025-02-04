cmake_minimum_required(VERSION 3.5)

project(FileExplorerApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(FileExplorerApp
    main.cpp
    CustomFileSystemModel.h
    CustomDelegate.h
)

target_link_libraries(FileExplorerApp Qt5::Widgets)