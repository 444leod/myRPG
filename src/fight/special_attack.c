/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** special_attack
*/

#include "../../include/my_rpg.h"

static void dodge(struct window *my_rpg, attack_t ennemy)
{
    if (get_rand_between(0, 100) > 70){
        FIGHT(state) = 3;
        sfText_setString(FIGHT(attack_text), "You missed the dodge !");
        display_fight(my_rpg);
        my_wait(1, WINDOW);
        ennemy_attack(my_rpg, ennemy);
        return;
    }
    sfText_setString(FIGHT(attack_text), "You dodged !");
    display_fight(my_rpg);
    my_wait(1, WINDOW);
    return;
}

static void augment_attack(struct window *my_rpg, attack_t ennemy)
{
    if (90 < ennemy->speed){
        ennemy_attack(my_rpg, ennemy);
        display_fight(my_rpg);
        my_wait(1, WINDOW);
        if (get_rand_between(0, 100) > 90){
            FIGHT(state) = 3;
            sfText_setString(FIGHT(attack_text), "You missed !");
            display_fight(my_rpg);
            my_wait(1, WINDOW);
            ennemy_attack(my_rpg, ennemy);
            return;
        }
        sfText_setString(FIGHT(attack_text), "You used Sweet Eyes !");
        F_PLAYER(attack) *= 1.10;
        display_fight(my_rpg);
    }
    return;
}

static void run_away(struct window *my_rpg, attack_t ennemy)
{
    sfSound_play(SOUND(whistle));
    if (get_rand_between(0, 100) > 30){
        FIGHT(state) = 3;
        sfText_setString(FIGHT(attack_text), "You missed !");
        display_fight(my_rpg);
        my_wait(1, WINDOW);
        ennemy_attack(my_rpg, ennemy);
        FIGHT(state) = 1;
        return;
    }
    FIGHT(state) = 3;
    sfText_setString(FIGHT(attack_text), "Enemy ran away !");
    display_fight(my_rpg);
    my_wait(1, WINDOW);
    FIGHT(state) = NOT_FIGHT;
    STATE(fight) = 0;
    return;
}

void special_attack(struct window *my_rpg, attack_t attack, attack_t ennemy)
{
    switch (attack->damage) {
        case -84:
            dodge(my_rpg, ennemy);
            break;
        case -10:
            augment_attack(my_rpg, ennemy);
            break;
        case -1:
            run_away(my_rpg, ennemy);
            break;
    }
}
