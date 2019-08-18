#pragma once

#include "iterator.h"
#include "book.h"

typedef struct bookshelf_t bookshelf_t;
struct bookshelf_t {
    long capacity;
    long amount;
    book_t **books;
    long (*push)(bookshelf_t *bookshelf, book_t *book);
    iterator_t *(*iterator)(bookshelf_t *bookshelf);
    void (*del)(bookshelf_t *bookshelf);
};

typedef struct {
    long capacity;
} bookshelf_config_t;

bookshelf_t *new_bookshelf(const bookshelf_config_t *config);
