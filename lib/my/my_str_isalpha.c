/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** CPool day 6 - Task 12
*/
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strcpy(char *, char const *);

int my_str_isalpha(char const *str)
{
    int len = my_strlen(str);
    char lowstr[len + 1];
    my_strcpy(lowstr, str);
    my_strlowcase(lowstr);
    if (len == 0) return 1;
    for (int x = 0; lowstr[x] != '\0'; ++x) {
        if (lowstr[x] < 'a' || lowstr[x] > 'z') {
            return 0;
        }
    }
    return 1;
}
