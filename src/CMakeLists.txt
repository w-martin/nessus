# CMake build script for Neural Network Simulator.

cmake_minimum_required (VERSION 2.6)

project (nn-simulator CXX)

set(PROJECT_NAME nn-simulator)
set(PROJECT_SOURCE_DIR .)
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/../include/nn-simulator)
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/../build/bin)

include_directories(${PROJECT_INCLUDE_DIR})

add_subdirectory(${PROJECT_SOURCE_DIR}/functions)
link_directories(${PROJECT_SOURCE_DIR}/functions)

add_subdirectory(${PROJECT_SOURCE_DIR}/model)
link_directories(${PROJECT_SOURCE_DIR}/model)

add_subdirectory(${PROJECT_SOURCE_DIR}/nets)
link_directories(${PROJECT_SOURCE_DIR}/nets)

add_subdirectory(${PROJECT_SOURCE_DIR}/trainer)
link_directories(${PROJECT_SOURCE_DIR}/trainer)

add_executable (${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)

target_link_libraries(${PROJECT_NAME} functions model nets trainer)
