/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** new_attack
*/

#include "../../include/my_rpg.h"

static void display_skill_screen(struct window *my_rpg, int a)
{
    sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(bg)[FIGHT(zone)]->sprite, NULL);
    sfRenderTexture_drawSprite(RDTEXTURE, MENU(skills2)->sprite, NULL);
    sfSprite_setPosition(FIGHT(attacks_sp)[a]->sprite, (sfVector2f){587, 338});
    FIGHT(attacks_sp)[a]->rect = sfSprite_getGlobalBounds(FIGHT(attacks_sp)[a]
        ->sprite);
    sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(attacks_sp)[a]->sprite, NULL);
    sfSprite_setPosition(FIGHT(attacks_sp)[a + 1]->sprite, (sfVector2f)
        {582, 687});
    FIGHT(attacks_sp)[a + 1]->rect = sfSprite_getGlobalBounds(FIGHT(attacks_sp)
        [a + 1]->sprite);
    sfRenderTexture_drawSprite(RDTEXTURE, FIGHT(attacks_sp)[a + 1]->sprite,
        NULL);
    display_window(my_rpg);
}

static void handle_skill_events(struct window *my_rpg, int a, int *level)
{
    sfVector2f pos = get_pxmousepos(WINDOW);
    pos.y *= 1080 / (float)my_rpg->size.y;
    pos.x *= 1920 / (float)my_rpg->size.x;
    if (EVENT.type == sfEvtClosed)
        sfRenderWindow_close(WINDOW);
    if (has_clicked(EVENT, sfMouseLeft)) {
        if (MOUSE_ON_F(FIGHT(attacks_sp)[a]->rect, pos)){
            F_PLAYER(slots)[(a == 1) ? 1 : (a == 3) ? 2 : 3] =
                create_slot(a, FIGHT(attacks_sp)[a], FIGHT(attack_stats[a]));
            (*level) = 0;
        }
        if (MOUSE_ON_F(FIGHT(attacks_sp)[a + 1]->rect, pos)){
            F_PLAYER(slots)[(a == 1) ? 1 : (a == 3) ? 2 : 3] =
                create_slot(a + 1, FIGHT(attacks_sp)[a + 1],
                    FIGHT(attack_stats[a + 1]));
            (*level) = 0;
        }
    }
}

void display_choose_attack(struct window *my_rpg)
{
    if (PLAYER->level == 1 || (PLAYER->level == 2 && FIGHT(nbr) == 2) ||
    (PLAYER->level == 3 && FIGHT(nbr) == 3) || FIGHT(nbr) == 4)
        return;
    int lvl = 1;
    int a = (FIGHT(nbr) == 1 && PLAYER->level == 2) ? 1 : (FIGHT(nbr) == 1 &&
        PLAYER->level == 3) ? 3 : 5;
    while (sfRenderWindow_isOpen(WINDOW) && lvl) {
        while (GET_EVENT(WINDOW, &EVENT))
            handle_skill_events(my_rpg, a, &lvl);
        sfRenderWindow_clear(WINDOW, sfBlack);
        display_skill_screen(my_rpg, a);
    }
}
