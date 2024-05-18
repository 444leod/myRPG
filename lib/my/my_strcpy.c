/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** CPool day 6 - Task 01
*/
#include "../../include/my.h"

char *my_strcpy(char *dest, char *src)
{
    int x = 0;
    int len = my_strlen(dest);
    while (src[x] != '\0' || x < len) {
        dest[x] = src[x];
        x++;
    }
    dest[x] = '\0';
    return dest;
}
