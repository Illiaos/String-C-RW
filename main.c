#include <stdio.h>
#include "m_string.h"
int main()
{
    str_t *string_1 = string_dup("0123456789");
    str_t *string_2 = string_dup("ceQasieoLPqa4xz10Iyq");
    //int res = string_spn(string_2, string_1);
    //printf("%d", res);
    string_1 = string_cat(string_1->data, string_2->data);
    print_string(string_1, stdout);
}
