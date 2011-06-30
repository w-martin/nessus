# CMake build script for Neural Network Simulator.

cmake_minimum_required (VERSION 2.6)

#set(CMAKE_C_COMPILER clang)
#set(CMAKE_CXX_COMPILER clang++)

########
# Main #
########

project (nn-simulator CXX)

set(NNSIM_NAME nn-simulator)
set(NNSIM_LIB lib-nn-simulator)
set(NNSIM_SOURCE_DIR src)
set(NNSIM_INCLUDE_DIR include/nn-simulator)
set(NNSIM_TEST_DIR test)

include_directories(${NNSIM_INCLUDE_DIR})

# list all source files here
# TODO: replace this with a macro

add_library (${NNSIM_LIB}
    ${NNSIM_SOURCE_DIR}/functions/HeavisideFunction.cpp
    ${NNSIM_SOURCE_DIR}/functions/SigmoidFunction.cpp
    ${NNSIM_SOURCE_DIR}/model/Architecture.cpp
    ${NNSIM_SOURCE_DIR}/model/Layer.cpp
    ${NNSIM_SOURCE_DIR}/model/Net.cpp
    ${NNSIM_SOURCE_DIR}/model/Neuron.cpp
    ${NNSIM_SOURCE_DIR}/model/Output.cpp
    ${NNSIM_SOURCE_DIR}/model/Vector.cpp
    ${NNSIM_SOURCE_DIR}/nets/NetsFactory.cpp
    ${NNSIM_SOURCE_DIR}/nets/BDN/BDN.cpp
    ${NNSIM_SOURCE_DIR}/nets/BDN/BDNTrainer.cpp
    ${NNSIM_SOURCE_DIR}/nets/BDN/LogicalArchitecture.cpp
    ${NNSIM_SOURCE_DIR}/nets/BDN/realisations/ORnet.cpp
    ${NNSIM_SOURCE_DIR}/trainer/Trainer.cpp)
    
add_executable (${NNSIM_NAME}
	${NNSIM_SOURCE_DIR}/main.cpp)
target_link_libraries(${NNSIM_NAME}
	${NNSIM_LIB})

################################################
# GTest - http://code.google.com/p/googletest/ #
################################################
    
add_subdirectory(gmock-1.6.0) 
enable_testing(true) 

include_directories(${gtest_SOURCE_DIR}/include 
	${gtest_SOURCE_DIR})
	
# left test definitions here
# TODO: replace this with a macro

add_executable(FunctionTests 
	${NNSIM_TEST_DIR}/functions/HeavisideFunctionTest.cpp
	${NNSIM_TEST_DIR}/functions/SigmoidFunctionTest.cpp) 
target_link_libraries(FunctionTests gtest gtest_main ${NNSIM_LIB}) 
add_test(FunctionTests FunctionTests)

add_executable(ModelTests 
	${NNSIM_TEST_DIR}/model/OutputTest.cpp
	${NNSIM_TEST_DIR}/model/VectorTest.cpp) 
target_link_libraries(ModelTests gtest gtest_main ${NNSIM_LIB}) 
add_test(ModelTests ModelTests)
