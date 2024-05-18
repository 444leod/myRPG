/*
** EPITECH PROJECT, 2023
** map_display.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

static void display(tile *tiles, int player_x, int player_y,
        struct window *my_rpg)
{
    if (tiles->sprite->id == 438 && my_rpg->player->sword == 1)
        return;
    sfSprite_setPosition(tiles->sprite->sprite,(V2F){TILEPOS.x + 1920 / 2 -
    player_x,TILEPOS.y + 1080 / 2 - player_y});
    sfRenderTexture_drawSprite(RDTEXTURE, tiles->sprite->sprite, NULL);
}

void display_map(struct window *my_rpg, tile *tiles)
{
    int player_x = my_rpg->player->position.x;
    int player_y = my_rpg->player->position.y;
    int first_element_x = player_x - (1920 / 2) - 64;
    int first_element_y = player_y - (1080 / 2) - 64;
    int last_element_x = player_x + (1920 / 2);
    int last_element_y = player_y + (1080 / 2);

    if (tiles == NULL) return;
    for (; tiles->next != NULL; tiles = tiles->next) {
        if (TILEPOS.x > first_element_x && TILEPOS.x < last_element_x &&
            TILEPOS.y > first_element_y && TILEPOS.y < last_element_y) {
            display(tiles, player_x, player_y, my_rpg);
        }
    }
    sfSprite_setPosition(my_rpg->hitbox->sprite, (V2F){-PLAYER->position.x +
        1920 / 2, -PLAYER->position.y + 1080 / 2});
    sfRenderTexture_drawSprite(HTEXTURE, my_rpg->hitbox->sprite, NULL);
}
