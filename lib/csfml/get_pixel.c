/*
** EPITECH PROJECT, 2023
** CSFML LIB
** File description:
** get_pixel
*/

#include "../../include/lib_csfml.h"

sfColor get_pixel(sfSprite *sprite, sfVector2f mousePos, sfFloatRect bounds)
{
    return sfImage_getPixel(sfTexture_copyToImage(
        sfSprite_getTexture(sprite)), mousePos.x - bounds.left,
        mousePos.y - bounds.top);
}
