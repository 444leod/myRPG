/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** collision
*/

#include "../include/my_rpg.h"
#include "../include/my.h"
#include <stdlib.h>

static int init_corner(struct window *my_rpg, int i, V2F coord)
{
    PLAYER->hitbox[i] = malloc(sizeof(sfVector2f) * 5);
    CHECK_MALLOC(PLAYER->hitbox[i]);
    PLAYER->hitbox[i][0] = (V2F){coord.x, coord.y};
    if (i == 0 || i == 1){
        PLAYER->hitbox[i][1] = (V2F){coord.x + 5, coord.y};
        PLAYER->hitbox[i][2] = (V2F){coord.x + 10, coord.y};
        PLAYER->hitbox[i][3] = (V2F){coord.x - 5, coord.y};
        PLAYER->hitbox[i][4] = (V2F){coord.x - 10, coord.y};
    } else {
        PLAYER->hitbox[i][1] = (V2F){coord.x, coord.y + 5};
        PLAYER->hitbox[i][2] = (V2F){coord.x, coord.y + 10};
        PLAYER->hitbox[i][3] = (V2F){coord.x, coord.y - 5};
        PLAYER->hitbox[i][4] = (V2F){coord.x, coord.y - 10};
    }
    return SUCCESS;
}

static int init_textures(struct window *my_rpg)
{
    my_rpg->hitbox = create_sprite("map/hitbox.png", (V2F){-3000, -3000});
    CHECK_MALLOC(my_rpg->hitbox);
    sfSprite_setScale(my_rpg->hitbox->sprite, (V2F){3, 3});
    HTEXTURE = sfRenderTexture_create(1920, 1080, 0);
    CHECK_MALLOC(HTEXTURE);
    HSPRITE = sfSprite_create();
    CHECK_MALLOC(HSPRITE);
    sfSprite_setTexture(HSPRITE, sfRenderTexture_getTexture(RDTEXTURE),
        sfTrue);
    sfSprite_setScale(HSPRITE, (sfVector2f){(float)(1920 / my_rpg->size.x),
        (float)(1080 / my_rpg->size.y)});
    return 0;
}

int init_collision(struct window *my_rpg)
{
    V2F base_pos = {VIDEO_MODE.width / 2 + 18, VIDEO_MODE.height / 2 + 20};
    V2F middle_top = (V2F){base_pos.x + 5, base_pos.y + 10};
    V2F middle_bottom = (V2F){base_pos.x + 5, base_pos.y + 50};
    V2F middle_left = (V2F){base_pos.x - 20, base_pos.y + 30};
    V2F middle_right = (V2F){base_pos.x + 30, base_pos.y + 30};
    V2F corner[4] = {middle_top, middle_bottom, middle_left, middle_right};

    PLAYER->hitbox = malloc(sizeof(sfVector2f *) * 4);
    CHECK_MALLOC(PLAYER->hitbox);
    for (int i = 0; i < 4; i++)
        CHECK_ERROR(init_corner(my_rpg, i, corner[i]));
    CHECK_ERROR(init_textures(my_rpg));
    return SUCCESS;
}
