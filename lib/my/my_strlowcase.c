/*
** EPITECH PROJECT, 2022
** my_strlowcase
** File description:
** CPool day 6 - Task 09
*/

char *my_strlowcase(char *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] >= 65 && str[x] <= 90) {
            str[x] = str[x] + 32;
        }
        x++;
    }
    return str;
}
