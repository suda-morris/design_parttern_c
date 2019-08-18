add_library(
    bookshelf STATIC "src/book.c" "src/bookshelf_iterator.c" "src/bookshelf.c"
)

target_include_directories(
    bookshelf PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)