/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** event
*/

#include "../../include/my_rpg.h"

static void handle_load(struct window *my_rpg, sfVector2f pos)
{
    if (MOUSE_ON(BUTTON(back2)->bounds, pos))
        STATE(load) = 0;
    if (MOUSE_ON(BUTTON(load_rect)->bounds, pos) && save_exists()){
        STATE(load) = 0;
        STATE(main_menu) = 0;
        reset_player_data(my_rpg);
        STATE(controls) = 0;
        my_rpg->tutorial = load_tutorial();
        CURRENT_MAP = my_rpg->tutorial;
        load_player_data(my_rpg);
    }
    if (MOUSE_ON(BUTTON(new_rect)->bounds, pos)){
        STATE(load) = 0;
        STATE(main_menu) = 0;
        my_rpg->tutorial = load_tutorial();
        CURRENT_MAP = my_rpg->tutorial;
        reset_player_data(my_rpg);
        load_intro(my_rpg);
    }

}

static void handle_main_menu(struct window *my_rpg, sfVector2f pos)
{
    if (is_mouse_on_sprite(BUTTON(play)->bounds, pos)
    && !STATE(credits) && !STATE(options))
        STATE(load) = 1;
    if (is_mouse_on_sprite(BUTTON(credits)->bounds, pos)
    && !STATE(options) && !STATE(load))
        STATE(credits) = 1;
    if (is_mouse_on_sprite(BUTTON(option)->bounds, pos)
    && !STATE(credits) && !STATE(load))
        STATE(options) = 1;
    if (is_mouse_on_sprite(BUTTON(exit)->bounds, pos)
    && !STATE(credits) && !STATE(options) && !STATE(load))
        sfRenderWindow_close(my_rpg->window);
}

void handle_option(struct window *my_rpg, sfVector2f pos)
{
    if (MOUSE_ON(BUTTON(back)->bounds, pos))
        STATE(options) = 0;
    handle_screen_change(my_rpg, pos);
    handle_sound_change(my_rpg, pos);
    save_settings(my_rpg);
}

static void handle_credits(struct window *my_rpg, sfVector2f pos)
{
    if (MOUSE_ON(BUTTON(resume)->bounds, pos))
        STATE(pause) = 0;
    if (MOUSE_ON(BUTTON(p_option)->bounds, pos))
        STATE(options) = 1;
    if (MOUSE_ON(BUTTON(save)->bounds, pos))
        save_player_data(my_rpg);
    if (MOUSE_ON(BUTTON(p_exit)->bounds, pos)){
        STATE(main_menu) = 1;
        unload_tutorial(my_rpg);
        STATE(pause) = 0;
    }
    if (MOUSE_ON(BUTTON(back)->bounds, pos))
        STATE(credits) = 0;
}

void handle_menus(struct window *my_rpg, sfVector2f pos)
{
    if (!has_clicked(EVENT, sfMouseLeft))
        return;
    if (STATE(options))
        handle_option(my_rpg, pos);
    if (STATE(load))
        handle_load(my_rpg, pos);
    if (STATE(controls))
        handle_controls(my_rpg, pos);
    if (STATE(credits))
        handle_credits(my_rpg, pos);
    if (STATE(skills))
        handle_skills(my_rpg, pos);
    if (STATE(main_menu))
        handle_main_menu(my_rpg, pos);
    if (STATE(pause) && !STATE(options) && !STATE(save))
        handle_pause_menu(my_rpg, pos);
}
