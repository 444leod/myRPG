/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** main macros of my_rpg
*/


#ifndef B_MUL_200_LIL_2_1_MYRPG_NICOLAS_PECHART_MY_MACRO_H
    #define B_MUL_200_LIL_2_1_MYRPG_NICOLAS_PECHART_MY_MACRO_H

    #include "../my_rpg.h"



//                ███    ███  █████   ██████ ██████   ██████  ███████
//                ████  ████ ██   ██ ██      ██   ██ ██    ██ ██
//                ██ ████ ██ ███████ ██      ██████  ██    ██ ███████
//                ██  ██  ██ ██   ██ ██      ██   ██ ██    ██      ██
//                ██      ██ ██   ██  ██████ ██   ██  ██████  ███████

    static int const square_size = 48;

    #define PLAYER my_rpg->player
    #define EVENT my_rpg->event
    #define CURRENT_MAP my_rpg->current_map
    #define WINDOW my_rpg->window
    #define VIDEO_MODE my_rpg->video_mode
    #define STYLE my_rpg->style
    #define ORANGE sfColor_fromRGB(255, 165, 0)
    #define FS fullscreen
    #define WW windowed
    #define RDTEXTURE my_rpg->texture
    #define RDSPRITE my_rpg->sprite
    #define HSPRITE my_rpg->hitbox_sprite
    #define HTEXTURE my_rpg->hitbox_texture
    #define HIMAGE my_rpg->hitbox_image
    #define ESC EVENT.type == sfEvtKeyPressed && EVENT.key.code == sfKeyEscape
    #define TILEPOS tiles->position
    #define SWIDTH screen_width
    #define SHEIGHT screen_height
    #define ATTACK_ID(x) F_PLAYER(slots)[x]->id
    #define TOOLTIP my_rpg->tooltip


    #define STATE(x)    my_rpg->states->x
    #define MENU(x)     my_rpg->menus->x
    #define BUTTON(x)   my_rpg->buttons->x
    #define TEXT(x)     my_rpg->texts->x
    #define SOUND(x)    my_rpg->sounds->x
    #define FIGHT(x)    my_rpg->fight->x
    #define F_PLAYER(x) my_rpg->fight->ally->x
    #define F_ENNEMY(x) my_rpg->fight->ennemy->x

    #define STATE(x) my_rpg->states->x
    #define MENU(x) my_rpg->menus->x
    #define BUTTON(x) my_rpg->buttons->x
    #define TEXT(x) my_rpg->texts->x
    #define SOUND(x) my_rpg->sounds->x
    #define TIME(x) sfClock_getElapsedTime(x).microseconds / 1000000.0
    #define RESET_TIME(x) sfClock_restart(x)
    #define QUEST(x) my_rpg->quests->x

    #define CHECK_ERROR(x) if (x == 84) return (84)
    #define CHECK_MALLOC(x) if (x == NULL) return (84)
    #define SUCCESS 0
    #define FAILURE 84
    #define UNUSED __attribute__((unused))

    #define isKeyPressed sfKeyboard_isKeyPressed
    #define RT_drawSprite sfRenderTexture_drawSprite

    #define ISKEYPRESSED sfKeyboard_isKeyPressed
    #define MYITOS my_int_to_str
    #define MYGNBR my_get_nbr_len




//              ███████ ███    ██ ██    ██ ███    ███ ███████
//              ██      ████   ██ ██    ██ ████  ████ ██
//              █████   ██ ██  ██ ██    ██ ██ ████ ██ ███████
//              ██      ██  ██ ██ ██    ██ ██  ██  ██      ██
//              ███████ ██   ████  ██████  ██      ██ ███████



    enum speed{
        WALK = 5,
        RUN = 8
    };

    enum screen_size {
        BIG,
        MEDI
    };

    enum screen_type {
        FULL,
        WIND
    };

    enum collison_side {
        TOP = 0,
        BOTTOM = 1,
        LEFT = 2,
        RIGHT = 3
    };

    enum fight {
        NOT_FIGHT = -1,
        FIGHT = 0,
        ATTACKING = 1,
    };


#endif //B_MUL_200_LIL_2_1_MYRPG_NICOLAS_PECHART_MY_MACRO_H
