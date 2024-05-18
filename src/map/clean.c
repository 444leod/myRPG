/*
** EPITECH PROJECT, 2023
** clean.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

void clean_map(struct map_manager *map)
{
    tile *t_tmp = NULL;
    tile *t_next = NULL;
    sprite *s_tmp = NULL;
    sprite *s_next = NULL;
    sfTexture_destroy(map->texture);
    for (int i = 0; i < 3; i++) {
        for (t_tmp = map->layers[i]; t_tmp != NULL; t_tmp = t_next) {
            t_next = t_tmp->next;
            free(t_tmp);
        }
    }
    for (s_tmp = map->sprites; s_tmp != NULL; s_tmp = s_next) {
        s_next = s_tmp->next;
        free(s_tmp);
    }
    for (s_tmp = map->animated_sprites; s_tmp != NULL; s_tmp = s_next) {
        s_next = s_tmp->next;
        free(s_tmp);
    }
    free(map);
}
