/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
** File description:
** sound
*/

#include "../../../include/my_rpg.h"

static void change_sounds_volume(struct window *my_rpg)
{
    sfSound_setVolume(SOUND(coconut), STATE(sound) * 10);
    sfSound_setVolume(SOUND(sword), STATE(sound) * 10);
    sfSound_setVolume(SOUND(win), STATE(sound) * 10);
    sfSound_setVolume(SOUND(whistle), STATE(sound) * 10);

}

int change_sound(struct window *my_rpg, int volume)
{
    if (volume < 0 && STATE(sound) != 0) {
        STATE(sound) += volume;
        change_sounds_volume(my_rpg);
        STATE(f_sound) -= 56.7 * -volume;
        sfRectangleShape_setSize(my_rpg->menus->sound->rect,
            (V2F){(float)STATE(f_sound), 39});
    }
    if (volume > 0 && STATE(sound) != 10) {
        STATE(sound) += volume;
        change_sounds_volume(my_rpg);
        STATE(f_sound) += 56.7 * volume;
        sfRectangleShape_setSize(my_rpg->menus->sound->rect,
            (V2F){(float)STATE(f_sound), 39});
    }
    return STATE(sound);
}

int change_music(struct window *my_rpg, int volume)
{
    if (volume < 0 && STATE(music) != 0) {
        STATE(music) += volume;
        sfMusic_setVolume(SOUND(music), STATE(music) * 10);
        STATE(f_music) -= 56.7 * -volume;
        sfRectangleShape_setSize(my_rpg->menus->music->rect,
            (V2F){(float)STATE(f_music), 39});
    }
    if (volume > 0 && STATE(music) != 10) {
        STATE(music) += volume;
        sfMusic_setVolume(SOUND(music), STATE(music) * 10);
        STATE(f_music) += 56.7 * volume;
        sfRectangleShape_setSize(my_rpg->menus->music->rect,
            (V2F){(float)STATE(f_music), 39});
    }
    return STATE(music);
}

void handle_sound_change(struct window *my_rpg, sfVector2f pos)
{
    if (MOUSE_ON(BUTTON(sound)[0]->bounds, pos))
        change_sound(my_rpg, -1);
    if (MOUSE_ON(BUTTON(sound)[1]->bounds, pos))
        change_sound(my_rpg, 1);
    if (MOUSE_ON(BUTTON(music)[0]->bounds, pos))
        change_music(my_rpg, -1);
    if (MOUSE_ON(BUTTON(music)[1]->bounds, pos))
        change_music(my_rpg, 1);
}
