/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** screen
*/

#include "../../../include/my_rpg.h"

static void change_screen_state(struct window *my_rpg, sfVector2f pos)
{
    if (!MOUSE_ON(BUTTON(fullscreen_rect)->bounds, pos) &&
        !MOUSE_ON(BUTTON(windowed_rect)->bounds, pos))
        return;
    if (STATE(s_type) == FULL && MOUSE_ON(BUTTON(windowed_rect)->bounds,
        pos)) {
        STATE(s_type) = WIND;
        STYLE = (sfResize | sfClose);
        sfSprite_setTextureRect(BUTTON(FS)->sprite, (IRECT){0, 123, 485, 118});
        sfSprite_setTextureRect(BUTTON(WW)->sprite, (IRECT){0, 0, 485, 118});
        return;
    }
    if (STATE(s_type) == WIND && MOUSE_ON(BUTTON(fullscreen_rect)->bounds,
        pos)) {
        STATE(s_type) = FULL;
        STATE(s_size) = BIG;
        VIDEO_MODE = (sfVideoMode){1920, 1080, 32};
        STYLE = (sfFullscreen | sfClose);
        sfSprite_setTextureRect(BUTTON(FS)->sprite, (IRECT){0, 0, 485, 118});
        sfSprite_setTextureRect(BUTTON(WW)->sprite, (IRECT){0, 123, 485, 118});
    }
}

static void change_screen_size(struct window *my_rpg, sfVector2f pos)
{
    if (!MOUSE_ON(BUTTON(res)[0]->bounds, pos) &&
        !MOUSE_ON(BUTTON(res)[1]->bounds, pos))
        return;
    if (STATE(s_size) == BIG) {
        STATE(s_size) = MEDI;
        VIDEO_MODE = (sfVideoMode){1280, 720, 32};
        return;
    }
    if (STATE(s_size) == MEDI) {
        STATE(s_size) = BIG;
        VIDEO_MODE = (sfVideoMode){1920, 1080, 32};
        return;
    }
}

void reload_window(struct window *my_rpg)
{
    sfRenderWindow_close(my_rpg->window);
    sfRenderWindow_destroy(my_rpg->window);
    WINDOW = sfRenderWindow_create(VIDEO_MODE, "My_RPG", STYLE, NULL);
    sfRenderWindow_setIcon(WINDOW, 512, 512, my_rpg->icon);
    sfRenderWindow_setFramerateLimit(WINDOW, 60);
    my_rpg->size = sfRenderWindow_getSize(WINDOW);
    sfSprite_setScale(RDSPRITE, (sfVector2f){(float)my_rpg->size.x / 1920,
        (float)my_rpg->size.y / 1080});
}

void handle_screen_change(struct window *my_rpg, sfVector2f pos)
{
    if (!(MOUSE_ON(BUTTON(res)[0]->bounds, pos) && STATE(s_type == WIND)) &&
        !(MOUSE_ON(BUTTON(res)[1]->bounds, pos) && STATE(s_type == WIND)) &&
        !(MOUSE_ON(BUTTON(fullscreen_rect)->bounds, pos) &&
        STATE(s_type) == WIND) &&
        !(MOUSE_ON(BUTTON(windowed_rect)->bounds, pos) &&
        STATE(s_type) == FULL))
        return;
    change_screen_size(my_rpg, pos);
    change_screen_state(my_rpg, pos);
    reload_window(my_rpg);
}
