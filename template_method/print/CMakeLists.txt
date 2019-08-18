add_library(
    print STATIC "src/abstract_print.c" "src/char_print.c" "src/string_print.c"
)

target_include_directories(print PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")