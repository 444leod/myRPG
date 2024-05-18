/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** CPool day 6 - Task 08
*/

char *my_strupcase(char *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] >= 97 && str[x] <= 122) {
            str[x] = str[x] - 32;
        }
        x++;
    }
    return str;
}
