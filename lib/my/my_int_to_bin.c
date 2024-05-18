/*
** EPITECH PROJECT, 2023
** my_int_to_bin.c
** File description:
** B-PSU-100-LIL-1-1-navy-nicolas.pechart
*/
#include <stdlib.h>

static int my_strlen(char *str)
{
    int x = 0;
    for (; str[x] != '\0' ; x++);
    return x;
}

static char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char temp;

    for (int i = 0; i < len - i; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

char *my_int_to_bin(int nb)
{
    char *bin = malloc(sizeof(char) * 9);
    int i = 0;
    for (int i = 0; i < 8; i++, nb /= 2) {
        bin[i] = nb % 2 + '0';
    }
    bin[i] = '\0';
    return my_revstr(bin);
}
