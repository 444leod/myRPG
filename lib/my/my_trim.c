/*
** EPITECH PROJECT, 2023
** my_trim.c
** File description:
** B-PSU-200-LIL-2-1-minishell1-nicolas.pechart
*/

static int my_strlen(char const *str)
{
    int x = 0;
    for (; str[x] != '\0' ; x++);
    return x;
}

static int my_char_contains(const char chr, const char *cmp)
{
    int len_cmp = my_strlen(cmp);
    int result = 0;
    for (int j = 0; j < len_cmp && result == 0; ++j)
        result = chr == cmp[j] ? 1 : 0;
    return result;
}

char *my_trim(char *str, char *separator)
{
    int i = 0;
    int letter = 0;

    while (str[letter] != '\0') {
        if (my_char_contains(str[letter], separator))
            letter++;
        else
            break;
    }
    for (; str[letter] != '\0'; i++, letter++)
        str[i] = str[letter];
    str[i] = '\0';
    return str;
}
