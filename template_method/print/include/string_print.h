#pragma once
#include "abstract_print.h"

typedef struct {
    char *str;
} string_print_config_t;

abstract_print_t *new_string_print(const string_print_config_t *config);
