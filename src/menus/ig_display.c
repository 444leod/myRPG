/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** ig_display
*/

#include "../../include/my_rpg.h"
#include "../../include/my.h"

static void display_pause(struct window *my_rpg)
{
    sfRenderTexture_drawRectangleShape(RDTEXTURE, BUTTON(pause_bg)->rect, NULL);
    sfVector2f pos = get_pxmousepos(WINDOW);
    pos.y *= 1080 / (float)my_rpg->size.y;
    pos.x *= 1920 / (float)my_rpg->size.x;
    menu_display_hover(my_rpg, pos);
    sfRenderTexture_drawSprite(RDTEXTURE, MENU(pause)->sprite, NULL);
}

static void display_inventory(struct window *my_rpg)
{
    sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(bag)->sprite, NULL);
    sfRenderTexture_drawText(RDTEXTURE, FIGHT(bag_text), NULL);
}

static void display_skills(struct window *my_rpg)
{
    sfRenderTexture_drawSprite(RDTEXTURE, MENU(skills)->sprite, NULL);
    sfText_setString(PLAYER->points_text, my_int_to_str(PLAYER->skill_p));
    sfText_setString(my_rpg->texts->hp_level,
        my_int_to_str(PLAYER->health_p));
    sfText_setString(my_rpg->texts->dmg_level,
        my_int_to_str(PLAYER->damage_p));
    sfRenderTexture_drawText(RDTEXTURE, PLAYER->points_text, NULL);
    sfRenderTexture_drawText(RDTEXTURE, my_rpg->texts->hp_level, NULL);
    sfRenderTexture_drawText(RDTEXTURE, my_rpg->texts->dmg_level, NULL);
}

void display_menu(struct window *my_rpg)
{
    if (STATE(fight))
        fight_screen(my_rpg);
    if (STATE(pause))
        display_pause(my_rpg);
    if (STATE(inventory))
        display_inventory(my_rpg);
    if (STATE(options))
        display_option(my_rpg);
    if (STATE(skills))
        display_skills(my_rpg);
    if (STATE(controls))
        sfRenderTexture_drawSprite(RDTEXTURE, MENU(controls)->sprite, NULL);
}
