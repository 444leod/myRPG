/*
** EPITECH PROJECT, 2023
** grab_sword.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

void get_sword(struct window *my_rpg)
{
    struct tile *sword = am_i_near_a_sword(CURRENT_MAP->layers[1], my_rpg);
    if (sword == NULL || PLAYER->sword) return;
    PLAYER->sword = 1;
    QUEST(nbr) = new_txt(MYITOS(PLAYER->coconut),
        30, (sfVector2f){1640, 170}, my_rpg->font);
}
