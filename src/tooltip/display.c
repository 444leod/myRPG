/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

void hide_tooltip(struct window *my_rpg)
{
    TOOLTIP->is_active = 0;
}

void display_tooltip(char *text, struct window *my_rpg)
{
    char *f_text = malloc(sizeof(char) * (my_strlen(text) + 6));
    my_memset(f_text, my_strlen(text) + 6);
    if (text == NULL) return;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '*')
            text[i] = '\n';
        f_text[i] = text[i];
    }
    sfText_setString(TOOLTIP->text, f_text);
    TOOLTIP->is_active = 1;
}

void draw_tooltip(struct window *my_rpg)
{
    if (TOOLTIP->is_active == 0)
        return;
    sfRenderTexture_drawSprite(RDTEXTURE, TOOLTIP->sprite, NULL);
    sfRenderTexture_drawText(RDTEXTURE, TOOLTIP->text, NULL);
}
