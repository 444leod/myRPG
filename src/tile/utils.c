/*
** EPITECH PROJECT, 2023
** utils.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

sfVector2u get_current_tile(struct window *my_rpg)
{
    sfVector2u current_tile = {0, 0};
    current_tile.y = my_rpg->player->position.y / square_size;
    current_tile.x = my_rpg->player->position.x / square_size;
    return current_tile;
}

tile *get_tile(struct window *my_rpg, sfVector2u tile, struct tile *layer)
{
    struct tile *temp = layer;
    while (temp != NULL) {
        if (temp->position.x == tile.x * my_rpg->current_map->tile_size &&
            temp->position.y == tile.y * my_rpg->current_map->tile_size)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

sprite *get_sprite_by_id(sprite *sprites, int id)
{
    sprite *temp = sprites;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void remove_tile(struct tile *tile, struct tile *layer)
{
    struct tile *temp = layer;
    while (temp != NULL) {
        if (temp->next == tile) {
            temp->next = tile->next;
            free(tile);
            return;
        }
        temp = temp->next;
    }
}
