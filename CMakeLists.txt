# CMake build script for Nessus.

cmake_minimum_required (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnuc++11")
message("-- C++ flags: ${CMAKE_CXX_FLAGS}")

########
# Main #
########

project (nessus)

set(TESTING "NONE" CACHE STRING "NONE")
set(COVERAGE "NONE" CACHE STRING "NONE")

set(NESSUS_NAME nessus)
set(NESSUS_LIB neural_network)
set(NESSUS_SOURCE_DIR src)
set(NESSUS_INCLUDE_DIR include)
set(NESSUS_TEST_DIR test/src)
set(NESSUS_MOCK_DIR test/mock)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

include_directories(${NESSUS_INCLUDE_DIR})

# list all source files here
# TODO: replace this with a macro

add_library (${NESSUS_LIB}
    ${NESSUS_SOURCE_DIR}/functions/HeavisideFunction.cpp
    ${NESSUS_SOURCE_DIR}/functions/SigmoidFunction.cpp
    ${NESSUS_SOURCE_DIR}/model/Architecture.cpp
    ${NESSUS_SOURCE_DIR}/model/Layer.cpp
    ${NESSUS_SOURCE_DIR}/model/Net.cpp
    ${NESSUS_SOURCE_DIR}/model/Neuron.cpp
    ${NESSUS_SOURCE_DIR}/model/Output.cpp
    ${NESSUS_SOURCE_DIR}/model/Vector.cpp
    ${NESSUS_SOURCE_DIR}/nets/BDN/BDN.cpp
    ${NESSUS_SOURCE_DIR}/nets/BDN/BDNTrainer.cpp
    ${NESSUS_SOURCE_DIR}/nets/BDN/LogicalArchitecture.cpp
    ${NESSUS_SOURCE_DIR}/nets/BDN/realisations/ORnet.cpp
    ${NESSUS_SOURCE_DIR}/trainer/Trainer.cpp)

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
        ${NESSUS_MOCK_DIR}
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
        ${NESSUS_TEST_DIR}/functions/HeavisideFunctionTest.cpp
        ${NESSUS_TEST_DIR}/functions/SigmoidFunctionTest.cpp) 
    target_link_libraries(FunctionTests
        ${NESSUS_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}) 
    add_test(FunctionTests FunctionTests)

    add_executable(ModelTests 
        ${NESSUS_TEST_DIR}/model/exceptions/EmptyVectorExceptionTest.cpp
        ${NESSUS_TEST_DIR}/model/exceptions/IncorrectInputExceptionTest.cpp
        ${NESSUS_TEST_DIR}/model/exceptions/LayerNotSetExceptionTest.cpp
        ${NESSUS_TEST_DIR}/model/ArchitectureTest.cpp
        ${NESSUS_TEST_DIR}/model/InputTest.cpp
        ${NESSUS_TEST_DIR}/model/LayerTest.cpp
        ${NESSUS_TEST_DIR}/model/NetTest.cpp
        ${NESSUS_TEST_DIR}/model/NeuronTest.cpp
        ${NESSUS_TEST_DIR}/model/OutputTest.cpp
        ${NESSUS_TEST_DIR}/model/VectorTest.cpp
        ${NESSUS_TEST_DIR}/model/WeightsTest.cpp) 
    target_link_libraries(ModelTests
        ${NESSUS_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}) 
    add_test(ModelTests ModelTests)

    add_executable(NetTests
        ${NESSUS_TEST_DIR}/nets/NetFactoryTest.cpp 
        ${NESSUS_TEST_DIR}/nets/NeuronFactoryTest.cpp 
        ${NESSUS_TEST_DIR}/nets/BDN/BDNTest.cpp 
        ${NESSUS_TEST_DIR}/nets/BDN/BDNTrainerTest.cpp 
        ${NESSUS_TEST_DIR}/nets/BDN/LogicalArchitectureTest.cpp
        ${NESSUS_TEST_DIR}/nets/BDN/realisations/ORnetTest.cpp)
    target_link_libraries(NetTests
        ${NESSUS_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
    add_test(NetTests NetTests)

    add_executable(TrainerTests 
        ${NESSUS_TEST_DIR}/trainer/TrainerTest.cpp)
    target_link_libraries(TrainerTests
        ${NESSUS_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}) 
    add_test(TrainerTests TrainerTests)

    add_executable(UtilTests 
        ${NESSUS_TEST_DIR}/util/FactoryTest.cpp
        ${NESSUS_TEST_DIR}/util/exceptions/ExceptionTest.cpp
        ${NESSUS_TEST_DIR}/util/exceptions/IllegalArgumentExceptionTest.cpp
        ${NESSUS_TEST_DIR}/util/exceptions/OutOfBoundsExceptionTest.cpp
        ${NESSUS_TEST_DIR}/util/exceptions/UnsupportedConfigurationExceptionTest.cpp) 
    target_link_libraries(UtilTests
        ${NESSUS_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}) 
    add_test(UtilTests UtilTests)

ENDIF()

IF("ALL" STREQUAL TESTING)

    message("-- Integration testing is enabled.")

    add_executable(IntegrationTests
        ${NESSUS_TEST_DIR}/integration/IntegrationTests.cpp
    ) 
    target_link_libraries(IntegrationTests
        ${NESSUS_LIB}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
    add_test(IntegrationTests IntegrationTests)

ENDIF()
    
add_executable (${NESSUS_NAME}
	${NESSUS_SOURCE_DIR}/main.cpp)
target_link_libraries(${NESSUS_NAME}
	${NESSUS_LIB})
