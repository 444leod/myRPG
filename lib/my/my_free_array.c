/*
** EPITECH PROJECT, 2023
** my_free_array.c
** File description:
** B-PSU-200-LIL-2-1-minishell1-nicolas.pechart
*/
#include <stdlib.h>

void my_free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
