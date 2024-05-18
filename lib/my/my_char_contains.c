/*
** EPITECH PROJECT, 2022
** my_char_contains.c
** File description:
** B-MUL-100-LIL-1-1-myradar-nicolas.pechart
*/

static int my_strlen(char const *str)
{
    int x = 0;
    for (; str[x] != '\0' ; x++);
    return x;
}

int my_char_contains(const char chr, const char *cmp)
{
    int len_cmp = my_strlen(cmp);
    int result = 0;
    for (int j = 0; j < len_cmp && result == 0; ++j)
        result = chr == cmp[j] ? 1 : 0;
    return result;
}
