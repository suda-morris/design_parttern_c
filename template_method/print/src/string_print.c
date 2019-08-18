#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "string_print.h"

#define PRINT_STRING_MAX_LENGTH (32)

typedef struct string_print_t string_print_t;
struct string_print_t {
    abstract_print_t abs_print;
    char str[PRINT_STRING_MAX_LENGTH];
};

#ifndef container_of
#define container_of(PTR, TYPE, MEMBER)                      \
    ({                                                       \
        const __typeof(((TYPE *)0)->MEMBER) *__mptr = (PTR); \
        (TYPE *)((char *)__mptr - offsetof(TYPE, MEMBER));   \
    })
#endif

static void string_print_open(abstract_print_t *p)
{
    printf("+++++++++++++++\r\n");
}

static void string_print_print(abstract_print_t *p)
{
    string_print_t *sprint = (string_print_t *) container_of(p, string_print_t,
                             abs_print);
    printf("++%s++\r\n", sprint->str);
}

static void string_print_close(abstract_print_t *p)
{
    printf("+++++++++++++++\r\n");
}

static void string_print_del(abstract_print_t *p)
{
    string_print_t *sprint = (string_print_t *) container_of(p, string_print_t,
                             abs_print);
    free(sprint);
}

abstract_print_t *new_string_print(const string_print_config_t *config)
{
    if (!config) {
        goto err;
    }
    string_print_t *sprint = calloc(1, sizeof(string_print_t));
    if (!sprint) {
        goto err;
    }
    strncpy(sprint->str, config->str, PRINT_STRING_MAX_LENGTH);
    sprint->abs_print.display = abstract_display;
    sprint->abs_print.open = string_print_open;
    sprint->abs_print.close = string_print_close;
    sprint->abs_print.print = string_print_print;
    sprint->abs_print.del = string_print_del;
    return &sprint->abs_print;
err: return NULL;
}
