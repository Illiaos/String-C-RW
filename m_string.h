#include <stdlib.h>
typedef struct mstring
{
    uint8_t *data;
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
str_t *get_line();
void *memory_cpy(void *des, const void *src, size_t size);
uint8_t compare(const void *string_1, const void *string_2, size_t size);
void *memory_move(void *string_1, const void *string_2, size_t size);
void *memory_set(void *string_1, uint8_t sign, size_t size);
void *string_token(void *string_1, const uint8_t c);
void *memory_char(void *string, const uint8_t letter, size_t size);
int memory_cmp(const void *string_1, const void *string_2, size_t size);
int string_cmp(const void *string_1, const void *string_2);
void *string_chr(const void *string, uint8_t letter);


