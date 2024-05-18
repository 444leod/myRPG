/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** use_inv
*/

#include "../../include/my_rpg.h"
#include "../../include/my.h"

void display_bag(struct window *my_rpg)
{
    sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(bag)->sprite, NULL);
    sfRenderTexture_drawText(RDTEXTURE, FIGHT(bag_text), NULL);
}

void use_coconut(struct window *my_rpg)
{
    if (PLAYER->coconut == 0){
        sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(no_more)->sprite, NULL);
        my_wait(1, WINDOW);
        return;
    }
    F_PLAYER(hp) += 5;
    if (F_PLAYER(hp) > F_PLAYER(max_hp))
        F_PLAYER(hp) = F_PLAYER(max_hp);
    PLAYER->coconut--;
    sfText_setString(FIGHT(bag_text),
        my_int_to_str(PLAYER->coconut));
}

void level_up(struct window *my_rpg)
{
    sfText_setPosition(FIGHT(attack_text), (V2F){sfText_getPosition(
        FIGHT(attack_text)).x, sfText_getPosition(
        FIGHT(attack_text)).y - 50});
    sfText_setString(FIGHT(attack_text),
        "You leveled up! Congrats\nYou gained 1 skill point");
    display_fight(my_rpg);
    FIGHT(state) = 6;
    sfText_setPosition(FIGHT(attack_text), (V2F){sfText_getPosition(
        FIGHT(attack_text)).x, sfText_getPosition(
        FIGHT(attack_text)).y + 30});
    my_wait(2, WINDOW);
    PLAYER->level++;
    PLAYER->skill_p++;
    sfText_setString(PLAYER->text_lvl, MYITOS(PLAYER->level));
}
