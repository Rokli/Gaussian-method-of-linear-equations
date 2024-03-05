cmake_minimum_required(VERSION 3.27)
project(GaussianMethodSolve)

set(CMAKE_CXX_STANDARD 23)

add_executable(GaussianMethodSolve main.cpp
        GaussMethod.h
        SimpleIterationMethod.cpp
        SimpleIterationMethod.h)
