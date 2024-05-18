/*
** EPITECH PROJECT, 2023
** update.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"

void update_orientation(struct window *my_rpg)
{
    switch (PLAYER->direction) {
        case 1:
            my_rpg->player->rect.top = 0;
            break;
        case 2:
            my_rpg->player->rect.top = 64;
            break;
        case 3:
            my_rpg->player->rect.top = 128;
            break;
        case 4:
            my_rpg->player->rect.top = 192;
            break;
    }
}

void update_speed(struct window *my_rpg)
{
    if (ISKEYPRESSED(sfKeyLControl) &&
        PLAYER->stamina - .5 >= 0 && !PLAYER->refill) {
        PLAYER->speed = RUN;
        sfRectangleShape_setSize(PLAYER->st_bar, PLAYER->st_size);
    } else {
        PLAYER->speed = WALK;
    }
    PLAYER->st_size.x = (344.0 / PLAYER->max_stamina) * PLAYER->stamina * 0.76;
    sfRectangleShape_setSize(PLAYER->st_bar, PLAYER->st_size);
}

void update_p_animation(struct window *my_rpg)
{
    if (PLAYER->direction == -1) {
        return;
    }
    if (PLAYER->animation_state == 7 ||
        PLAYER->rect.left >= 448 + 64) {
        PLAYER->rect.left = 64;
        PLAYER->animation_state = 0;
    } else {
        PLAYER->rect.left += 64;
        PLAYER->animation_state += 1;
    }
}

void update_player(struct window *my_rpg)
{
    move_player(my_rpg);
    update_orientation(my_rpg);
    update_speed(my_rpg);
}
