#include <stdlib.h>
#include <string.h>
#include "bookshelf.h"
#include "bookshelf_iterator.h"

static long bookshelf_push(bookshelf_t *bookshelf, book_t *book)
{
    if (!book) {
        goto err;
    }
    bookshelf->books[bookshelf->amount] = book;
    bookshelf->amount++;
    return bookshelf->amount;
err: return -1;
}

static iterator_t *bookshelf_iterator(bookshelf_t *bookshelf)
{
    bookshelf_iterator_config_t it_config = { .bookshelf = bookshelf };
    iterator_t *iterator = new_bookshelf_iterator(&it_config);
    if (!iterator) {
        goto err;
    }
    return iterator;
err: return NULL;
}

static void bookshelf_del(bookshelf_t *bookshelf)
{
    book_t *book = NULL;
    for (long i = 0; i < bookshelf->amount; i++) {
        book = bookshelf->books[i];
        book->del(book);
    }
    free(bookshelf->books);
    free(bookshelf);
}

bookshelf_t *new_bookshelf(const bookshelf_config_t *config)
{
    if (!config) {
        goto err;
    }
    bookshelf_t *bookshelf = calloc(1, sizeof(bookshelf_t));
    if (!bookshelf) {
        goto err;
    }
    bookshelf->amount = 0;
    bookshelf->capacity = config->capacity;
    bookshelf->books = calloc(config->capacity, sizeof(book_t *));
    if (!bookshelf->books) {
        goto err_books;
    }
    bookshelf->push = bookshelf_push;
    bookshelf->iterator = bookshelf_iterator;
    bookshelf->del = bookshelf_del;
    return bookshelf;
err_books: free(bookshelf);
err: return NULL;
}

