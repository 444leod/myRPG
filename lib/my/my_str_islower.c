/*
** EPITECH PROJECT, 2022
** my_str_islower
** File description:
** CPool day 6 - Task 14
*/
int my_strlen(char const *);

int my_str_islower(char const *str)
{
    int len = my_strlen(str);
    if (len == 0) return 1;
    for (int x = 0; str[x] != '\0'; ++x) {
        if (str[x] < 'a' || str[x] > 'z') {
            return 0;
        }
    }
    return 1;
}
