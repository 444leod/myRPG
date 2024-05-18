/*
** EPITECH PROJECT, 2023
** security.c
** File description:
** B-MUL-200-LIL-2-1-mypaint-nicolas.pechart
*/
#include "../include/my.h"

static int continue_verif_deps(void)
{
    char *deps[] = {
"assets/font.ttf","assets/npc","assets/npc/365","assets/npc/.gitkeep",
"assets/player_swordless.png","assets/sound","assets/sound/main_theme.ogg",
"assets/sound/coconut.ogg","assets/sound/heal.ogg","assets/sound/sword.ogg",
"assets/sound/whistle.ogg","assets/sound/win.ogg","assets/p_info.png",
"assets/menu","assets/menu/controls.png","assets/menu/skills.png",
"assets/menu/ingame.png","assets/menu/load.png",
"assets/menu/ttip.png","assets/menu/skills2.png","assets/menu/1680.png",
"assets/menu/option.png","assets/menu/1920.png","assets/menu/fullscreen_c.png",
"assets/menu/main.png","assets/menu/fullscreen.png",
"assets/menu/windowed.png","assets/menu/credits.png",
"assets/menu/inventory.png","assets/fight","assets/fight/fight_health.png",
"assets/fight/fight_screen.png","assets/fight/bag.png",
"assets/fight/background1.png","assets/fight/attack7.png",
"assets/fight/attack4.png","assets/fight/attacks_screen.png",
    };
    for (int i = 0; i < 6; i++)
        if (my_file_exists(deps[i]) == 0)
            return 84;
    return 0;
}

int verif_deps(void)
{
    char *deps[] = {
"assets/fight/life_bar.png","assets/fight/attack5.png",
"assets/fight/background2.png","assets/fight/attack2.png",
"assets/fight/no_more_coco.png", "assets/fight/attack1.png",
"assets/fight/box.png", "assets/fight/background3.png",
"assets/fight/attack6.png", "assets/fight/attack3.png",
"assets/text_box.png", "assets/MinimalPixel_v2.ttf",
"assets/player.png", "assets/map", "assets/map/hitbox.png",
"assets/map/tutorial", "assets/map/tutorial/layer_1.csv",
"assets/map/tutorial/layer_4.csv", "assets/map/tutorial/layer_2.csv",
"assets/map/tutorial/layer_3.csv", "assets/map/tutorial/sprite.png",
"assets/map/tutorial/map_refaite.tmx", "assets/map/tutorial/beach_tileset.tsx",
"assets/icon.png", "assets/explosion.jpg", "assets/quest_box.png",
"assets/intro_end", "assets/intro_end/discu3.png",
"assets/intro_end/discu7.png", "assets/intro_end/discu5.png",
"assets/intro_end/discu1.png", "assets/intro_end/discu6.png",
"assets/intro_end/discu4.png", "assets/intro_end/discu2.png",
    };
    for (int i = 0; i < 6; i++)
        if (my_file_exists(deps[i]) == 0)
            return 84;
    return continue_verif_deps();
}
