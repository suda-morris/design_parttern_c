#pragma once

typedef struct abstract_print_t abstract_print_t;
struct abstract_print_t {
    void (*display)(abstract_print_t *p);
    void (*open)(abstract_print_t *p);
    void (*close)(abstract_print_t *p);
    void (*print)(abstract_print_t *p);
    void (*del)(abstract_print_t *p);
};

void abstract_display(abstract_print_t *p);
