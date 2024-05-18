/*
** EPITECH PROJECT, 2023
** am_i_near_a_npc.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

static int is_this_a_npc(int id)
{
    int npc[1] = {365};
    for (int i = 0; i < 1; i++)
        if (id == npc[i])
            return 1;
    return 0;
}

struct tile *am_i_near_a_npc(struct tile *layer, struct window *my_rpg)
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
            is_this_a_npc(temp->sprite->id))
            return temp;
        temp = temp->next;
    }
    return NULL;
}
