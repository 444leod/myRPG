/*
** EPITECH PROJECT, 2023
** generate_sprite.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../../../include/my_rpg.h"

sfSprite *gen_sprite(sfTexture *texture, V2F pos)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, (sfIntRect){pos.x, pos.y, 48, 48});
    return sprite;
}
