/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** init all
*/

#include "../include/my_rpg.h"
#include <stdlib.h>

int init_all(struct window * my_rpg)
{
    CHECK_ERROR(init_window(my_rpg));
    CHECK_ERROR(init_states(my_rpg));
    CHECK_ERROR(init_menus(my_rpg));
    CHECK_ERROR(init_buttons(my_rpg));
    CHECK_ERROR(init_player(my_rpg));
    CHECK_ERROR(init_sounds(my_rpg));
    CHECK_ERROR(init_collision(my_rpg));
    CHECK_ERROR(init_fight(my_rpg));
    CHECK_MALLOC(my_rpg->font);
    CHECK_ERROR(init_texts(my_rpg));
    CHECK_ERROR(init_tooltip(my_rpg));
    CHECK_ERROR(init_quests(my_rpg));
    load_settings(my_rpg);
    sfMusic_play(SOUND(music));
    sfSprite_setScale(RDSPRITE, (sfVector2f){(float)my_rpg->size.x / 1920,
        (float)my_rpg->size.y / 1080});
    sfSprite_setScale(HSPRITE, (sfVector2f){(float)my_rpg->size.x / 1920,
        (float)my_rpg->size.y / 1080});
    return SUCCESS;
}
