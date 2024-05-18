/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** CPool day 6 - Task 02
*/
int my_strlen(char const *);

char *my_strncpy(char *dest, char const *src, int n)
{
    int x = 0;

    while (x < n) {
        dest[x] = src[x];
        x++;
    }
    return dest;
}
