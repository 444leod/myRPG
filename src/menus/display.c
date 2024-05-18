/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** display menu
*/

#include "../../include/my_rpg.h"

void display_option(struct window *my_rpg)
{
    sfRenderTexture_drawSprite(RDTEXTURE, MENU(option)->sprite, NULL);
    sfRenderTexture_drawSprite(RDTEXTURE, BUTTON(fullscreen)->sprite, NULL);
    sfRenderTexture_drawSprite(RDTEXTURE, BUTTON(windowed)->sprite, NULL);
    sfRenderTexture_drawSprite(RDTEXTURE,
        BUTTON(screen_size)[STATE(s_size)]->sprite, NULL);
    sfRenderTexture_drawRectangleShape(RDTEXTURE, MENU(sound)->rect, NULL);
    sfRenderTexture_drawRectangleShape(RDTEXTURE, MENU(music)->rect, NULL);
    sfRectangleShape_setFillColor(BUTTON(option)->rect, ORANGE);

}

static void display_credits(struct window *my_rpg)
{
    sfRenderTexture_drawSprite(RDTEXTURE, MENU(credits)->sprite, NULL);
}

static void display_load(struct window *my_rpg)
{
    sfRenderTexture_drawSprite(RDTEXTURE, MENU(load)->sprite, NULL);
    display_save_data(my_rpg);
    if (!save_exists())
        sfRenderTexture_drawRectangleShape(RDTEXTURE, BUTTON(grey)->rect, NULL);
}

void display_main_menu(struct window *my_rpg)
{
    sfRenderTexture_drawSprite(RDTEXTURE, MENU(main)->sprite, NULL);
    if (STATE(options))
        display_option(my_rpg);
    if (STATE(credits))
        display_credits(my_rpg);
    if (STATE(load))
        display_load(my_rpg);
}
