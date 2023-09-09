cmake_minimum_required(VERSION 3.16)
include(CMakePrintHelpers)


# set the project name
project(tetris)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
set(EXECUTABLE_NAME "tetris_main")
add_executable(${EXECUTABLE_NAME} src/main.cpp)

# Detect and add SFML
# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
cmake_print_variables(CMAKE_CURRENT_SOURCE_DIR)

find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics network audio)

target_link_libraries(${EXECUTABLE_NAME} sfml-graphics)

# sfml-system
# sfml-window
# sfml-network
# sfml-graphics
# sfml-audio
# sfml-main