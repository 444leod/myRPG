/*
** EPITECH PROJECT, 2023
** get_csv_data.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../../../include/my.h"
#include <stdlib.h>

int **get_int_map(char *path, int size)
{
    char *file = my_read_file(path, my_file_size(path));
    char **lines = my_str_to_word_array(file, "\n");
    char **line = NULL;
    int **map = NULL;
    if (file == NULL || lines == NULL) return NULL;
    map = malloc(sizeof(int **) * (size + 1));
    for (int i = 0; i < size; i++) {
        map[i] = malloc(sizeof(int *) * (size + 1));
        line = my_str_to_word_array(lines[i], ",");
        if (line == NULL) return NULL;
        for (int j = 0; j < size; j++)
            map[i][j] = my_getnbr(line[j]);
        map[i][size] = -255;
        my_free_array(line);
    }
    my_free_array(lines);
    map[size] = NULL;
    return map;
}
