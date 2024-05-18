/*
** EPITECH PROJECT, 2023
** clean.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../include/my_rpg.h"
#include "../include/my.h"
#include <stdlib.h>

void destroy_all(struct window *my_rpg)
{
    clean_player(my_rpg);
    sfRenderTexture_destroy(my_rpg->texture);
    sfText_destroy(my_rpg->text);
    sfFont_destroy(my_rpg->font);
    sfSprite_destroy(my_rpg->sprite);
    sfRenderWindow_destroy(my_rpg->window);
    sfClock_destroy(my_rpg->map_clock);
    sfClock_destroy(my_rpg->player_mov_clock);
    sfClock_destroy(my_rpg->npc_clock);
    sfClock_destroy(my_rpg->player_anim_clock);
    sfRenderTexture_destroy(my_rpg->hitbox_texture);
    sfSprite_destroy(my_rpg->hitbox_sprite);
    sfTexture_destroy(my_rpg->menus->option->texture);
    sfSprite_destroy(my_rpg->menus->option->sprite);
    free(my_rpg);
}
