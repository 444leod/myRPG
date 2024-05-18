/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** collision
*/

#include "../../include/my_rpg.h"

static void change_player(struct window *my_rpg, char c)
{
    switch (c) {
    case 'r':
        PLAYER->rect.top = 192;
        break;
    case 'l':
        PLAYER->rect.top = 64;
        break;
    case 'u':
        PLAYER->rect.top = 0;
        break;
    case 'd':
        PLAYER->rect.top = 128;
        break;
    }
}

static int check_color(struct window *my_rpg, sfVector2f *side)
{
    sfColor colors[5];
    for (int i = 0; i < 5; i++){
        colors[i] = sfImage_getPixel(HIMAGE, side[i].x, side[i].y);
        if (colors[i].r == 255)
            return false;
    }
    return true;
}

bool check_coll(struct window *my_rpg, char c)
{
    HIMAGE = sfTexture_copyToImage(sfRenderTexture_getTexture(HTEXTURE));
    int val = false;
    change_player(my_rpg, c);
    if (c == 'r')
        val = check_color(my_rpg, PLAYER->hitbox[RIGHT]);
    if (c == 'l')
        val = check_color(my_rpg, PLAYER->hitbox[LEFT]);
    if (c == 'u')
        val = check_color(my_rpg, PLAYER->hitbox[TOP]);
    if (c == 'd')
        val = check_color(my_rpg, PLAYER->hitbox[BOTTOM]);
    sfImage_destroy(HIMAGE);
    return val;
}
