/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** CPool day 6 - Task 03
*/

int my_strlen(char const * str);

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char temp;

    for (int i = 0; i < len - i; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}
