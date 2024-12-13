# Version
cmake_minimum_required(VERSION 3.15)

# Project name
project(TestCalculator)

# Add executable
add_executable(TestCalculator ./test-calculator-cpp.cpp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Copy Assets folder to build directory
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Specify the source file
set(SOURCE_FILE ${CMAKE_SOURCE_DIR}/Assets/test.txt)

# Specify the destination directory
set(DESTINATION_DIR ${CMAKE_BINARY_DIR}/Debug/Assets)

# Create the destination directory if it doesn't exist
file(MAKE_DIRECTORY ${DESTINATION_DIR})

# Copy the file to the destination directory
add_custom_command(
    TARGET TestCalculator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${SOURCE_FILE} ${DESTINATION_DIR}
)