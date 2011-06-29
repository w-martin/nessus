# CMake build script for Neural Network Simulator.

cmake_minimum_required (VERSION 2.6)

project (nn-simulator CXX)

set(PROJECT_NAME nn-simulator)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_INCLUDE_DIR include/nn-simulator)
set(PROJECT_BINARY_DIR build/bin)

include_directories(${PROJECT_INCLUDE_DIR})

add_executable (${PROJECT_NAME} 
    ${PROJECT_SOURCE_DIR}/main.cpp
    ${PROJECT_SOURCE_DIR}/functions/HeavisideFunction.cpp
    ${PROJECT_SOURCE_DIR}/functions/SigmoidFunction.cpp
    ${PROJECT_SOURCE_DIR}/model/Architecture.cpp
    ${PROJECT_SOURCE_DIR}/model/Layer.cpp
    ${PROJECT_SOURCE_DIR}/model/Net.cpp
    ${PROJECT_SOURCE_DIR}/model/Neuron.cpp
    ${PROJECT_SOURCE_DIR}/model/Output.cpp
    ${PROJECT_SOURCE_DIR}/model/Vector.cpp
    ${PROJECT_SOURCE_DIR}/nets/NetsFactory.cpp
    ${PROJECT_SOURCE_DIR}/nets/BDN/BDN.cpp
    ${PROJECT_SOURCE_DIR}/nets/BDN/BDNTrainer.cpp
    ${PROJECT_SOURCE_DIR}/nets/BDN/LogicalArchitecture.cpp
    ${PROJECT_SOURCE_DIR}/nets/BDN/realisations/ORnet.cpp
    ${PROJECT_SOURCE_DIR}/trainer/Trainer.cpp)
