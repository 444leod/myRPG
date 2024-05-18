/*
** EPITECH PROJECT, 2023
** clean.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

void clean_player(struct window *my_rpg)
{
    sfSprite_destroy(PLAYER->sprite);
    sfTexture_destroy(PLAYER->texture);
    sfSprite_destroy(PLAYER->info);
    sfTexture_destroy(PLAYER->info_texture);
    sfRectangleShape_destroy(PLAYER->hp_bar);
    sfRectangleShape_destroy(PLAYER->st_bar);
    sfRectangleShape_destroy(PLAYER->hp_bg);
    sfRectangleShape_destroy(PLAYER->st_bg);
    free(PLAYER);
}
