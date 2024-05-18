/*
** EPITECH PROJECT, 2023
** update_anim.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"

void update_animation(map_manager *map)
{
    sprite *sprite = map->animated_sprites;
    sfIntRect rect = {0, 0, map->tile_size, map->tile_size};

    for (; sprite != NULL; sprite = sprite->next) {
        rect = sfSprite_getTextureRect(sprite->sprite);
        if (map->animation_dir == 1)
            rect.left += map->tile_size * map->animation_spacing;
        else
            rect.left -= map->tile_size * map->animation_spacing;
        sfSprite_setTextureRect(sprite->sprite, rect);
    }
    map->animation_state++;
    if (map->animation_state == map->animation_count - 1) {
        map->animation_state = 0;
        map->animation_dir = (map->animation_dir == 1) ? 0 : 1;
    }
}
