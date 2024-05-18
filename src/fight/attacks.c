/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** attacks
*/

#include "../../include/my_rpg.h"
#include "../../include/my.h"

void draw_health_and_xp(struct window *my_rpg);
void display_window(struct window *my_rpg);

void update_health_smooth(struct window *my_rpg, attack_t attack, int *hp,
    float multi)
{
    int new_hp = (*hp) - (float)attack->damage * multi;
    new_hp = (new_hp < 0) ? 0 : new_hp;
    for (; (*hp) > new_hp;){
        update_health(my_rpg);
        display_fight(my_rpg);
        my_wait(0.05, WINDOW);
        (*hp)--;
    }
}

attack_t get_ennemy_attack(struct window *my_rpg)
{
    int id = get_rand_between(0, 6);
    if (id == 3 || id == 6)
        id = 4;
    return FIGHT(attack_stats)[id];
}

static void attack_first(struct window *my_rpg, attack_t ally, attack_t enemy)
{
    if (ally->speed > enemy->speed) {
        ally_attack(my_rpg, ally);
        ennemy_attack(my_rpg, enemy);
    } else {
        ennemy_attack(my_rpg, enemy);
        ally_attack(my_rpg, ally);
    }
}

void attack(struct window *my_rpg, int attack_id)
{
    attack_t attack_stats = F_PLAYER(slots)[attack_id]->stats;
    attack_t ennemy_attacks = get_ennemy_attack(my_rpg);
    FIGHT(state) = 5;
    display_fight(my_rpg);
    FIGHT(state) = 2;
    my_wait(1, WINDOW);
    if (ATTACK_ID(attack_id) == 3 || ATTACK_ID(attack_id) == 6 ||
        ATTACK_ID(attack_id) == 2){
        special_attack(my_rpg, attack_stats, ennemy_attacks);
        return;
    }
    attack_first(my_rpg, attack_stats, ennemy_attacks);
    FIGHT(state) = 1;
    change_state_fight(my_rpg);
}
