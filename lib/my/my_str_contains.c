/*
** EPITECH PROJECT, 2022
** my_str_contains.c
** File description:
** B-MUL-100-LIL-1-1-myradar-nicolas.pechart
*/

static int my_strlen(char const *str)
{
    int x = 0;
    for (; str[x] != '\0' ; x++);
    return x;
}

int my_str_contains(const char *str, const char *cmp)
{
    int len_str = my_strlen(str);
    int len_cmp = my_strlen(cmp);
    int result = 0;
    for (int i = 0; i < len_str; ++i) {
        result = 0;
        for (int j = 0; j < len_cmp && result == 0; ++j)
            result = str[i] == cmp[j] ? 1 : 0;
        if (result == 0)
            return 0;
    }
    return 1;
}
