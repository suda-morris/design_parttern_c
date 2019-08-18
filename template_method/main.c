#include "string_print.h"
#include "char_print.h"

int main(void)
{
    string_print_config_t sconfig = { .str = "Hello World" };
    abstract_print_t *abs_print = new_string_print(&sconfig);
    abs_print->display(abs_print);
    abs_print->del(abs_print);
    char_print_config_t cconfig = { .c = 'H' };
    abs_print = new_char_print(&cconfig);
    abs_print->display(abs_print);
    abs_print->del(abs_print);
    return 0;
}
