cmake_minimum_required(VERSION 3.10)

project(ft)

aux_source_directory(printf_src PRINTF_SRC)
aux_source_directory(libft_src LIBFT_SRC)

add_library(ft "${LIBFT_SRC}" "${PRINTF_SRC}")

target_include_directories(ft PUBLIC ./)
target_include_directories(ft PUBLIC printf_includes/)
