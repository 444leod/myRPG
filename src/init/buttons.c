/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** buttons
*/

#include "../../include/my_rpg.h"
#include <stdlib.h>

static int init_main_menu(struct window *my_rpg)
{
    BUTTON(play) = create_rect(ORANGE, (IRECT){6, 393, 387, 143});
    BUTTON(credits) = create_rect(ORANGE, (IRECT){6, 572, 387, 143});
    BUTTON(option) = create_rect(ORANGE, (IRECT){6, 762, 387, 143});
    BUTTON(exit) = create_rect(ORANGE, (IRECT){6, 950, 387, 124});
    BUTTON(inventory) = create_rect(ORANGE, (IRECT){1234, 494, 90, 90});
    BUTTON(skill_menu) = create_rect(ORANGE, (IRECT){1237, 729, 83, 88});
    BUTTON(grey) = create_rect((sfColor){128, 128, 128, 80},
        (IRECT){582, 642, 796, 271});
    CHECK_MALLOC(BUTTON(play));
    CHECK_MALLOC(BUTTON(credits));
    CHECK_MALLOC(BUTTON(option));
    CHECK_MALLOC(BUTTON(exit));
    CHECK_MALLOC(BUTTON(inventory));
    CHECK_MALLOC(BUTTON(skill_menu));
    return SUCCESS;
}

static int init_options_bis_bis(struct window *my_rpg)
{
    my_rpg->menus->music = create_rect(sfGreen, (IRECT){676, 453, 567 / 2, 39});
    my_rpg->menus->sound = create_rect(sfGreen, (IRECT){676, 298, 567 / 2, 39});
    CHECK_MALLOC(my_rpg->menus->music);
    CHECK_MALLOC(my_rpg->menus->sound);
    BUTTON(resume) = create_rect(ORANGE, (IRECT){675, 109, 571, 162});
    BUTTON(save) = create_rect(ORANGE, (IRECT){675, 343, 571, 162});
    BUTTON(p_option) = create_rect(ORANGE, (IRECT){675, 577, 571, 162});
    BUTTON(p_exit) = create_rect(ORANGE, (IRECT){675, 811, 571, 162});
    BUTTON(pause_bg) = create_rect(sfWhite, (IRECT){675, 109, 571, 824});
    CHECK_MALLOC(BUTTON(resume));
    CHECK_MALLOC(BUTTON(save));
    CHECK_MALLOC(BUTTON(p_option));
    CHECK_MALLOC(BUTTON(p_exit));
    CHECK_MALLOC(BUTTON(pause_bg));
    BUTTON(new_rect) = create_rect(ORANGE, (IRECT){522, 283, 880, 144});
    BUTTON(load_rect) = create_rect(ORANGE, (IRECT){515, 620, 830, 315});
    BUTTON(skill_hp) = create_rect(ORANGE, (IRECT){745, 330, 650, 144});
    BUTTON(skill_dmg) = create_rect(ORANGE, (IRECT){745, 610, 650, 144});
    return SUCCESS;
}

static int init_options_bis(struct window *my_rpg)
{
    BUTTON(sound) = malloc(sizeof(struct my_rect) * 2);
    CHECK_MALLOC(BUTTON(sound));
    BUTTON(sound)[0] = create_rect(ORANGE, (IRECT){577, 270, 92, 92});
    BUTTON(sound)[1] = create_rect(ORANGE, (IRECT){1249, 270, 92, 92});
    BUTTON(music) = malloc(sizeof(struct my_rect) * 2);
    CHECK_MALLOC(BUTTON(music));
    BUTTON(music)[0] = create_rect(ORANGE, (IRECT){577, 424, 92, 92});
    BUTTON(music)[1] = create_rect(ORANGE, (IRECT){1249, 424, 92, 92});
    BUTTON(res) = malloc(sizeof(struct my_rect) * 2);
    CHECK_MALLOC(BUTTON(res));
    BUTTON(res)[0] = create_rect(sfRed, (IRECT){1225, 792, 92, 92});
    BUTTON(res)[1] = create_rect(sfRed, (IRECT){606, 792, 92, 92});
    CHECK_MALLOC(BUTTON(sound)[0]);
    CHECK_MALLOC(BUTTON(sound)[1]);
    CHECK_MALLOC(BUTTON(music)[0]);
    CHECK_MALLOC(BUTTON(music)[1]);
    return SUCCESS;
}

static int init_options(struct window *my_rpg)
{
    BUTTON(fullscreen) = create_sprite("menu/fullscreen.png", (V2F){726, 535});
    BUTTON(windowed) = create_sprite("menu/windowed.png", (V2F){726, 656});
    CHECK_MALLOC(BUTTON(fullscreen));
    CHECK_MALLOC(BUTTON(windowed));
    sfSprite_setTextureRect(BUTTON(FS)->sprite, (IRECT){0, 123, 485, 118});
    sfSprite_setTextureRect(BUTTON(WW)->sprite, (IRECT){0, 0, 485, 118});
    BUTTON(screen_size) = malloc(sizeof(struct my_image) * 2);
    CHECK_MALLOC(BUTTON(screen_size));
    BUTTON(screen_size)[0] = create_sprite("menu/1920.png", (V2F){697, 792});
    BUTTON(screen_size)[1] = create_sprite("menu/1680.png", (V2F){697, 792});
    CHECK_MALLOC(BUTTON(screen_size)[0]);
    CHECK_MALLOC(BUTTON(screen_size)[1]);
    BUTTON(fullscreen_rect) = create_rect(ORANGE, (IRECT){726, 535, 485, 118});
    BUTTON(windowed_rect) = create_rect(ORANGE, (IRECT){726, 658, 485, 118});
    CHECK_MALLOC(BUTTON(fullscreen_rect));
    CHECK_MALLOC(BUTTON(windowed_rect));
    CHECK_ERROR(init_options_bis(my_rpg));
    CHECK_ERROR(init_options_bis_bis(my_rpg));

    return SUCCESS;
}

int init_buttons(struct window *my_rpg)
{
    my_rpg->buttons = malloc(sizeof(struct buttons));

    CHECK_ERROR(init_main_menu(my_rpg));
    CHECK_ERROR(init_options(my_rpg));
    BUTTON(back) = create_rect(sfWhite, (IRECT){1352, 858, 92, 92});
    BUTTON(back2) = create_rect(sfWhite, (IRECT){1400, 858, 92, 92});
    CHECK_MALLOC(BUTTON(back));
    CHECK_MALLOC(BUTTON(back2));
    return SUCCESS;
}
