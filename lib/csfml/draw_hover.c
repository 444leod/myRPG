/*
** EPITECH PROJECT, 2023
** CSFML LIB
** File description:
** draw_hover
*/

#include "../../include/lib_csfml.h"

void draw_if_hover(sfRenderTexture *window, sfFloatRect bounds,
    sfSprite *sprite, sfVector2f mousePos)
{
    if (is_mouse_on_sprite_f(bounds, mousePos))
        sfRenderTexture_drawSprite(window, sprite, NULL);
}
