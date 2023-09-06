#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

void string_print(char *str);

void string_scan(char *str, int size);

char string_compare_for_search(char *str1, char *str2);

char string_compare_sort(char *str1, char *str2);

void string_copy(char *str_original, char *str_copy, int element_number);

void string_copy_charTOint(char *str, int *num, int element_number);


#endif // STRING_H_INCLUDED
