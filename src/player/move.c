/*
** EPITECH PROJECT, 2023
** move.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/lib_csfml.h"
#include "../../include/my.h"

static void update_stamina(struct player *player, int refill)
{
    if (player->speed == WALK || (player->speed == RUN && !refill)) {
        if (player->stamina < 0.5)
            player->refill = 1;
        if (player->stamina < player->max_stamina)
            player->stamina += 0.1;
        if (player->stamina > 25 && player->refill)
            player->refill = 0;
    } else if (player->speed == RUN && refill) {
        player->stamina = player->stamina > 0.5 ? player->stamina - 0.5 : 0;
    }
}

static int update_position(int x, int y, int direction, struct window *my_rpg)
{
    PLAYER->direction = direction;
    PLAYER->position.x += x;
    PLAYER->position.y += y;
    return 1;
}

void move_player(struct window *my_rpg)
{
    int pc = 0;
    if (ISKEYPRESSED(sfKeyUp) && check_coll(my_rpg, 'u')) {
        pc = update_position(0, -PLAYER->speed, 1, my_rpg);
    }
    if (!pc && ISKEYPRESSED(sfKeyLeft) && check_coll(my_rpg, 'l')) {
        pc = update_position(-PLAYER->speed, 0, 2, my_rpg);
    }
    if (!pc && ISKEYPRESSED(sfKeyDown) && check_coll(my_rpg, 'd')) {
        pc = update_position(0, PLAYER->speed, 3, my_rpg);
    }
    if (!pc && ISKEYPRESSED(sfKeyRight) && check_coll(my_rpg, 'r')) {
        pc = update_position(PLAYER->speed, 0, 4, my_rpg);
    }
    update_stamina(PLAYER, pc);
    if (!pc) {
        PLAYER->direction = -1;
        PLAYER->rect.left = 0;
        PLAYER->animation_state = 0;
    }
}
