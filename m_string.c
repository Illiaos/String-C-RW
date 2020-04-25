#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "m_string.h"

str_t *create_string(uint8_t length)
{
    str_t *string = malloc(sizeof(struct mstring));
    string->data = malloc(sizeof(length));
    string->length = length;
    return string;
}

str_t *string_dup(const char *text)
{
    uint8_t text_length = string_length(text);
    str_t *string = create_string(text_length);
    //string->data = text;
    memory_cpy(string->data, text, string->length);
    //memory_cpy_char(&string, text, string->length);
    return string;
}
uint8_t get_string_length(str_t *string)
{
    return string->length;
}
void print_string(str_t *string, FILE *file)
{
    fwrite(string->data, sizeof(uint8_t), string->length, file);
}

uint8_t string_length(const char *text)
{
    uint8_t length = 0;
    while (*text != '\0')
    {
        length++;
        text++;
    }
    return length;
}


void clear_string(str_t *string)
{
    free(string->data);
    free(string);
}
//
str_t *string_conc(str_t *left, str_t *right)
{
    str_t *string = create_string(left->length + right->length);
    memory_cpy(string->data, left->data, left->length);
    memory_cpy(string->data + left->length, right->data, right->length);
    
    return string;
}
//o
str_t *push_back(str_t *string, char letter)
{
    char *l = &letter;
    str_t *accum_string = create_string(string->length+1);
    memory_cpy(accum_string->data, string->data, string->length);
    
    memory_cpy(accum_string->data + string->length, l, 1);
    return accum_string;
}

str_t *pop_back(str_t *string)
{
    str_t *accum_string = create_string(string->length-1);
    memory_cpy(accum_string->data, string->data, accum_string->length);
    return accum_string;
}

void swap(str_t **string_1, str_t **string_2)
{
    str_t *accum_string = create_string((*string_1)->length);
    memory_cpy(accum_string->data, (*string_1)->data, accum_string->length);
    free(*string_1);
    
    *string_1 = create_string((*string_2)->length);
    memory_cpy((*string_1)->data, (*string_2)->data, (*string_2)->length);
    
    free(*string_2);
    *string_2 = create_string(accum_string->length);
    memory_cpy((*string_2)->data, accum_string->data, accum_string->length);
    
}

str_t *get_line()
{
    str_t *str_accum;
    uint8_t i_couter = 0;
    uint8_t *string = malloc(sizeof(uint8_t *));
    int accum;
    while((accum = getchar()) != '\n')
    {
        string[i_couter] = accum;
        i_couter++;
    }
    str_accum = create_string(i_couter);
    str_accum->data = string;
    free(string);
    return str_accum;
}

void *memory_cpy(void *des, const void *src, size_t size)
{
    for(int i=0; i<size; i++)
    {
        *(uint8_t*)des = *(uint8_t*)src;
        src++;
        des++;
    }
    return 0;
}
uint8_t compare(const void *string_1, const void *string_2, size_t size)
{
    int pass = 0;
    for(size_t i=0; i<size; i++)
    {
        if(*(uint8_t*)string_1 != *(uint8_t*)string_2)
        {
            return 0;
        }
        string_1++;
        string_2++;
    }
    return 1;
}
