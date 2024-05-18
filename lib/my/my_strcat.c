/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** CPool day 7 - Task 02
*/
int my_strlen(char const *);
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    while (dest[i] != '\0'){
        tmp[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        tmp[i] = src[j];
        i++;
        j++;
    }
    tmp[i] = '\0';
    return tmp;
}

char *supercat(int nbr, ...)
{
    va_list ap;
    char *str = malloc(sizeof(char));
    char *temp;

    str[0] = '\0';
    va_start(ap, nbr);
    for (int i = 0; i < nbr; i++){
        temp = my_strcat(str, va_arg(ap, char *));
        free(str);
        str = temp;
    }
    va_end(ap);
    return str;
}
