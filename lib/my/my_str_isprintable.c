/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** CPool day 6 - Task 16
*/
int my_strlen(char const *);

int my_str_isprintable(char const *str)
{
    int len = my_strlen(str);
    if (len == 0) return 1;
    for (int x = 0; str[x] != '\0'; ++x) {
        if (str[x] < ' ' || str[x] > '~') {
            return 0;
        }
    }
    return 1;
}
