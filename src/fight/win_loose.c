/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** win_loose
*/

#include "../../include/my_rpg.h"

static void update_xp(struct window *my_rpg)
{
    float xp_ratio = (float)(PLAYER->xp % 100) / 100;
    int l = (int)(609 * xp_ratio);
    IRECT rect = (IRECT){0, 81, l, 19};
    sfSprite_setTextureRect(F_PLAYER(xp)->sprite, rect);
}

static void loose(struct window *my_rpg)
{
    sfText_setString(FIGHT(attack_text), "You lost !");
    display_fight(my_rpg);
    my_wait(1, WINDOW);
    FIGHT(state) = NOT_FIGHT;
    reset_player_data(my_rpg);
    STATE(main_menu) = 1;
    my_rpg->tutorial = load_tutorial();
    CURRENT_MAP = my_rpg->tutorial;
}

static void check_if_levelup(struct window *my_rpg)
{
    int xp = get_rand_between(30, 70);
    for (; xp > 0 ; PLAYER->xp++, xp--){
        update_xp(my_rpg);
        display_fight(my_rpg);
        my_wait(0.001, WINDOW);
        if (PLAYER->xp % 100 == 1)
            level_up(my_rpg);
    }
}

static void win(struct window *my_rpg)
{
    FIGHT(state) = 2;
    sfText_setString(FIGHT(attack_text), "You won !");
    display_fight(my_rpg);
    my_wait(1, WINDOW);
    check_if_levelup(my_rpg);
    display_choose_attack(my_rpg);
    FIGHT(state) = NOT_FIGHT;
    PLAYER->health = F_PLAYER(hp);
    my_wait(1, WINDOW);
}

void change_state_fight(struct window *my_rpg)
{
    FIGHT(state) = 2;
    if (F_PLAYER(hp) <= 0){
        loose(my_rpg);
        return;
    }
    if (F_ENNEMY(hp) <= 0){
        win(my_rpg);
        return;
    }
    FIGHT(state) = 1;
}
