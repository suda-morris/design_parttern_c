#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "char_print.h"

typedef struct char_print_t char_print_t;
struct char_print_t {
    abstract_print_t abs_print;
    char c;
};

#ifndef container_of
#define container_of(PTR, TYPE, MEMBER)                      \
    ({                                                       \
        const __typeof(((TYPE *)0)->MEMBER) *__mptr = (PTR); \
        (TYPE *)((char *)__mptr - offsetof(TYPE, MEMBER));   \
    })
#endif

static void char_print_open(abstract_print_t *p)
{
    printf("<<<");
}

static void char_print_close(abstract_print_t *p)
{
    printf(">>>\r\n");
}

static void char_print_print(abstract_print_t *p)
{
    char_print_t *char_print = (char_print_t *) container_of(p, char_print_t,
                               abs_print);
    printf("%c", char_print->c);
}

static void char_print_del(abstract_print_t *p)
{
    char_print_t *char_print = (char_print_t *) container_of(p, char_print_t,
                               abs_print);
    free(char_print);
}

abstract_print_t *new_char_print(const char_print_config_t *config)
{
    if (!config) {
        goto err;
    }
    char_print_t *char_print = calloc(1, sizeof(char_print_t));
    char_print->c = config->c;
    char_print->abs_print.display = abstract_display;
    char_print->abs_print.open = char_print_open;
    char_print->abs_print.close = char_print_close;
    char_print->abs_print.print = char_print_print;
    char_print->abs_print.del = char_print_del;
    return &char_print->abs_print;
err: return NULL;
}
