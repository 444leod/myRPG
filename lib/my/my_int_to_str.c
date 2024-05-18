/*
** EPITECH PROJECT, 2023
** my_int_to_str.c
** File description:
** B-MUL-100-LIL-1-1-myradar-nicolas.pechart
*/
#include <stdlib.h>

static int my_get_nbr_len(int nbr)
{
    int x = 1;
    int i = 1;
    while (nbr / x >= 10) {
        i++;
        x = x * 10;
    }
    return i;
}

char *my_int_to_str(int nbr)
{
    int x = 1;
    int i = 0;
    char *str = malloc(sizeof(char) * (my_get_nbr_len(nbr) + 1));
    if (nbr < 0) {
        str[i] = '-';
        i++;
        nbr = -nbr;
    }
    while (nbr / x >= 10)
        x = x * 10;
    while (x >= 1) {
        str[i] = (nbr / x) % 10 + '0';
        i++;
        x = x / 10;
    }
    str[i] = '\0';
    return str;
}
