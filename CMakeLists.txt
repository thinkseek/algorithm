cmake_minimum_required(VERSION 3.8)
project(algorithm)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# arrays
#set(yg_algorithm src/category/arrays/DoThreeSumSolution.cpp)
# hash-table
#set(yg_algorithm src/category/hash-table/DoTwoSumSolution.cpp)
# heaps
#set(yg_algorithm src/category/heaps/DoKthLargest.cpp)
# linked-list
#set(yg_algorithm src/category/linked-list/DoMergeTwoListsSolution.cpp)
# queues
#set(yg_algorithm src/category/queues/DoMyStack.cpp)
# stacks
#set(yg_algorithm src/category/stacks/DoEffectiveBracketSolution.cpp)
# strings
#set(yg_algorithm src/category/strings/DoMaxNoDuplicateStringsSolution.cpp)
# trees
#set(yg_algorithm src/category/trees/DoTreeInorderTraversalSolution.cpp)
# graphs
#set(yg_algorithm src/category/graphs/DoFindValidPathSolution.cpp)
# algorithm/findx
set(yg_algorithm src/category/algorithm/findx/DoBinarySearchSolution.cpp)
# algorithm/sortx
#set(yg_algorithm src/category/algorithm/sortx/DoMergeTwoArraySolution.cpp)

# 产出
add_executable(yg_algorithm ${yg_algorithm})
