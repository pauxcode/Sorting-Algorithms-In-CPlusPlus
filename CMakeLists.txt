cmake_minimum_required(VERSION 3.25)
project(Algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(Algorithms src/main.cpp src/sortingAlgorithms.h "src/Sorting Algorithms/bubbleSort.cpp" "src/Sorting Algorithms/quickSort.cpp" src/Utilities/swap.cpp src/Utilities/printArray.cpp "src/Sorting Algorithms/insertSort.cpp" "src/Sorting Algorithms/mergeSort.cpp" src/Utilities/generateArray.cpp src/Utilities/menu.cpp)
