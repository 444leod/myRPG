/*
** EPITECH PROJECT, 2023
** clean.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include <stdlib.h>

void clean_tooltip(struct tooltip *tooltip)
{
    sfSprite_destroy(tooltip->sprite);
    sfTexture_destroy(tooltip->texture);
    sfText_destroy(tooltip->text);
    sfFont_destroy(tooltip->font);
    free(tooltip);
}
