cmake_minimum_required(VERSION 3.10)
project(20S-3353-PA04)
set (EXE_NAME pa04)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "-Wall -O3")


file(COPY data DESTINATION .)
file(COPY output DESTINATION .)

add_executable(PA04 main.cpp graph.cpp graph.h Anneal.cpp Anneal.h BruteForce.cpp BruteForce.h)