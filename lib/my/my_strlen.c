/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** CPool day 04 - Task 03
*/

int my_strlen(char *str)
{
    int x = 0;
    for (; str[x] != '\0' ; x++);
    return x;
}
