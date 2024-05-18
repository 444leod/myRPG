/*
** EPITECH PROJECT, 2022
** B-CPE-100-LIL-1-1-cpoolday10-nicolas.pechart
** File description:
** my_sort_word_array
*/
#include <stdlib.h>
#include "../../include/my.h"

static int swa_strcmp(char *cmp1, char *cmp2)
{
    int x = 0;
    int result = 0;
    char *s1 = malloc(sizeof(char) * my_strlen(cmp1));
    my_strcpy(s1, cmp1);
    my_strlowcase(s1);
    char *s2 = malloc(sizeof(char) * my_strlen(cmp2));
    my_strcpy(s2, cmp2);
    my_strlowcase(s2);
    while (s1[x] != '\0' || s2[x] != '\0') {
        if (s1[x] > s2[x] || s2[x] > s1[x]) {
            result = s1[x] - s2[x];
            break;
        }
        x++;
    }
    free(s1);
    free(s2);
    return result;
}

static int compare(char **tab, int i, int edit)
{
    char *temp;
    char *swap;

    temp = tab[i];
    swap = tab[i + 1];
    if (swa_strcmp(temp, swap) >= 0) {
        tab[i + 1] = temp;
        tab[i] = swap;
        return 1;
    }
    return edit;
}

int my_sort_word_array(char **tab)
{
    int sorted = 0;
    int edit = 0;

    while (sorted == 0) {
        for (int i = 0; tab[i + 1] != (void *) 0; i++) {
            edit = compare(tab, i, edit);
        }
        if (edit == 0) {
            sorted = 1;
        } else {
            edit = 0;
        }
    }
    return 0;
}
