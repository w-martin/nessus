# CMake build script for Neural Network Simulator.

cmake_minimum_required (VERSION 2.6)

project (nn-simulator CXX)

set(nn-simulator_SOURCE_DIR .)
set(nn-simulator_BINARY_DIR ${nn-simulator_SOURCE_DIR}/build/bin)
set(nn-simulator_INCLUDE_DIR ${nn-simulator_SOURCE_DIR}/include/nn-simulator)
include_directories(
    ${nn-simulator_INCLUDE_DIR}
    ${nn-simulator_SOURCE_DIR}
    ${nn-simulator_BINARY_DIR})

add_executable (nn-simulator ${nn-simulator_SOURCE_DIR}/src/main.cpp)