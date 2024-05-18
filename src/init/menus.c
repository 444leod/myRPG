/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** menus
*/

#include "../../include/my_rpg.h"
#include <stdlib.h>

static int init_menus_sprites(struct window *my_rpg)
{
    MENU(main) = create_sprite("menu/main.png", (V2F){0, 0});
    MENU(pause) = create_sprite("menu/ingame.png", (V2F){623, 57});
    MENU(option) = create_sprite("menu/option.png", (V2F){431, 85});
    MENU(load) = create_sprite("menu/load.png", (V2F){481, 85});
    MENU(controls) = create_sprite("menu/controls.png", (V2F){0, 0});
    MENU(credits) = create_sprite("menu/credits.png", (V2F){0, 0});
    MENU(skills) = create_sprite("menu/skills.png", (V2F){0, 0});
    MENU(skills2) = create_sprite("menu/skills2.png", (V2F){0, 0});
    CHECK_MALLOC(MENU(pause));
    CHECK_MALLOC(MENU(option));
    CHECK_MALLOC(MENU(load));
    CHECK_MALLOC(MENU(controls));
    CHECK_MALLOC(MENU(credits));
    CHECK_MALLOC(MENU(skills));
    CHECK_MALLOC(MENU(skills2));
    return SUCCESS;
}

int init_menus(struct window *my_rpg)
{
    my_rpg->menus = malloc(sizeof(struct menus));
    CHECK_ERROR(init_menus_sprites(my_rpg));
    return SUCCESS;
}
