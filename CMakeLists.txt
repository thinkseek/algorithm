cmake_minimum_required(VERSION 3.8)
project(algorithm)
set(CMAKE_CXX_STANDARD 11)

# 指定题目文件
set(TwoSumSolution src/category/hash-table/DoTwoSumSolution.cpp
        src/category/arrays/DoThreeSumSolution.cpp
        src/category/linked-list/DoMergeTwoListsSolution.cpp
)
add_executable(TwoSumSolution ${TwoSumSolution})
