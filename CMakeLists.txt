cmake_minimum_required(VERSION 3.8)
project(algorithm)
set(CMAKE_CXX_STANDARD 11)

# 指定题目文件
set(TwoSumSolution src/category/math/TwoSumSolution.cpp)
add_executable(TwoSumSolution ${TwoSumSolution})
