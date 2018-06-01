cmake_minimum_required(VERSION 3.7)
project(Data_Structures)

set(CMAKE_C_STANDARD 90)
#BinarySearchTree.c BinarySearchTree.h
set(LIB_SRC_FILES LinkedList.h LinkedList.c )
add_library(Data_Structures-Beta SHARED ${LIB_SRC_FILES})

set(SOURCE_FILES test1.c LinkedList.h)
add_executable(test1 ${SOURCE_FILES})
target_link_libraries(test1 Data_Structures-Beta)