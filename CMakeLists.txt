cmake_minimum_required(VERSION 3.12)
project(traffic_shaping_array)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

set(TOKEN_ARRAY_LIMIT
        TokenArrayLimit.h
        TokenArrayLimit.cpp)

add_executable(traffic_shaping_array
        TokenArrayLimit.cpp)
