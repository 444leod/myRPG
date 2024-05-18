/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** display
*/

#include "../../include/my_rpg.h"
#include <stdarg.h>

static void display_sprite(sfRenderTexture *window, image_t sprite,
    sfVector2f pos)
{
    if (is_mouse_on_sprite_f(sprite->rect, pos))
        sfRenderTexture_drawSprite(window, sprite->sprite, NULL);
}

static void display_rect(sfRenderTexture *window, rect_t rect, sfVector2f pos)
{
    if (is_mouse_on_sprite(rect->bounds, pos))
        sfRenderTexture_drawRectangleShape(window, rect->rect, NULL);
}

void display_hover(V2F pos, int type, sfRenderTexture *window, ...)
{
    va_list list;
    va_start(list, window);

    switch (type) {
        case SPRITE:
            display_sprite(window, va_arg(list, image_t), pos);
            break;
        case RECTANGLE:
            display_rect(window, va_arg(list, rect_t), pos);
            break;
    }
}
