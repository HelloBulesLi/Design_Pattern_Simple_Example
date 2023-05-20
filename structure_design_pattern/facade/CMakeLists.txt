cmake_minimum_required(VERSION 3.14)
project(facade)

SET(CMAKE_BUILD_TYPE "Debug")

set( CMAKE_CXX_FLAGS "-std=c++14 -O3" )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} facade.cpp)
