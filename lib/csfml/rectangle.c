/*
** EPITECH PROJECT, 2023
** CSFML LIB
** File description:
** rectangle
*/

#include "../../include/lib_csfml.h"
#include <stdlib.h>
#include <unistd.h>

static int my_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

static void my_error(char *str)
{
    write(2, str, my_strlen(str));
}

rect_t create_rect(sfColor color, sfIntRect recta)
{
    rect_t rect = malloc(sizeof(struct my_rect));

    if (!rect){
        my_error("Error : Can't create the rect\n");
        return NULL;
    }
    rect->rect = sfRectangleShape_create();
    if (!rect->rect){
        my_error("Error : Can't create the rect\n");
        return NULL;
    }
    sfRectangleShape_setFillColor(rect->rect, color);
    sfRectangleShape_setSize(rect->rect, (V2F){recta.width, recta.height});
    sfRectangleShape_setPosition(rect->rect, (V2F){recta.left, recta.top});
    rect->bounds = recta;
    return rect;
}
