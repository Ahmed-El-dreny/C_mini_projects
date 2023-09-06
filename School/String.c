#include "string.h"

void string_print(char *str)
{
    int counter = 0;

    printf("\n String: ");
    for(counter = 0; str[counter]; counter++)
    {
        printf("%c", *(str + counter));
    }
    printf("\n\n");
}





void string_scan(char *str, int size)
{
    int counter = 0;
    fflush(stdin);
    while(str[counter - 1] != '\n' && counter < size)
    {
        scanf("%c", (str + counter) );
        counter++;
    }
    fflush(stdin);
    str[counter-1] = 0;
}




int string_len(char *str)
{
    int counter;
    for(counter = 0; str[counter]; counter++);
    return counter;
}




char string_compare_for_search(char *str1, char *str2)
{
    int len1 = string_len(str1), len2 = string_len(str2);

    if(len1 != len2)
    {
        return 0;
    }
    else
    {
        for(int counter = 0; counter < len1; counter++)
        {
            if(str1[counter] != str2[counter] && str1[counter] != str2[counter] - ('a'-'A') && str1[counter] != str2[counter] + ('a'-'A'))
            {
                return 0;
            }
        }
    }
    return 1;
}



char string_compare_sort(char *str1, char *str2)
{
    int counter, c1, c2;
    for(counter = 0; str1[counter] && str2[counter]; counter++)
    {
        c1 = str1[counter];
        c2 = str2[counter];
        if(c1 >= 'a' && c1 <= 'z')
        {
            c1 -= 32;
        }
        if(c2 >= 'a' && c2 <= 'z')
        {
            c2 -= 32;
        }
        if(c1 > c2)
        {
            return 1;
        }
        else if(c1 < c2)
        {
            return -1;
        }
    }
    if(!str1[counter] && str2[counter])
    {
        return -1;
    }
    else if(str1[counter] && !str2[counter])
    {
        return 1;
    }
    return 0;
}



void string_copy(char *str_original, char *str_copy, int element_number)
{
    for(int counter = 0; counter < element_number && str_original[counter]; counter++)
    {
        str_copy[counter] = str_original[counter];
    }
}




void string_copy_charTOint(char *str, int *num, int element_number)
{
    for(int counter = 0; counter < element_number && (str[counter] >= '0' && str[counter] <= '9'); counter++)
    {
        *num = *num * 10 + (str[counter] - '0');
    }
}
