/*
** EPITECH PROJECT, 2023
** sprite_struct.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../../../include/my_rpg.h"
#include <stdlib.h>

void add_sprite(map_manager *map, sfSprite *sprite, int id)
{
    struct sprite *temp = map->sprites;
    struct sprite *new = malloc(sizeof(struct sprite));
    new->id = id;
    new->sprite = sprite;
    new->next = NULL;
    if (map->sprites == NULL)
        map->sprites = new;
    else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}

void add_ani_sprite(map_manager *map, sfSprite *sprite, int id)
{
    struct sprite *temp = map->animated_sprites;
    struct sprite *new = malloc(sizeof(struct sprite));
    new->id = id;
    new->sprite = sprite;
    new->next = NULL;
    if (map->animated_sprites == NULL)
        map->animated_sprites = new;
    else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}
