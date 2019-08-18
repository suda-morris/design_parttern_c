cmake_minimum_required(VERSION 3.5)
project(template_method VERSION 1.0.0)

add_subdirectory(print)

add_executable(app "main.c")

target_link_libraries(app PRIVATE print)