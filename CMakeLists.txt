cmake_minimum_required(VERSION 3.10)
project(ScientificCalculator)

set(CMAKE_CXX_STANDARD 14)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_executable(calculator
    src/calc.cpp
)

add_executable(calculator_test 
    tests/tests.cpp
    src/calc.cpp
)

enable_testing()
add_test(NAME calculator_tests COMMAND calculator_test)