# CMake build script for Neural Network Simulator.

cmake_minimum_required (VERSION 2.6)

########
# Main #
########

project (nn-simulator)

set(TESTING "NONE" CACHE STRING "NONE")
set(COVERAGE "NONE" CACHE STRING "NONE")

set(NNSIM_NAME nn-simulator)
set(NNSIM_LIB neural_network)
set(NNSIM_SOURCE_DIR src)
set(NNSIM_INCLUDE_DIR include)
set(NNSIM_TEST_DIR test/src)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

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

################################################
# GTest - http://code.google.com/p/googletest/ #
################################################
    
message("-- Testing mode: ${TESTING}")

IF(("FAST" STREQUAL TESTING) OR ("ALL" STREQUAL TESTING))

    message("-- Testing is enabled.")

    set(Boost_USE_MULTITHREADED ON)
    find_package(Boost COMPONENTS 
        unit_test_framework
        REQUIRED)
    enable_testing(true)

    include_directories(
        ${Boost_INCLUDE_DIRS}
    )

    ################################################
    # Code coverage ################################
    ################################################

    message("-- Coverage mode: ${COVERAGE}")
    if(("LCOV" STREQUAL COVERAGE) OR ("COBERTURA" STREQUAL COVERAGE))

      set(CMAKE_BUILD_TYPE "Debug")

      if(NOT CMAKE_COMPILER_IS_GNUCXX)
        message("-- Compiler not GNU, cannot create coverage report.")
      else()      
        FIND_PROGRAM(PYTHON_EXECUTABLE
          NAMES python python3
          PATHS /usr/bin /usr/local/bin /usr/pkg/bin
        )
        include(CodeCoverage)
        message("-- Code coverage is enabled.")

        if("LCOV" STREQUAL COVERAGE)
          SETUP_TARGET_FOR_COVERAGE(coverage ctest coverage)
        else()
          SETUP_TARGET_FOR_COVERAGE_COBERTURA(coverage ctest coverage)
        endif()

      endif()

    endif()

    # left test definitions here
    # TODO: replace this with a macro

    add_executable(FunctionTests 
        ${NNSIM_TEST_DIR}/functions/HeavisideFunctionTest.cpp
        ${NNSIM_TEST_DIR}/functions/SigmoidFunctionTest.cpp) 
    target_link_libraries(FunctionTests
        ${NNSIM_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}) 
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
    target_link_libraries(ModelTests
        ${NNSIM_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}) 
    add_test(ModelTests ModelTests)

    add_executable(NetTests
        ${NNSIM_TEST_DIR}/nets/NetFactoryTest.cpp 
        ${NNSIM_TEST_DIR}/nets/NeuronFactoryTest.cpp 
        ${NNSIM_TEST_DIR}/nets/BDN/BDNTest.cpp 
        ${NNSIM_TEST_DIR}/nets/BDN/BDNTrainerTest.cpp 
        ${NNSIM_TEST_DIR}/nets/BDN/LogicalArchitectureTest.cpp
        ${NNSIM_TEST_DIR}/nets/BDN/realisations/ORnetTest.cpp)
    target_link_libraries(NetTests
        ${NNSIM_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
    add_test(NetTests NetTests)

    add_executable(TrainerTests 
        ${NNSIM_TEST_DIR}/trainer/TrainerTest.cpp)
    target_link_libraries(TrainerTests
        ${NNSIM_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}) 
    add_test(TrainerTests TrainerTests)

    add_executable(UtilTests 
        ${NNSIM_TEST_DIR}/util/FactoryTest.cpp
        ${NNSIM_TEST_DIR}/util/exceptions/ExceptionTest.cpp
        ${NNSIM_TEST_DIR}/util/exceptions/IllegalArgumentExceptionTest.cpp
        ${NNSIM_TEST_DIR}/util/exceptions/OutOfBoundsExceptionTest.cpp
        ${NNSIM_TEST_DIR}/util/exceptions/UnsupportedConfigurationExceptionTest.cpp) 
    target_link_libraries(UtilTests
        ${NNSIM_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}) 
    add_test(UtilTests UtilTests)

ENDIF()

IF("ALL" STREQUAL TESTING)

    message("-- Integration testing is enabled.")

    add_executable(IntegrationTests
        ${NNSIM_TEST_DIR}/integration/IntegrationTests.cpp
    ) 
    target_link_libraries(IntegrationTests
        ${NNSIM_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
    add_test(IntegrationTests IntegrationTests)

ENDIF()
    
add_executable (${NNSIM_NAME}
	${NNSIM_SOURCE_DIR}/main.cpp)
target_link_libraries(${NNSIM_NAME}
	${NNSIM_LIB})
