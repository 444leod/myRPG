/*
** EPITECH PROJECT, 2023
** my_char_isalpha.c
** File description:
** B-PSU-200-LIL-2-1-minishell1-nicolas.pechart
*/

int my_char_isalpha(char c)
{
    if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) {
        return 0;
    }
    return 1;
}
