/*
** EPITECH PROJECT, 2023
** current
** File description:
** fight
*/

#include "../../include/my_rpg.h"

void display_window(struct window *my_rpg)
{
    sfRenderTexture_display(RDTEXTURE);
    sfRenderTexture_display(HTEXTURE);
    sfSprite_setTexture(RDSPRITE, sfRenderTexture_getTexture(RDTEXTURE), true);
    sfRenderWindow_drawSprite(WINDOW, RDSPRITE, NULL);
    sfRenderWindow_display(WINDOW);
    sfRenderTexture_clear(RDTEXTURE, sfWhite);
    sfRenderTexture_clear(HTEXTURE, sfTransparent);
}

void update_health(struct window *my_rpg)
{
    float life_ratio = (F_PLAYER(hp) >= 0) ?
        (float)F_PLAYER(hp) / F_PLAYER(max_hp) : 0;
    int l = (int)(320 * life_ratio);
    IRECT rect = (IRECT){0, 0, l, 27};

    rect.top = (l < 155 && l >= 78) ? 27 : (l < 78) ? 54 : 0;
    sfSprite_setTextureRect(F_PLAYER(life)->sprite, rect);

    life_ratio = (F_ENNEMY(hp) >= 0) ?
        (float)F_ENNEMY(hp) / F_ENNEMY(max_hp) : 0;
    l = (int)(320 * life_ratio);
    rect = (IRECT){0, 27, l, 27};
    rect.top = (l < 155 && l >= 78) ? 27 : (l < 78) ? 54 : 0;
    sfSprite_setTextureRect(F_ENNEMY(life)->sprite, rect);
}

void draw_health_and_xp(struct window *my_rpg)
{
    update_health(my_rpg);
    if (FIGHT(state) == 2 || FIGHT(state) == 3){
        sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(box)->sprite, NULL);
        sfRenderTexture_drawText(RDTEXTURE, FIGHT(attack_text), NULL);
    }
    sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(healths)->sprite, NULL);
    sfRenderTexture_drawSprite(RDTEXTURE, F_PLAYER(life)->sprite, NULL);
    sfRenderTexture_drawSprite(RDTEXTURE, F_PLAYER(xp)->sprite, NULL);
    sfRenderTexture_drawSprite(RDTEXTURE, F_ENNEMY(life)->sprite, NULL);
    sfRenderTexture_drawText(RDTEXTURE, F_ENNEMY(name), NULL);
    sfRenderTexture_drawText(RDTEXTURE, F_ENNEMY(lvl), NULL);
    sfRenderTexture_drawText(RDTEXTURE, F_PLAYER(lvl), NULL);
}

static void display_attacks(struct window *my_rpg)
{
    if (FIGHT(state) == 0)
        sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(fightscreen)->sprite, NULL);
    if (FIGHT(state) == 1) {
        sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(attacks)->sprite, NULL);
        if (FIGHT(nbr) >= 1)
            RT_drawSprite(RDTEXTURE, FIGHT(attacks_sp)[0]->sprite, NULL);
        if (FIGHT(nbr) >= 2)
            RT_drawSprite(RDTEXTURE, F_PLAYER(slots)[1]->sprite->sprite, NULL);
        if (FIGHT(nbr) >= 3)
            RT_drawSprite(RDTEXTURE, F_PLAYER(slots)[2]->sprite->sprite, NULL);
        if (FIGHT(nbr) == 4)
            RT_drawSprite(RDTEXTURE, F_PLAYER(slots)[3]->sprite->sprite, NULL);
    }

}

void display_fight(struct window *my_rpg)
{
    sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(bg)[FIGHT(zone)]->sprite, NULL);
    draw_health_and_xp(my_rpg);
    display_attacks(my_rpg);
    if (FIGHT(bag_state))
        display_bag(my_rpg);
    display_window(my_rpg);
}
