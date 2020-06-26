cmake_minimum_required(VERSION 3.10)

project(Push_Swap)

add_subdirectory(Libft)
link_libraries(ft)

add_library(IntStack src/IntStack/IntNode.c src/IntStack/IntStack.c src/IntStack/IntStack_extension.c)
target_include_directories(IntStack PUBLIC include/IntStack)

add_library(StackPair src/StackPair/StackPair.c src/StackPair/Swap_cmds.c src/StackPair/Push_cmds.c src/StackPair/Rotate_cmds.c src/StackPair/ReverseRotate_cmds.c)
target_include_directories(StackPair PUBLIC include/StackPair)
target_link_libraries(StackPair IntStack)