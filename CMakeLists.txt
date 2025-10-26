cmake_minimum_required(VERSION 4.0)
project(advent_2024)

set(CMAKE_CXX_STANDARD 14)

include_directories(day1/C
utils
)
add_executable(advent_2024
        day1/C/main.c
        utils/utils.c
)
