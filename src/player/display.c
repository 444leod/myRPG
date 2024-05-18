/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"

void display_player(struct window *my_rpg)
{
    float life_ratio = (float)(PLAYER->health) / PLAYER->max_health;
    sfRectangleShape_setSize(PLAYER->hp_bar, (V2F){313 * life_ratio, 24});
    sfSprite_setTextureRect(my_rpg->player->sprite, my_rpg->player->rect);
    sfSprite_setPosition(my_rpg->player->sprite, (sfVector2f){1920
    / 2 - square_size / 2, 1080 / 2 - square_size / 2});
    sfSprite_setScale(my_rpg->player->sprite, (sfVector2f){1.5, 1.5});
    sfRenderTexture_drawSprite(RDTEXTURE, PLAYER->sprite, NULL);
}
