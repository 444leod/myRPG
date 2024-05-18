/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my.h"
#include <stdio.h>

void save_data(char *path, char *data, int size)
{
    FILE *file = fopen(path, "a");
    if (file == NULL)
        return;
    fwrite(data, size, 1, file);
    fwrite("\n", 1, 1, file);
    fclose(file);
}

int save_exists(void)
{
    int size = my_file_size("game_data/game.rpg");
    char *file = my_read_file("game_data/game.rpg", size);
    char **s_data = NULL;
    int len = -1;
    if (file == NULL)
        return 0;

    s_data = my_str_to_word_array(file, "\n");
    if (s_data == NULL)
        return 0;
    for (len = 0; s_data[len] != NULL ; len++);
    if (len != 13)
        return 0;
    return 1;
}
