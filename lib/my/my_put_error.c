/*
** EPITECH PROJECT, 2023
** my_put_error.c
** File description:
** B-PSU-200-LIL-2-1-minishell1-nicolas.pechart
*/
#include <unistd.h>

static void my_putchar(char c)
{
    write(2, &c, 1);
}

int my_put_error(char *str)
{
    int x = 0;
    while (str[x] != '\0') {
        my_putchar(str[x]);
        x++;
    }
    return 1;
}
