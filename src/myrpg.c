/*
** EPITECH PROJECT, 2023
** myrpg.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/

#include "../include/my_rpg.h"
#include <stdlib.h>
#include <stdio.h>

static void handle_event(struct window *my_rpg, V2F pos)
{
    if (EVENT.type == sfEvtClosed)
        sfRenderWindow_close(my_rpg->window);
    if (STATE(controls) && ESC) {
        STATE(controls) = 0;
        return;
    }
    if (STATE(credits) && ESC) STATE(credits) = 0;
    if (!STATE(main_menu) && !STATE(options) && ESC)
        STATE(pause) = !STATE(pause);
    if (STATE(options) && ESC) STATE(options) = 0;
    if (STATE(load) && ESC) STATE(load) = 0;
    if (!STATE(main_menu) && ISKEYPRESSED(sfKeyE)) {
        get_coconut(my_rpg);
        get_sword(my_rpg);
    }
    if (STATE(skills) && ESC) STATE(skills) = 0;
    if (STATE(inventory) && ESC) STATE(inventory) = 0;
    handle_menus(my_rpg, pos);
}

static void update_animation_fps(struct window *my_rpg)
{
    if (STATE(main_menu) || STATE(pause) || STATE(options) || STATE(controls)
    || STATE(skills))
        return;
    if (TIME(my_rpg->player_mov_clock) > .01) {
        update_player(my_rpg);
        RESET_TIME(my_rpg->player_mov_clock);
    }
    if (TIME(my_rpg->player_anim_clock) > .1) {
        update_p_animation(my_rpg);
        RESET_TIME(my_rpg->player_anim_clock);
    }
    if (CURRENT_MAP != NULL &&
        TIME(my_rpg->map_clock) > CURRENT_MAP->animation_speed) {
        update_animation(CURRENT_MAP);
        RESET_TIME(my_rpg->map_clock);
    }
}

void update(struct window *my_rpg)
{
    sfVector2f pos = get_pxmousepos(WINDOW);
    pos.y *= 1080 / (float)my_rpg->size.y;
    pos.x *= 1920 / (float)my_rpg->size.x;
    while (sfRenderWindow_pollEvent(my_rpg->window, &EVENT))
        handle_event(my_rpg, pos);
    menu_display_hover(my_rpg, pos);
    display_all(my_rpg);
    update_animation_fps(my_rpg);
    sfRenderTexture_clear(RDTEXTURE, sfWhite);
    sfRenderTexture_clear(HTEXTURE, sfTransparent);
}

int myrpg(int ac, __attribute__((unused)) char **av, char **env)
{
    struct window *my_rpg = malloc(sizeof(struct window));
    if (ac != 1 || env[0] == NULL || verif_deps() == 84) {
        free(my_rpg);
        return 84;
    }
    CHECK_ERROR(init_all(my_rpg));
    while (sfRenderWindow_isOpen(my_rpg->window)) {
        update(my_rpg);
    }
    destroy_all(my_rpg);
    my_free_all();
    return 0;
}
