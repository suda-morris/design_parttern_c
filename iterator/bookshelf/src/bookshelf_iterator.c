#include <stdlib.h>
#include <stddef.h>
#include "bookshelf_iterator.h"

typedef struct bookshelf_iterator_t bookshelf_iterator_t;
struct bookshelf_iterator_t {
    long cursor;
    iterator_t iterator;
    bookshelf_t *bookshelf;
};

#ifndef container_of
#define container_of(PTR, TYPE, MEMBER)                      \
    ({                                                       \
        const __typeof(((TYPE *)0)->MEMBER) *__mptr = (PTR); \
        (TYPE *)((char *)__mptr - offsetof(TYPE, MEMBER));   \
    })
#endif

static bool bookshelf_has_next(iterator_t *it)
{
    bookshelf_iterator_t *bookshelf_it = container_of(it, bookshelf_iterator_t,
                                         iterator);
    return bookshelf_it->cursor < bookshelf_it->bookshelf->amount;
}

static void *bookshelf_next(iterator_t *it)
{
    bookshelf_iterator_t *bookshelf_it = container_of(it, bookshelf_iterator_t,
                                         iterator);
    long index = bookshelf_it->cursor;
    if (index >= bookshelf_it->bookshelf->amount) {
        goto err;
    }
    bookshelf_it->cursor++;
    return bookshelf_it->bookshelf->books[index];
err: return NULL;
}

static void bookshelf_iterator_del(iterator_t *it)
{
    bookshelf_iterator_t *bookshelf_it = container_of(it, bookshelf_iterator_t,
                                         iterator);
    free(bookshelf_it);
}

iterator_t *new_bookshelf_iterator(const bookshelf_iterator_config_t *config)
{
    if (!config) {
        goto err;
    }
    bookshelf_iterator_t *bookshelf_it = calloc(1,
                                         sizeof(bookshelf_iterator_t));
    if (!bookshelf_it) {
        goto err;
    }
    bookshelf_it->bookshelf = config->bookshelf;
    bookshelf_it->cursor = 0;
    bookshelf_it->iterator.has_next = bookshelf_has_next;
    bookshelf_it->iterator.next = bookshelf_next;
    bookshelf_it->iterator.del = bookshelf_iterator_del;
    return &bookshelf_it->iterator;
err: return NULL;
}
