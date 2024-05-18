/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** ally_attack
*/

#include "../../include/my_rpg.h"
#include "../../include/my.h"

void ally_attack(struct window *my_rpg, attack_t attck)
{
    if (FIGHT(state) == NOT_FIGHT)
        return;
    sfText_setString(FIGHT(attack_text), supercat(2, "You used ", attck->text));
    display_fight(my_rpg);
    my_wait(1, WINDOW);
    if (get_rand_between(0, 100) > attck->precision + 10){
        FIGHT(state) = 3;
        sfText_setString(FIGHT(attack_text), "You missed !");
        display_fight(my_rpg);
        my_wait(1, WINDOW);
        return;
    }
    sfSound_play(SOUND(sword));
    update_health_smooth(my_rpg, attck, &F_ENNEMY(hp), F_PLAYER(attack));
    if (F_PLAYER(hp) <= 0 || F_ENNEMY(hp) <= 0)
        FIGHT(state) = NOT_FIGHT;
}
