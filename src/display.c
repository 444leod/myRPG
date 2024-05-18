/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** display
*/

#include "../include/my_rpg.h"
#include <stdio.h>

static void display_player_health(struct window *my_rpg)
{
    sfRenderTexture_drawRectangleShape(RDTEXTURE, PLAYER->hp_bg, NULL);
    sfRenderTexture_drawRectangleShape(RDTEXTURE, PLAYER->st_bg, NULL);
    sfRenderTexture_drawRectangleShape(RDTEXTURE, PLAYER->hp_bar, NULL);
    sfRenderTexture_drawRectangleShape(RDTEXTURE, PLAYER->st_bar, NULL);
    sfRenderTexture_drawSprite(RDTEXTURE, PLAYER->info, NULL);
    sfRenderTexture_drawText(RDTEXTURE, PLAYER->text_lvl, NULL);
}

void continue_display(struct window *my_rpg)
{
    display_player_health(my_rpg);
    display_coconut_help(my_rpg);
    display_sword_help(my_rpg);
    display_npc_interaction(my_rpg);
    draw_tooltip(my_rpg);
    display_quest(my_rpg);
    display_menu(my_rpg);
}

void display_map_all(struct window *my_rpg)
{
    for (int i = 0; i < 4; ++i) {
        if (CURRENT_MAP->player_display == i + 1)
            display_player(my_rpg);
        display_map(my_rpg, my_rpg->tutorial->layers[i]);
    }
}

void display_all(struct window *my_rpg)
{
    if (STATE(main_menu)){
        display_main_menu(my_rpg);
        sfRenderTexture_display(RDTEXTURE);
        sfSprite_setTexture(RDSPRITE, sfRenderTexture_getTexture(RDTEXTURE),
            true);
        sfRenderWindow_drawSprite(WINDOW, RDSPRITE, NULL);
        sfRenderWindow_display(WINDOW);
        return;
    }
    display_map_all(my_rpg);
    continue_display(my_rpg);
    sfRenderTexture_display(RDTEXTURE);
    sfRenderTexture_display(HTEXTURE);
    sfSprite_setTexture(RDSPRITE, sfRenderTexture_getTexture(RDTEXTURE), true);
    sfRenderWindow_drawSprite(WINDOW, RDSPRITE, NULL);
    sfRenderWindow_display(WINDOW);
}
