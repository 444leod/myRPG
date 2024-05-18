/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** CPool day 4 - Task 06
*/

int my_str_array_len(char *array)
{
    int i;
    for (int i = 0; array[i] != 0; i++) ;
    return i;
}
