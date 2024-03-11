cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(hanoi VERSION 1.0)
add_compile_options(-Wall -Wextra -pedantic -Werror -O3)
include_directories(include)
add_executable(hanoi src/Hanoi.cc)
