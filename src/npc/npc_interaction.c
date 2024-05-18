/*
** EPITECH PROJECT, 2023
** npc_interaction.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

void display_npc_interaction(struct window *my_rpg)
{
    struct tile *temp = am_i_near_a_npc(CURRENT_MAP->layers[1], my_rpg);
    char *line = NULL;
    if (temp == NULL) {
        hide_tooltip(my_rpg);
        my_rpg->npc_line = 0;
        return;
    }
    if (ISKEYPRESSED(sfKeyE) && TIME(my_rpg->npc_clock) > 0.25) {
        my_rpg->npc_line++;
        RESET_TIME(my_rpg->npc_clock);
    }
    line = get_npc_line(temp->sprite->id, my_rpg->npc_line);
    if (line == NULL) {
        my_rpg->npc_line = 0;
        line = get_npc_line(temp->sprite->id, my_rpg->npc_line);
    }
    display_tooltip(line, my_rpg);
}
