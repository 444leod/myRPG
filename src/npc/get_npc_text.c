/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

char *get_npc_line(int npc_id, int line_id)
{
    char *path = supercat(2, "assets/npc/", MYITOS(npc_id));
    char *file = my_read_file(path, my_file_size(path));
    char **lines = my_str_to_word_array(file, "\n");
    if (lines == NULL) return NULL;
    for (int i = 0; lines[i] != NULL; i++) {
        if (i == line_id)
            return lines[i];
    }
    return NULL;
}
