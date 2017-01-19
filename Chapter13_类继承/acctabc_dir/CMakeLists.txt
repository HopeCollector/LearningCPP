cmake_minimum_required (VERSION 3.0)
project(brass)
set (CMAKE_CXX_FLAGS "-std=c++0x -stdlib=libc++ -g3 -Wall -O0")
add_executable(brass acctabc.cpp abc_main.cpp)
