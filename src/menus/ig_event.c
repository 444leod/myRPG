/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** event_tuto
*/

#include "../../include/my_rpg.h"

void handle_controls(struct window *my_rpg, sfVector2f pos)
{
    if (MOUSE_ON(BUTTON(back)->bounds, pos))
        STATE(controls) = 0;
}

void handle_skills(struct window *my_rpg, sfVector2f pos)
{
    if (MOUSE_ON(BUTTON(back)->bounds, pos))
        STATE(skills) = 0;
    if (MOUSE_ON(BUTTON(skill_hp)->bounds, pos) && PLAYER->skill_p > 0) {
        my_rpg->player->max_health += 10;
        my_rpg->player->health += 10;
        PLAYER->skill_p--;
        PLAYER->health_p++;
    }
    if (MOUSE_ON(BUTTON(skill_dmg)->bounds, pos) && PLAYER->skill_p > 0) {
        my_rpg->player->damage += 0.2;
        PLAYER->skill_p--;
        PLAYER->damage_p++;
    }
}

void handle_inv(struct window *my_rpg, sfVector2f pos)
{
    if (MOUSE_ON(BUTTON(back)->bounds, pos))
        STATE(inventory) = 0;
    if (MOUSE_ON(FIGHT(use_rect)->bounds, pos))
        use_coconut(my_rpg);
}

void handle_pause_menu(struct window *my_rpg, sfVector2f pos)
{
    if (MOUSE_ON(BUTTON(resume)->bounds, pos))
        STATE(pause) = 0;
    if (MOUSE_ON(BUTTON(p_option)->bounds, pos))
        STATE(options) = 1;
    if (MOUSE_ON(BUTTON(save)->bounds, pos))
        save_player_data(my_rpg);
    if (MOUSE_ON(BUTTON(p_exit)->bounds, pos)){
        STATE(main_menu) = 1;
        STATE(pause) = 0;
    }
    if (MOUSE_ON(BUTTON(inventory)->bounds, pos))
        STATE(inventory) = 1;
    if (MOUSE_ON(BUTTON(skill_menu)->bounds, pos))
        STATE(skills) = 1;
    if (STATE(inventory))
        handle_inv(my_rpg, pos);
}
