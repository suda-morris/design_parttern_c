#pragma once
#include "abstract_print.h"

typedef struct {
    char c;
} char_print_config_t;

abstract_print_t *new_char_print(const char_print_config_t *config);
