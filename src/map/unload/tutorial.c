/*
** EPITECH PROJECT, 2023
** tutorial.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../../include/my_rpg.h"
#include "../../../include/my.h"
#include <stdlib.h>

void free_tile_list(struct tile *list)
{
    struct tile *temp = list;
    while (temp != NULL) {
        list = list->next;
        free(temp);
        temp = list;
    }
}

void unload_tutorial(struct window *my_rpg)
{
    struct sprite *next = NULL;
    struct sprite *tmp = NULL;
    if (my_rpg->tutorial == NULL) return;
    if (my_rpg->current_map == my_rpg->tutorial) my_rpg->current_map = NULL;
    for (int i = 0; i < 4; ++i)
        if (my_rpg->tutorial->layers[i] != NULL)
            free_tile_list(my_rpg->tutorial->layers[i]);
    for (tmp = my_rpg->tutorial->sprites; tmp != NULL; tmp = next) {
        next = tmp->next;
        sfSprite_destroy(tmp->sprite);
        free(tmp);
    }
    for (tmp = my_rpg->tutorial->animated_sprites; tmp != NULL; tmp = next) {
        next = tmp->next;
        sfSprite_destroy(tmp->sprite);
        free(tmp);
    }
    sfTexture_destroy(my_rpg->tutorial->texture);
    free(my_rpg->tutorial);
}
