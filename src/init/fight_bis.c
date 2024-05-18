/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** fight_bis
*/

#include "../../include/my_rpg.h"
#include "../../include/my.h"

static int init_txt_bis_bis(struct window *my_rpg)
{
    FIGHT(bag_text) = sfText_create();
    CHECK_MALLOC(FIGHT(bag_text));
    sfText_setFont(FIGHT(bag_text), my_rpg->font);
    sfText_setCharacterSize(FIGHT(bag_text), 50);
    sfText_setPosition(FIGHT(bag_text), (sfVector2f){500, 256});
    sfText_setColor(FIGHT(bag_text), sfWhite);
    sfText_setString(FIGHT(bag_text), "0");
    FIGHT(no_more) = create_sprite("fight/no_more_coco.png", (V2F){431, 85});
    CHECK_MALLOC(FIGHT(no_more));
    FIGHT(bag_rect) = create_rect(sfWhite, (IRECT){743, 785, 446, 247});
    return SUCCESS;
}

static int init_txt_bis(struct window *my_rpg)
{
    FIGHT(attack_text) = sfText_create();
    CHECK_MALLOC(FIGHT(attack_text));
    sfText_setFont(FIGHT(attack_text), my_rpg->font);
    sfText_setCharacterSize(FIGHT(attack_text), 50);
    sfText_setPosition(FIGHT(attack_text), (sfVector2f){129, 930});
    sfText_setColor(FIGHT(attack_text), sfWhite);
    STATE(fight) = 0;
    FIGHT(use_rect) = create_rect(sfWhite, (IRECT){1172, 314, 238, 129});
    FIGHT(bag_state) = 0;
    init_txt_bis_bis(my_rpg);
    return SUCCESS;
}

int init_fight_texts(struct window *my_rpg)
{
    F_PLAYER(lvl) = sfText_create();
    CHECK_MALLOC(F_PLAYER(lvl));
    sfText_setString(F_PLAYER(lvl), my_int_to_str(PLAYER->level));
    sfText_setFont(F_PLAYER(lvl), my_rpg->font);
    sfText_setCharacterSize(F_PLAYER(lvl), 60);
    sfText_setPosition(F_PLAYER(lvl), (sfVector2f){1775, 722});
    sfText_setColor(F_PLAYER(lvl), sfBlack);
    F_ENNEMY(lvl) = sfText_create();
    CHECK_MALLOC(F_ENNEMY(lvl));
    sfText_setString(F_ENNEMY(lvl), "1");
    sfText_setFont(F_ENNEMY(lvl), my_rpg->font);
    sfText_setCharacterSize(F_ENNEMY(lvl), 50);
    sfText_setPosition(F_ENNEMY(lvl), (sfVector2f){570, 180});
    sfText_setColor(F_ENNEMY(lvl), sfBlack);
    CHECK_ERROR(init_txt_bis(my_rpg));
    return SUCCESS;
}

int init_fight_lifes(struct window *my_rpg)
{
    F_PLAYER(life) = create_sprite("fight/life_bar.png", (V2F){1533, 807});
    CHECK_MALLOC(F_PLAYER(life));
    sfSprite_setTextureRect(F_PLAYER(life)->sprite, (IRECT){0, 0, 320, 27});
    F_ENNEMY(life) = create_sprite("fight/life_bar.png", (V2F){333, 264});
    CHECK_MALLOC(F_ENNEMY(life));
    sfSprite_setTextureRect(F_ENNEMY(life)->sprite, (IRECT){0, 1, 320, 26});
    F_PLAYER(xp) = create_sprite("fight/life_bar.png", (V2F){1313, 927});
    CHECK_MALLOC(F_PLAYER(xp));
    sfSprite_setTextureRect(F_PLAYER(xp)->sprite, (IRECT){0, 81, 601, 19});
    FIGHT(box) = create_sprite("fight/box.png", (V2F){0, 0});
    CHECK_MALLOC(FIGHT(box));
    return SUCCESS;
}
