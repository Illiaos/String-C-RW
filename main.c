#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mstring
{
    uint8_t* data;
    uint8_t length;
}str_t;
str_t *create_string(uint8_t length);
str_t *string_dup(const char *text);
uint8_t string_length(const char *text);
void clear_string(str_t *string);
void print_string(str_t *string, FILE *file);
uint8_t get_string_length(str_t *string);
str_t *string_conc(str_t *left, str_t *right);
int main()
{
    str_t *string_1 = string_dup("Hello World_1");
    str_t *string_2 = string_dup("Hello World_2");
    //print_string(string_1, stdout);
    //print_string(string_2, stdout);
    str_t *new = string_conc(string_1, string_2);
    print_string(new, stdout);
    clear_string(string_1);
}
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
        length ++;
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
