/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** loop
*/

#include "../../include/my_rpg.h"
#include "../../include/my.h"

static void pos_attacks(struct window *my_rpg)
{
    sfSprite_setPosition(F_PLAYER(slots)[0]->sprite->sprite, (V2F){203, 5});
    if (FIGHT(nbr) >= 2)
        sfSprite_setPosition(F_PLAYER(slots)[1]->sprite->sprite, (V2F){971, 5});
    if (FIGHT(nbr) >= 3)
        sfSprite_setPosition(F_PLAYER(slots)[2]->sprite->sprite,
            (V2F){203, 395});
    if (FIGHT(nbr) == 4)
        sfSprite_setPosition(F_PLAYER(slots)[3]->sprite->sprite,
            (V2F){971, 395});

}

static void init_ennemy(struct window *my_rpg)
{
    F_ENNEMY(hp) = (FIGHT(zone) == 0) ? 30 : (FIGHT(zone) == 1) ? 50 : 70;
    F_ENNEMY(max_hp) = (FIGHT(zone) == 0) ? 30 : (FIGHT(zone) == 1) ? 50 : 70;
    F_ENNEMY(attack) = (FIGHT(zone) == 0) ? 0.7 : (FIGHT(zone) == 1) ? 1 : 1.3;
    if (FIGHT(zone) == 0) {
        sfText_setString(F_ENNEMY(name), "noadcoca");
        sfText_setString(F_ENNEMY(lvl), "1");
    }
    if (FIGHT(zone) == 1) {
        sfText_setString(F_ENNEMY(name), "bernard");
        sfText_setString(F_ENNEMY(lvl), "3");
    }
    if (FIGHT(zone) == 2) {
        sfText_setString(F_ENNEMY(name), "farine moto");
        sfText_setString(F_ENNEMY(lvl), "5");
    }
    F_PLAYER(attack) = PLAYER->damage;
    F_PLAYER(max_hp) = PLAYER->max_health;
    F_PLAYER(hp) = PLAYER->health;
}

static void re_init_fight(struct window *my_rpg)
{
    FIGHT(state) = FIGHT;
    FIGHT(bag_state) = 0;
    FIGHT(nbr) = 0;
    for (int i = 0; i < 4 && F_PLAYER(slots)[i] != NULL; i++)
        FIGHT(nbr)++;
    init_ennemy(my_rpg);
    pos_attacks(my_rpg);
    float life_ratio = (float)(PLAYER->xp % 100) / 100;
    int l = (int)(601 * life_ratio);
    IRECT rect = (IRECT){0, 81, l, 19};
    sfSprite_setTextureRect(F_PLAYER(xp)->sprite, rect);
    sfText_setString(F_PLAYER(lvl), my_int_to_str(PLAYER->xp / 100 + 1));
}

void zoom_on_sprite(sfRenderWindow* window, sfSprite* sprite,
    struct window *my_rpg)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    V2F pos2 = pos;
    sfVector2f size = sfSprite_getScale(sprite);
    V2F size2 = size;
    for (int i = 0; i < 50; i++){
        sfSprite_setScale(sprite, (sfVector2f){size.x += 0.1, size.y += 0.1});
        sfSprite_setPosition(sprite, (sfVector2f)
        {pos.x -= (1920 + 24) / 10 / 2, pos.y -= (1080 + 24) / 10 / 2});
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        my_wait(0.01, window);
        sfRenderWindow_clear(window, sfBlack);
    }
    sfSprite_setScale(sprite, size2);
    sfSprite_setPosition(sprite, pos2);
    sfText_setString(FIGHT(bag_text),
        my_int_to_str(PLAYER->coconut));
}

void fight_screen(struct window *my_rpg)
{
    re_init_fight(my_rpg);
    zoom_on_sprite(WINDOW, RDSPRITE, my_rpg);
    while (FIGHT(state) != NOT_FIGHT && sfRenderWindow_isOpen(WINDOW)) {
        sfVector2f pos = get_pxmousepos(WINDOW);
        pos.y *= 1080 / (float)my_rpg->size.y;
        pos.x *= 1920 / (float)my_rpg->size.x;
        while (GET_EVENT(my_rpg->window, &EVENT))
            handle_fight_event(my_rpg, pos);
        display_fight(my_rpg);
    }
    STATE(fight) = 0;
}
