#include <stdio.h>
#include <stdlib.h>
#include "bookshelf.h"

static void add_book2shelf(const char *name, bookshelf_t *bookshelf)
{
    book_config_t config = { .name = name };
    book_t *book = new_book(&config);
    bookshelf->push(bookshelf, book);
}

int main(void)
{
    bookshelf_config_t bookshelf_config = { .capacity = 100 };
    bookshelf_t *bookshelf = new_bookshelf(&bookshelf_config);

    add_book2shelf("hello", bookshelf);
    add_book2shelf("world", bookshelf);

    iterator_t *it = bookshelf->iterator(bookshelf);
    while (it->has_next(it)) {
        book_t *book = (book_t *) it->next(it);
        printf("%s ", book->name);
    }
    printf("\r\n");
    it->del(it);
    it = bookshelf->iterator(bookshelf);
    add_book2shelf("morris", bookshelf);
    while (it->has_next(it)) {
        book_t *book = (book_t *) it->next(it);
        printf("%s ", book->name);
    }
    printf("\r\n");
    it->del(it);
    bookshelf->del(bookshelf);
    return 0;
}
