/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** B-PSU-200-LIL-2-1-minishell1-nicolas.pechart
*/

#include <stdlib.h>

static int my_char_contains(const char chr, const char *cmp)
{
    int len_cmp = 0;
    for (; cmp[len_cmp] != '\0' ; len_cmp++);
    int result = 0;
    for (int j = 0; j < len_cmp && result == 0; ++j)
        result = chr == cmp[j] ? 1 : 0;
    return result;
}

int count_words(char *str, char *separator)
{
    int words = 0;
    for (int x = 0; str[x] != '\0'; x++) {
        if (!my_char_contains(str[x], separator) &&
            (my_char_contains(str[x + 1], separator) || str[x + 1] == '\0'))
            words++;
    }
    return words;
}

int word_len(char *str, char *separator, int x)
{
    int len = 0;
    for (; str[x] != '\0'; x++) {
        if (my_char_contains(str[x], separator))
            break;
        len++;
    }
    return len;
}

int next_word(char *str, char *separator, int x)
{
    int len = 0;
    for (; str[x] != '\0'; x++) {
        if (!my_char_contains(str[x], separator))
            break;
        len++;
    }
    return len;
}

char **my_str_to_word_array(char *str, char *separator)
{
    int fill = 0;
    int word_length = 0;
    int words = 0;
    if (str != NULL)
        words = count_words(str, separator);
    if (words == 0 || str == NULL)
        return NULL;
    char **array = malloc(sizeof(char *) * (words + 2));
    array[words] = NULL;
    for (int i = 0; i < words; ++i) {
        word_length = word_len(str, separator, fill);
        array[i] = malloc(sizeof(char) * (word_length + 1));
        for (int j = 0; j < word_length; ++j, ++fill)
            array[i][j] = str[fill];
        array[i][word_length] = '\0';
        fill += next_word(str, separator, fill);
    }
    return array;
}
