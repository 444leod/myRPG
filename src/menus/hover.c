/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** hover
*/

#include "../../include/my_rpg.h"

static void hover_main(struct window *my_rpg, sfVector2f pos)
{
    display_hover(pos, RECTANGLE, RDTEXTURE, BUTTON(play));
    display_hover(pos, RECTANGLE, RDTEXTURE, BUTTON(credits));
    display_hover(pos, RECTANGLE, RDTEXTURE, BUTTON(option));
    display_hover(pos, RECTANGLE, RDTEXTURE, BUTTON(exit));
}

static void hover_pause(struct window *my_rpg, sfVector2f pos)
{
    display_hover(pos, RECTANGLE, RDTEXTURE, BUTTON(resume));
    display_hover(pos, RECTANGLE, RDTEXTURE, BUTTON(save));
    display_hover(pos, RECTANGLE, RDTEXTURE, BUTTON(p_option));
    display_hover(pos, RECTANGLE, RDTEXTURE, BUTTON(p_exit));
}

void menu_display_hover(struct window *my_rpg, sfVector2f pos)
{
    if (STATE(main_menu) && !STATE(options) && !STATE(credits) && !STATE(load))
        hover_main(my_rpg, pos);
    if (STATE(pause))
        hover_pause(my_rpg, pos);

    if (STATE(load)){
        sfRectangleShape_setFillColor(BUTTON(play)->rect, sfRed);
        sfRenderTexture_drawRectangleShape(RDTEXTURE, BUTTON(play)->rect, 0);
        sfRectangleShape_setFillColor(BUTTON(play)->rect, ORANGE);
    }
    if (STATE(options) && !STATE(pause)){
        sfRectangleShape_setFillColor(BUTTON(option)->rect, sfRed);
        sfRenderTexture_drawRectangleShape(RDTEXTURE, BUTTON(option)->rect, 0);
        sfRectangleShape_setFillColor(BUTTON(option)->rect, ORANGE);
    }
    if (STATE(credits)){
        sfRectangleShape_setFillColor(BUTTON(credits)->rect, sfRed);
        sfRenderTexture_drawRectangleShape(RDTEXTURE, BUTTON(credits)->rect, 0);
        sfRectangleShape_setFillColor(BUTTON(credits)->rect, ORANGE);
    }
}
