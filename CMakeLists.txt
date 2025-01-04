cmake_minimum_required(VERSION 3.15)
project(BoostExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to Boost as a submodule
set(BOOST_ROOT "${CMAKE_SOURCE_DIR}/external/boost")

# Integrate Boost through its CMake
add_subdirectory(${BOOST_ROOT} external/boost-build)

find_package(Boost REQUIRED COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Could not find Boost!")
endif()

add_executable(main main.cpp)

# Link Boost libraries
target_link_libraries(main Boost::program_options)