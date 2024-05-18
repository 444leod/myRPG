/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** ennemy_attack
*/

#include "../../include/my_rpg.h"
#include "../../include/my.h"

void ennemy_attack(struct window *my_rpg, attack_t attack)
{
    if (FIGHT(state) == NOT_FIGHT)
        return;
    sfText_setString(FIGHT(attack_text), supercat(3,
        sfText_getString(F_ENNEMY(name)), " has used ",attack->text));
    display_fight(my_rpg);
    my_wait(1, WINDOW);
    if (get_rand_between(0, 100) > attack->precision){
        FIGHT(state) = 3;
        sfText_setString(FIGHT(attack_text), "Enemy missed !");
        display_fight(my_rpg);
        my_wait(1, WINDOW);
        return;
    }
    sfSound_play(SOUND(sword));
    update_health_smooth(my_rpg, attack, &F_PLAYER(hp), F_ENNEMY(attack));
    if (F_PLAYER(hp) <= 0 || F_ENNEMY(hp) <= 0)
        FIGHT(state) = NOT_FIGHT;
}
