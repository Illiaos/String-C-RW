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
    memcpy(string->data, text, string->length);
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
str_t *string_conc(str_t *left, str_t *right)
{
    str_t *string = create_string(left->length + right->length);
    memcpy(string->data, left->data, left->length);
    memcpy(string->data + left->length,right->data, right->length);
    
    return string;
}
str_t *push_back(str_t *string, char letter)
{
    char *l = &letter;
    str_t *accum_string = create_string(string->length+1);
    memcpy(accum_string->data, string->data, string->length);
    
    memcpy(accum_string->data + string->length, l, 1);
    return accum_string;
}

str_t *pop_back(str_t *string)
{
    str_t *accum_string = create_string(string->length-1);
    memcpy(accum_string->data, string->data, accum_string->length);
    return accum_string;
}
void swap(str_t **string_1, str_t **string_2)
{
    str_t *accum_string = create_string((*string_1)->length);
    memcpy(accum_string->data, (*string_1)->data, accum_string->length);
    free(*string_1);
    
    *string_1 = create_string((*string_2)->length);
    memcpy((*string_1)->data, (*string_2)->data, (*string_2)->length);
    
    free(*string_2);
    *string_2 = create_string(accum_string->length);
    memcpy((*string_2)->data, accum_string->data, accum_string->length);
    
}
void memory_cpy(str_t **string_1, str_t *string_2, uint8_t length)
{
    for(int i=0; i<length; i++)
    {
        
        
        (*string_1)->data = string_2->data;
        
        string_2->data++;
        (*string_1)->data++;
        
        printf("%s\n", (*string_1)->data);
        
        
        
    }
    
}
