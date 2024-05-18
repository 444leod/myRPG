/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** CPool day 4 - Task 02
*/
#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int x = 0;
    while (str[x] != '\0') {
        my_putchar(str[x]);
        x++;
    }
    return 0;
}
