cmake_minimum_required(VERSION 3.9)

# set the project name
project(Fox VERSION 1.0)

set(GCC_COVERAGE_COMPILE_FLAGS "-O3 -pedantic -Wall -Wextra -Werror --std=gnu++20")

file(GLOB src_deps
    "include/*.cpp"
    "include/*.hpp"
)

add_executable(fox fox.cpp ${src_deps})
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
target_include_directories(fox PUBLIC include)
