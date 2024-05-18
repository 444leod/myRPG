/*
** EPITECH PROJECT, 2023
** CSFML LIB
** File description:
** set_invisible
*/

#include "../../include/lib_csfml.h"

void text_set_visible(sfText *text, bool state)
{
    if (state)
        sfText_setColor(text, (sfColor){255, 255, 255, 255});
    else
        sfText_setColor(text, (sfColor){255, 255, 255, 0});
}

void sp_set_visible(sfSprite *sprite, bool state)
{
    if (state)
        sfSprite_setColor(sprite, (sfColor){255, 255, 255, 255});
    else
        sfSprite_setColor(sprite, (sfColor){255, 255, 255, 0});
}

void rect_set_visible(sfRectangleShape *rect, bool state)
{
    if (state)
        sfRectangleShape_setFillColor(rect, (sfColor){255, 255, 255, 255});
    else
        sfRectangleShape_setFillColor(rect, (sfColor){255, 255, 255, 0});
}
