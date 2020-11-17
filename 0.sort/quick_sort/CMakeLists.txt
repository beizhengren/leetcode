project(QuickSort)
cmake_minimum_required(VERSION 3.17)
add_executable(quicksort)
target_sources(quicksort PRIVATE
        main.cpp
        quick_sort.cpp)
