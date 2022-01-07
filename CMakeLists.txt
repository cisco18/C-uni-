cmake_minimum_required(VERSION 3.20)
project(miniprojekt)

set(CMAKE_CXX_STANDARD 23)

add_executable(miniprojekt main.cpp CMax3SatProblem.cpp CMax3SatProblem.h CGAIndividual.cpp CGAIndividual.h CGAOptimizer.cpp CGAOptimizer.h)
