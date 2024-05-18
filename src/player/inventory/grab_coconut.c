/*
** EPITECH PROJECT, 2023
** grab_coconut.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../../include/my_rpg.h"
#include "../../../include/my.h"
#include <stdlib.h>

void get_coconut(struct window *my_rpg)
{
    int coconut_list[5] = {586, 587, 588, 622, 623};
    int coconut_value[5] = {1, 2, 1, 1, 1};
    struct tile *coconut = is_there_a_coconut_near_me(CURRENT_MAP->layers[1],
        my_rpg);
    if (coconut == NULL || !PLAYER->sword) return;
    for (int i = 0; i < 5; i++) {
        if (coconut->sprite->id == coconut_list[i]) {
            remove_tile(coconut, my_rpg->current_map->layers[1]);
            PLAYER->coconut += (coconut_value[i] + PLAYER->coconut <= 15) ?
                coconut_value[i] + PLAYER->coconut : 15;
            QUEST(nbr) = new_txt(MYITOS(PLAYER->coconut),
        30, (sfVector2f){1640, 170}, my_rpg->font);
        }
        if (rand() % (2 * coconut_value[i]) == 0 &&
            coconut->sprite->id == coconut_list[i]) {
            sfSound_play(SOUND(coconut));
            STATE(fight) = 1;
            break;
        }
    }
}
