/*
** EPITECH PROJECT, 2023
** my_put_str_array.c
** File description:
** B-PSU-200-LIL-2-1-minishell1-nicolas.pechart
*/

#include <unistd.h>

static void my_putchar(char c)
{
    write(1, &c, 1);
}

static int my_putstr(char const *str)
{
    int x = 0;
    while (str[x] != '\0') {
        my_putchar(str[x]);
        x++;
    }
    return 0;
}

int my_put_str_array(char **array)
{
    if (array == NULL)
        return 0;
    int i = 0;
    while (array[i] != NULL) {
        my_putstr(array[i]);
        my_putchar('\n');
        i++;
    }
    return i;
}
