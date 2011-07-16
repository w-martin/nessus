# CMake build script for Neural Network Simulator.

cmake_minimum_required (VERSION 2.6)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

########
# Main #
########

project (nn-simulator CXX)

set(NNSIM_NAME nn-simulator)
set(NNSIM_LIB neural_network)
set(NNSIM_SOURCE_DIR src)
set(NNSIM_INCLUDE_DIR include)
set(NNSIM_TEST_DIR test)
# set(NNSIM_BIN_DIR bin)
# set(NNSIM_LIB_DIR lib)

# file(MAKE_DIRECTORY ${NNSIM_BIN_DIR})
# file(MAKE_DIRECTORY ${NNSIM_LIB_DIR})

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
	${gtest_SOURCE_DIR}
        ${gmock_SOURCE_DIR}/include 
	${gmock_SOURCE_DIR})
	
# left test definitions here
# TODO: replace this with a macro

add_executable(FunctionTests 
	${NNSIM_TEST_DIR}/functions/HeavisideFunctionTest.cpp
	${NNSIM_TEST_DIR}/functions/SigmoidFunctionTest.cpp) 
target_link_libraries(FunctionTests gtest gtest_main ${NNSIM_LIB}) 
add_test(FunctionTests FunctionTests)

add_executable(ModelTests 
	${NNSIM_TEST_DIR}/model/exceptions/EmptyVectorExceptionTest.cpp
	${NNSIM_TEST_DIR}/model/exceptions/IncorrectInputExceptionTest.cpp
	${NNSIM_TEST_DIR}/model/exceptions/LayerNotSetExceptionTest.cpp
	${NNSIM_TEST_DIR}/model/ArchitectureTest.cpp
	${NNSIM_TEST_DIR}/model/InputTest.cpp
	${NNSIM_TEST_DIR}/model/LayerTest.cpp
	${NNSIM_TEST_DIR}/model/NetTest.cpp
	${NNSIM_TEST_DIR}/model/NeuronTest.cpp
	${NNSIM_TEST_DIR}/model/OutputTest.cpp
	${NNSIM_TEST_DIR}/model/VectorTest.cpp
	${NNSIM_TEST_DIR}/model/WeightsTest.cpp) 
target_link_libraries(ModelTests gmock gmock_main ${NNSIM_LIB}) 
add_test(ModelTests ModelTests)

add_executable(NetTests
	${NNSIM_TEST_DIR}/nets/NetFactoryTest.cpp 
	${NNSIM_TEST_DIR}/nets/NeuronFactoryTest.cpp 
	${NNSIM_TEST_DIR}/nets/BDN/BDNTest.cpp 
	${NNSIM_TEST_DIR}/nets/BDN/BDNTrainerTest.cpp 
        ${NNSIM_TEST_DIR}/nets/BDN/LogicalArchitectureTest.cpp
        ${NNSIM_TEST_DIR}/nets/BDN/realisations/ORnetTest.cpp)
target_link_libraries(NetTests gmock gmock_main ${NNSIM_LIB})
add_test(NetTests NetTests)

add_executable(TrainerTests 
	${NNSIM_TEST_DIR}/trainer/TrainerTest.cpp)
target_link_libraries(TrainerTests gmock gmock_main ${NNSIM_LIB}) 
add_test(TrainerTests TrainerTests)

add_executable(UtilTests 
	${NNSIM_TEST_DIR}/util/FactoryTest.cpp
	${NNSIM_TEST_DIR}/util/exceptions/ExceptionTest.cpp
	${NNSIM_TEST_DIR}/util/exceptions/IllegalArgumentExceptionTest.cpp
	${NNSIM_TEST_DIR}/util/exceptions/OutOfBoundsExceptionTest.cpp
	${NNSIM_TEST_DIR}/util/exceptions/UnsupportedConfigurationExceptionTest.cpp) 
target_link_libraries(UtilTests gtest gtest_main ${NNSIM_LIB}) 
add_test(UtilTests UtilTests)
