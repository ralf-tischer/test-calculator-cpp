# Version#
cmake_minimum_required(VERSION 3.31)

# Set the project name
set(PROJECT_NAME RatsiCalculator)

# Set the project path
set(PROJECT_PATH ${CMAKE_SOURCE_DIR})

# Project name
project(${PROJECT_NAME})

# Add executable
add_executable(${PROJECT_NAME} ${PROJECT_PATH}/ratsi-calculator.cpp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the source file
set(SOURCE_FILE ${PROJECT_PATH}/Assets/test.txt)

# Specify the destination directory
set(DESTINATION_DIR ${CMAKE_BINARY_DIR}/Debug/Assets)

# Create the destination directory if it doesn't exist
file(MAKE_DIRECTORY ${DESTINATION_DIR})

# Copy the file to the destination directory
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${SOURCE_FILE} ${DESTINATION_DIR}
)