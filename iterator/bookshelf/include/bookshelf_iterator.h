#pragma once

#include "iterator.h"
#include "bookshelf.h"

typedef struct {
    bookshelf_t *bookshelf;
} bookshelf_iterator_config_t;

iterator_t *new_bookshelf_iterator(const bookshelf_iterator_config_t *config);
