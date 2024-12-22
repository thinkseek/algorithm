cmake_minimum_required(VERSION 3.8)
project(algorithm)
set(CMAKE_CXX_STANDARD 11)

# 指定题目文件
set(TwoSumSolution src/category/maths/DoTwoSumSolution.cpp
        src/category/arrays/DoThreeSumSolution.cpp
)
add_executable(TwoSumSolution ${TwoSumSolution})

#set(DoMaxNoDuplicateStringsSolution src/category/strings/DoMaxNoDuplicateStringsSolution.cpp
#        src/category/strings/DoMaxNoDuplicateStringsSolution.h
#        src/category/main.cpp)
#add_executable(DoMaxNoDuplicateStringsSolution ${DoMaxNoDuplicateStringsSolution})
