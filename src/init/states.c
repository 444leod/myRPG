/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** states
*/

#include "../../include/my_rpg.h"
#include <stdlib.h>

int init_states(struct window *my_rpg)
{
    my_rpg->states = malloc(sizeof(struct states));
    CHECK_MALLOC(my_rpg->states);
    STATE(pause) = false;
    STATE(inventory) = false;
    STATE(quest) = false;
    STATE(load) = false;
    STATE(options) = false;
    STATE(credits) = false;
    STATE(save) = false;
    STATE(main_menu) = true;
    STATE(controls) = false;
    STATE(skills) = false;
    STATE(s_size) = 0;
    STATE(s_type) = 1;
    STATE(sound) = 5;
    STATE(f_sound) = (float)567 / 2;
    STATE(music) = 5;
    STATE(f_music) = (float)567 / 2;
    STATE(fight) = false;
    return SUCCESS;
}
