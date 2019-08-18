#pragma once

#include <stdbool.h>

typedef struct iterator_t iterator_t;
struct iterator_t {
    bool (*has_next)(iterator_t *it);
    void *(*next)(iterator_t *it);
    void (*del)(iterator_t *it);
};
