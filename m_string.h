#include <stdlib.h>
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
str_t *push_back(str_t *string, char letter);
str_t *pop_back(str_t *string);
void swap(str_t **string_1, str_t **string_2);
void memory_cpy(str_t **string_1, str_t *string_2, uint8_t length);

