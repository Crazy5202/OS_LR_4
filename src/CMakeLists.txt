cmake_minimum_required(VERSION 3.0)
project(Dynamic_library)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(impl1 SHARED impl1.c)
target_link_libraries(impl1 m)
add_library(impl2 SHARED impl2.c)

add_executable(static static.c)
add_executable(dynamic dynamic.c)

target_link_libraries(static impl1)