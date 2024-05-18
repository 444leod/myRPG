/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** window
*/

#include "../../include/my_rpg.h"
#include <stdlib.h>

static int continue_init(struct window *my_rpg)
{
    my_rpg->player_anim_clock = sfClock_create();
    my_rpg->player_mov_clock = sfClock_create();
    my_rpg->map_clock = sfClock_create();
    my_rpg->npc_clock = sfClock_create();
    my_rpg->npc_line = 0;
    return SUCCESS;
}

int init_window(struct window *my_rpg)
{
    VIDEO_MODE.width = 1920;
    VIDEO_MODE.height = 1080;
    VIDEO_MODE.bitsPerPixel = 32;
    STYLE = (sfResize | sfClose);
    WINDOW = sfRenderWindow_create(VIDEO_MODE, "My RPG", STYLE, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW, 60);
    sfImage *icon = sfImage_createFromFile("assets/icon.png");
    CHECK_MALLOC(icon);
    my_rpg->icon = sfImage_getPixelsPtr(icon);
    sfRenderWindow_setIcon(WINDOW, 512, 512, my_rpg->icon);
    RDTEXTURE = sfRenderTexture_create(1920, 1080, 0);
    RDSPRITE = sfSprite_create();
    sfSprite_setTexture(RDSPRITE, sfRenderTexture_getTexture(RDTEXTURE),true);
    my_rpg->size = sfRenderWindow_getSize(WINDOW);
    sfSprite_setScale(RDSPRITE, (sfVector2f){(float)(1920 / my_rpg->size.x),
        (float)(1080 / my_rpg->size.y)});
    my_rpg->text = sfText_create();
    my_rpg->font = sfFont_createFromFile("./assets/MinimalPixel_v2.ttf");
    return continue_init(my_rpg);
}
