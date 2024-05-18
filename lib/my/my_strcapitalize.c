/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** CPool day 6 - Task 10
*/
char *my_strlowcase(char *);

char *my_strcapitalize(char *str)
{
    int x = 0;
    int capitalize = 1;
    my_strlowcase(str);

    while (str[x] != '\0') {
        if (capitalize) {
            capitalize = str[x] >= 97 && str[x] <= 122 ? 1 : 0;
            str[x] = capitalize ? str[x] - 32 : str[x];
            capitalize = 0;
        } else {
            capitalize = str[x] == 32 || str[x] == 43 || str[x] == 45 ? 1 : 0;
        }
        x++;
    }
    return str;
}
