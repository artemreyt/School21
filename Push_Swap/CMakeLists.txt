cmake_minimum_required(VERSION 3.10)

project(Push_Swap)

add_subdirectory(Libft)
link_libraries(ft)

add_library(IntStack src/StackPair/IntStack/IntNode.c
        src/StackPair/IntStack/IntStack.c
        src/StackPair/IntStack/IntStack_extension.c
        src/StackPair/IntStack/IntStack_create_free.c)
target_include_directories(IntStack PUBLIC include/StackPair/IntStack)

add_library(StackPair   src/StackPair/StackPair.c
                        src/StackPair/Swap_cmds.c
                        src/StackPair/Push_cmds.c
                        src/StackPair/Rotate_cmds.c
                        src/StackPair/ReverseRotate_cmds.c
                        src/StackPair/StackPair_utility.c)
target_include_directories(StackPair PUBLIC include/StackPair)
target_link_libraries(StackPair IntStack)

add_library(ftChecker STATIC src/Checker/checker_invalid.c src/Checker/checker.c)
target_include_directories(ftChecker PUBLIC include/Checker)
target_link_libraries(ftChecker StackPair)

aux_source_directory(src/Push_Swap PUSH_SWAP_SRC)
add_executable(push_swap "${PUSH_SWAP_SRC}")
target_link_libraries(push_swap StackPair ftChecker)
target_include_directories(push_swap PRIVATE include/Push_Swap)

add_executable(checker src/Checker/checker_main.c)
target_link_libraries(checker ftChecker)
target_include_directories(checker PRIVATE include/Checker)