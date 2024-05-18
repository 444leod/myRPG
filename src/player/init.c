/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include <stdlib.h>

static void reset_player_data_bis(struct window *my_rpg)
{
    PLAYER->damage_p = 0;
    PLAYER->health_p = 0;
    PLAYER->sword = 0;
    PLAYER->coconut = 0;
    STATE(quest) = 1;
}

void reset_player_data(struct window *my_rpg)
{
    PLAYER->rect = (sfIntRect){0, 0, 64, 64};
    PLAYER->stamina = 100;
    PLAYER->health = 100;
    PLAYER->max_health = 100;
    PLAYER->damage = 1.0;
    PLAYER->xp = 10;
    PLAYER->max_stamina = 100;
    PLAYER->refill = 0;
    PLAYER->position = (sfVector2f){2800, 2900};
    PLAYER->speed = WALK;
    PLAYER->x = 2800;
    PLAYER->y = 2900;
    PLAYER->level = 1;
    PLAYER->skill_p = 0;
    reset_player_data_bis(my_rpg);
}

static void generate_text(struct window *my_rpg)
{
    PLAYER->hp_size = (sfVector2f){412 * .76, 24};
    sfRectangleShape_setFillColor(PLAYER->hp_bar, sfRed);
    sfRectangleShape_setSize(PLAYER->hp_bar, PLAYER->hp_size);
    sfRectangleShape_setPosition(PLAYER->hp_bar, (sfVector2f){225, 944});
    PLAYER->points_text = sfText_create();
    sfText_setFont(PLAYER->points_text, my_rpg->font);
    sfText_setCharacterSize(PLAYER->points_text, 50);
    sfText_setPosition(PLAYER->points_text, (sfVector2f){1080, 250});
    PLAYER->text_lvl = sfText_create();
    sfText_setFont(PLAYER->text_lvl, my_rpg->font);
    sfText_setCharacterSize(PLAYER->text_lvl, 45);
    sfText_setPosition(PLAYER->text_lvl, (sfVector2f){440, 1000});
    sfText_setString(PLAYER->text_lvl, "1");
}

static void generate_rects(struct window *my_rpg)
{
    PLAYER->st_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(PLAYER->st_bg, (sfColor){24, 20, 37, 255});
    sfRectangleShape_setSize(PLAYER->st_bg, (sfVector2f){344 * .76, 24});
    sfRectangleShape_setPosition(PLAYER->st_bg, (sfVector2f){225, 900});
    PLAYER->hp_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(PLAYER->hp_bg, (sfColor){24, 20, 37, 255});
    sfRectangleShape_setSize(PLAYER->hp_bg, (sfVector2f){412 * .76, 24});
    sfRectangleShape_setPosition(PLAYER->hp_bg, (sfVector2f){225, 944});
    PLAYER->st_bar = sfRectangleShape_create();
    PLAYER->st_size = (sfVector2f){344 * .76, 24};
    sfRectangleShape_setFillColor(PLAYER->st_bar, sfBlue);
    sfRectangleShape_setSize(PLAYER->st_bar, PLAYER->st_size);
    sfRectangleShape_setPosition(PLAYER->st_bar, (sfVector2f){225, 900});
    PLAYER->hp_bar = sfRectangleShape_create();
    generate_text(my_rpg);
}

int init_player(struct window *my_rpg)
{
    PLAYER = malloc(sizeof(struct player));
    PLAYER->position = (sfVector2f){2800, 2900};
    PLAYER->speed = WALK;
    PLAYER->direction = 1;
    PLAYER->rect = (sfIntRect){0, 0, 64, 64};
    PLAYER->sprite = sfSprite_create();
    PLAYER->texture = sfTexture_createFromFile("assets/player_swordless.png",
        NULL);
    CHECK_MALLOC(PLAYER->texture);
    PLAYER->info = sfSprite_create();
    PLAYER->info_texture = sfTexture_createFromFile("assets/p_info.png", NULL);
    CHECK_MALLOC(PLAYER->info_texture);
    sfSprite_setTexture(PLAYER->info, PLAYER->info_texture, sfTrue);
    sfSprite_setPosition(PLAYER->info, (sfVector2f){8, 872});
    sfSprite_setScale(PLAYER->info, (sfVector2f){0.76, 0.76});
    sfSprite_setTexture(PLAYER->sprite, PLAYER->texture, sfTrue);
    sfSprite_setTextureRect(PLAYER->sprite, PLAYER->rect);
    generate_rects(my_rpg);
    reset_player_data(my_rpg);
    return 0;
}
