cmake_minimum_required(VERSION 3.10)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(TaskManager
    src/Task.cpp
    src/TaskManager.cpp
    src/TaskView.cpp
    src/TaskController.cpp
    main.cpp
)
