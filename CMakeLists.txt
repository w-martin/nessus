# CMake build script for Neural Network Simulator.

cmake_minimum_required (VERSION 2.6)

########
# Main #
########

project (nn-simulator CXX)

set(PROJECT_NAME nn-simulator)
set(PROJECT_SOURCE_DIR src)
set(PROJECT_INCLUDE_DIR include/nn-simulator)

include_directories(${PROJECT_INCLUDE_DIR})

# list all source files here
# TODO: replace this with a macro
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

################################################
# GTest - http://code.google.com/p/googletest/ #
################################################
add_subdirectory(gtest-1.6.0) 
enable_testing(true) 

include_directories(src ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#add_executable(unit-tests test/unit-tests.cpp) 
#target_link_libraries(unit-tests gtest gtest_main) 
#add_test(unit-tests unit-tests) 

