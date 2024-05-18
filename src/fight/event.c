/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** event
*/

#include "../../include/my_rpg.h"

static void handle_attacks(struct window *my_rpg, V2F pos)
{
    if (MOUSE_ON(FIGHT(hitboxes)[0]->bounds, pos))
        attack(my_rpg, 0);
    if (FIGHT(nbr) >= 2 && MOUSE_ON(FIGHT(hitboxes)[1]->bounds, pos))
        attack(my_rpg, 1);
    if (FIGHT(nbr) >= 4 && MOUSE_ON(FIGHT(hitboxes)[2]->bounds, pos))
        attack(my_rpg, 2);
    if (FIGHT(nbr) == 4 && MOUSE_ON(FIGHT(hitboxes)[3]->bounds, pos))
        attack(my_rpg, 3);
}

static int check_bag_events(struct window *my_rpg, V2F pos)
{
    if (MOUSE_ON(BUTTON(back)->bounds, pos))
        FIGHT(bag_state) = 0;
    if (MOUSE_ON(FIGHT(use_rect)->bounds, pos))
        use_coconut(my_rpg);
    return 1;
}

static void handle_click(struct window *my_rpg, V2F pos)
{
    if (FIGHT(bag_state) && check_bag_events(my_rpg, pos))
        return;
    if (FIGHT(state) == ATTACKING)
        handle_attacks(my_rpg, pos);
    if (MOUSE_ON(FIGHT(bag_rect)->bounds, pos) && FIGHT(state) == FIGHT)
        FIGHT(bag_state) = 1;
    if (MOUSE_ON(FIGHT(fight)->bounds, pos) && FIGHT(state) == FIGHT)
        FIGHT(state) = ATTACKING;
    if (MOUSE_ON(FIGHT(cancel)->bounds, pos) && FIGHT(state) == ATTACKING)
        FIGHT(state) = FIGHT;
}

void handle_fight_event(struct window *my_rpg, sfVector2f pos)
{
    if (EVENT.type == sfEvtClosed)
        sfRenderWindow_close(WINDOW);
    if (FIGHT(bag_state) && ESC)
        FIGHT(bag_state) = 0;
    if (has_clicked(EVENT, sfMouseLeft))
        handle_click(my_rpg, pos);
}
