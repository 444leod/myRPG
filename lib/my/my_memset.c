/*
** EPITECH PROJECT, 2023
** my_memset.c
** File description:
** B-PSU-200-LIL-2-1-minishell1-nicolas.pechart
*/

void my_memset(char *str, int len)
{
    for (int i = 0; i < len; ++i) {
        str[i] = 0;
    }
}
