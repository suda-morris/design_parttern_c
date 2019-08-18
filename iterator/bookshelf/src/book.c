#include <stdlib.h>
#include <string.h>
#include "book.h"

static void book_del(book_t *book)
{
    free(book);
}

book_t *new_book(const book_config_t *config)
{
    if (!config) {
        goto err;
    }
    book_t *book = calloc(1, sizeof(book_t));
    strncpy(book->name, config->name, BOOK_NAME_LENGTH_MAX);
    book->del = book_del;
    return book;
err: return NULL;
}
