#include <stdio.h>
#include "m_string.h"
int main()
{
    str_t *string_1 = string_dup("Hello, World!");
    str_t *string_2 = string_dup("Hello, World");
    uint8_t res = compare(string_1->data, string_2->data, string_1->length);
    printf("%d", res);
    //char *s = memory_char(string_1, 'e', string_1->length);
}
