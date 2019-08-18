#include "abstract_print.h"

#define PRINT_REPEAT_TIMES (4)

void abstract_display(abstract_print_t *p)
{
    p->open(p);
    for (long i = 0; i < PRINT_REPEAT_TIMES; i++) {
        p->print(p);
    }
    p->close(p);
}
