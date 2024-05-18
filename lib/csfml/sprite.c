/*
** EPITECH PROJECT, 2023
** CSFML LIB
** File description:
** sprite
*/

#include "../../include/lib_csfml.h"
#include <stdarg.h>
#include <stdlib.h>

static int my_strlenn(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

static char *my_strcatt(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *temp = malloc(sizeof(char) *
        (my_strlenn(dest) + my_strlenn(src) + 1));

    while (dest[i] != '\0'){
        temp[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        temp[i] = src[j];
        i++;
        j++;
    }
    temp[i] = '\0';
    return temp;
}

static char *supercatt(int nbr, ...)
{
    va_list ap;
    char *str = malloc(sizeof(char));
    char *temp;

    str[0] = '\0';
    va_start(ap, nbr);
    for (int i = 0; i < nbr; i++){
        temp = my_strcatt(str, va_arg(ap, char *));
        free(str);
        str = temp;
    }
    va_end(ap);
    return str;
}

image_t create_sprite(char *file_name, sfVector2f pos)
{
    image_t image = malloc(sizeof(struct my_image));
    char *path = supercatt(2, "assets/", file_name);

    image->texture = sfTexture_createFromFile(path, NULL);
    if (!image->texture)
        return NULL;
    image->sprite = sfSprite_create();
    if (!image->sprite)
        return NULL;
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setPosition(image->sprite, pos);
    image->rect = sfSprite_getGlobalBounds(image->sprite);

    return image;
}
