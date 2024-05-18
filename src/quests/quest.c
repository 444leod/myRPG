/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** quest
*/

#include "../../include/my_rpg.h"

static int continue_quest(struct window *my_rpg, int sword)
{
    int max_x = 4420 + CURRENT_MAP->tile_size * 2;
    int min_x = 4420 - CURRENT_MAP->tile_size * 2;
    int max_y = 2519 + CURRENT_MAP->tile_size * 2;
    int min_y = 2519 - CURRENT_MAP->tile_size * 2;
    if (PLAYER->position.x >= min_x && PLAYER->position.x <= max_x &&
        PLAYER->position.y >= min_y && PLAYER->position.y <= max_y &&
        sword == 2) {
        STATE(quest) = 0;
        FIGHT(zone) = 2;
        STATE(fight) = 1;
    }
    return sword;
}

static void change_quest(struct window *my_rpg)
{
    static bool sword = 0;
    if (PLAYER->sword && PLAYER->coconut >= 0 && sword == 0) {
        QUEST(text) = new_txt("Find some coconuts", 30,
            (sfVector2f){1540, 70}, my_rpg->font);
        QUEST(nbr) = new_txt("0", 30, (sfVector2f){1640, 170}, my_rpg->font);
        QUEST(nbr2) =
                new_txt("/10", 30, (sfVector2f){1660, 170}, my_rpg->font);
        sword = 1;
    }
    if (PLAYER->coconut >= 10 && sword == 1) {
        sword = 2;
        QUEST(text) = new_txt("   Go to the pier", 30,
            (sfVector2f){1540, 70}, my_rpg->font);
        QUEST(nbr) = new_txt("", 30, (sfVector2f){1640, 170}, my_rpg->font);
        QUEST(nbr2) = new_txt("", 30, (sfVector2f){1660, 170}, my_rpg->font);
    }
    sword = continue_quest(my_rpg, sword);
}

void display_quest(struct window *my_rpg)
{
    if (STATE(quest) == 0)
        return;
    sfRenderTexture_drawSprite(RDTEXTURE, QUEST(bg)->sprite, NULL);
    sfRenderTexture_drawText(RDTEXTURE, QUEST(text), NULL);
    sfRenderTexture_drawText(RDTEXTURE, QUEST(nbr), NULL);
    sfRenderTexture_drawText(RDTEXTURE, QUEST(nbr2), NULL);
    change_quest(my_rpg);
}
