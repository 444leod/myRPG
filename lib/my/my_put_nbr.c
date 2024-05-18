/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** CPool day 3 - Task07
*/
#include "my.h"

int my_put_nbr(int nbr)
{
    int x = 1, retain = 0;
    if (nbr == -2147483648) {
        retain = 1;
        nbr += 1;
    }
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    while (nbr / x >= 10)
        x = x * 10;
    while (x >= 1) {
        if (x < 10 && retain == 1) {
            my_putchar((nbr / x) % 10  + 1 + '0');
        } else {
            my_putchar((nbr / x) % 10 + '0');
        }
        x = x / 10;
    }
    return 0;
}
