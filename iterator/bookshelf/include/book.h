#pragma once

#define BOOK_NAME_LENGTH_MAX (128)

typedef struct book_t book_t;
struct book_t {
    char name[BOOK_NAME_LENGTH_MAX];
    void (*del)(book_t *book);
};

typedef struct {
    const char *name;
} book_config_t;

book_t *new_book(const book_config_t *config);
