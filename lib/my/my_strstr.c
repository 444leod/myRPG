/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** CPool day 6 - Task 05
*/
int my_strlen(char const *);

char *my_strstr(char *str, char const *to_find)
{
    int x = 0;
    int found = 0;
    int first_letter = -1;

    if (my_strlen(to_find) == 0) return str;
    while (str[x] != '\0') {
        if (str[x] == to_find[found]) {
            found++;
            first_letter = first_letter == -1 ? x : first_letter;
        } else {
            found = 0;
            first_letter = -1;
        }
        if (found == my_strlen(to_find)) {
            return str + first_letter;
        }
        x++;
    }
    return 0;
}
