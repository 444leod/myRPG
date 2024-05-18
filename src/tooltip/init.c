/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include <stdlib.h>

int init_tooltip(struct window *my_rpg)
{
    TOOLTIP = malloc(sizeof(struct tooltip));
    TOOLTIP->text = sfText_create();
    TOOLTIP->sprite = sfSprite_create();
    TOOLTIP->texture = sfTexture_createFromFile("assets/menu/ttip.png", NULL);
    CHECK_MALLOC(TOOLTIP->text);
    TOOLTIP->is_active = 0;
    TOOLTIP->font = sfFont_createFromFile("assets/MinimalPixel_v2.ttf");
    CHECK_MALLOC(TOOLTIP->font);
    sfText_setFont(TOOLTIP->text, TOOLTIP->font);
    sfText_setCharacterSize(TOOLTIP->text, 20);
    sfText_setColor(TOOLTIP->text, sfWhite);
    sfText_setString(TOOLTIP->text, "");
    sfText_setPosition(TOOLTIP->text, (sfVector2f){890, 928});
    sfSprite_setPosition(TOOLTIP->sprite, (sfVector2f){860, 908});
    sfSprite_setTexture(TOOLTIP->sprite, TOOLTIP->texture, sfTrue);
    sfSprite_setScale(TOOLTIP->sprite, (sfVector2f){1.5, 1.3});
    return SUCCESS;
}
