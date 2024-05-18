/*
** EPITECH PROJECT, 2023
** tiles_struct.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../../../include/my_rpg.h"
#include <stdlib.h>

tile *add_tile(tile *tiles, sprite *sprite, V2F pos, int walkable)
{
    tile *temp = tiles;
    tile *new = malloc(sizeof(struct tile));
    new->sprite = sprite;
    new->position = pos;
    new->walkable = walkable;
    new->next = NULL;
    if (tiles == NULL)
        tiles = new;
    else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
    return tiles;
}
