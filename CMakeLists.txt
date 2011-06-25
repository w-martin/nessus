# CMake build script for Neural Network Simulator.

cmake_minimum_required (VERSION 2.6)

project (nn-simulator)

set(nn-simulator_BINARY_DIR ${nn-simulator_BINARY_DIR}/build/bin)
include_directories(include/nn-simulator)

add_executable (nn-simulator src/main.cpp)