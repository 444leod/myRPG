/*
** EPITECH PROJECT, 2023
** display_informations.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

char *format_int(int nb, int zero)
{
    char *str = malloc(sizeof(char) * 10);
    int i = 0;

    for (i = 0; nb > 0; i++) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    for (; i < zero; i++)
        str[i] = '0';
    str[i] = '\0';
    return my_revstr(str);
}

void display_save_data(struct window *my_rpg)
{
    char *str_health = format_int(get_health(), 3);
    char *str_stamina = format_int(get_stamina(), 3);
    char *str_xp = format_int(get_xp() / 100, 3);

    sfText_setColor(my_rpg->text, sfWhite);
    sfText_setFont(my_rpg->text, my_rpg->font);
    sfText_setCharacterSize(my_rpg->text, 42);
    sfText_setString(my_rpg->text, str_health);
    sfText_setPosition(my_rpg->text, (sfVector2f){1134, 680});
    sfRenderTexture_drawText(RDTEXTURE, my_rpg->text, NULL);
    sfText_setString(my_rpg->text, str_stamina);
    sfText_setPosition(my_rpg->text, (sfVector2f){1134, 735});
    sfRenderTexture_drawText(RDTEXTURE, my_rpg->text, NULL);
    sfText_setString(my_rpg->text, str_xp);
    sfText_setPosition(my_rpg->text, (sfVector2f){1134, 790});
    sfRenderTexture_drawText(RDTEXTURE, my_rpg->text, NULL);
    free(str_health);
    free(str_stamina);
    free(str_xp);
}
