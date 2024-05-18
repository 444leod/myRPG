/*
** EPITECH PROJECT, 2023
** am_i_near_a_sword.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>


void display_sword_help(struct window *my_rpg)
{
    struct tile *temp = am_i_near_a_sword(CURRENT_MAP->layers[1], my_rpg);
    if (temp == NULL || PLAYER->sword)
        return;
    sfText_setString(my_rpg->text, "Press 'E' to\nget the sword");
    sfText_setCharacterSize(my_rpg->text, 20);
    sfText_setPosition(my_rpg->text, (V2F){temp->position.x +
    1920 / 2 - PLAYER->position.x + CURRENT_MAP->tile_size,
    temp->position.y + 1080 / 2 - PLAYER->position.y});
    sfText_setColor(my_rpg->text, sfBlack);
    sfRenderTexture_drawText(RDTEXTURE, my_rpg->text, NULL);
}

static int is_this_a_sword(int id)
{
    return id == 438;
}

struct tile *am_i_near_a_sword(struct tile *layer, struct window *my_rpg)
{
    struct tile *temp = layer;
    sfVector2u pos = get_current_tile(my_rpg);
    int x_min = (pos.x + 1 - 1) * CURRENT_MAP->tile_size;
    int x_max = (pos.x + 1 + 1) * CURRENT_MAP->tile_size;
    int y_min = (pos.y + 1 - 1) * CURRENT_MAP->tile_size;
    int y_max = (pos.y + 1 + 1) * CURRENT_MAP->tile_size;
    while (temp != NULL) {
        if (temp->position.x >= x_min && temp->position.x <= x_max &&
            temp->position.y >= y_min && temp->position.y <= y_max &&
            is_this_a_sword(temp->sprite->id))
            return temp;
        temp = temp->next;
    }
    return NULL;
}
