/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init_texts
*/

#include "../../include/my_rpg.h"
#include <stdlib.h>

sfText *new_txt(char *str, int size, sfVector2f pos, sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f scale = {1, 1};

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setScale(text, scale);
    return text;
}

int init_texts(struct window *my_rpg)
{
    my_rpg->texts = malloc(sizeof(struct texts));
    CHECK_MALLOC(my_rpg->texts);

    TEXT(hp_level) = new_txt("1", 75, (sfVector2f){575, 375}, my_rpg->font);
    TEXT(dmg_level) = new_txt("1", 75, (sfVector2f){575, 665}, my_rpg->font);
    CHECK_MALLOC(TEXT(hp_level));
    CHECK_MALLOC(TEXT(dmg_level));
    return SUCCESS;
}
