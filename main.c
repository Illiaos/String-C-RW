#include <stdio.h>
#include "m_string.h"
int main()
{
    str_t *string = string_dup("Hello, World");
    print_string(string, stdout);
}
