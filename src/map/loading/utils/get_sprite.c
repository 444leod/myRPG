/*
** EPITECH PROJECT, 2023
** get_sprite_by_id.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../../../include/my_rpg.h"
#include <stdlib.h>

sprite *get_sprite(map_manager *map, int id)
{
    sprite *temp_sprites = map->sprites;
    sprite *temp_animated_sprites = map->animated_sprites;

    while (temp_sprites != NULL) {
        if (temp_sprites->id == id)
            return temp_sprites;
        temp_sprites = temp_sprites->next;
    }
    while (temp_animated_sprites != NULL) {
        if (temp_animated_sprites->id == id)
            return temp_animated_sprites;
        temp_animated_sprites = temp_animated_sprites->next;
    }
    return NULL;
}
