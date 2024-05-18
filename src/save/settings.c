/*
** EPITECH PROJECT, 2023
** settings.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <fcntl.h>
#include <unistd.h>

void update_states(struct window *my_rpg, int s_type, int s_size)
{
    if (s_type == 0) {
        STATE(s_type) = FULL;
        STATE(s_size) = BIG;
        VIDEO_MODE = (sfVideoMode) {1920, 1080, 32};
        STYLE = (sfFullscreen | sfClose);
        sfSprite_setTextureRect(BUTTON(FS)->sprite, (IRECT){0, 0, 485, 118});
        sfSprite_setTextureRect(BUTTON(WW)->sprite, (IRECT){0, 123, 485, 118});
    } else {
        STATE(s_type) = WIND;
        STYLE = (sfResize | sfClose);
        sfSprite_setTextureRect(BUTTON(FS)->sprite, (IRECT){0, 123, 485, 118});
        sfSprite_setTextureRect(BUTTON(WW)->sprite, (IRECT){0, 0, 485, 118});
    }
    if (s_size == 1) {
        STATE(s_size) = MEDI;
        VIDEO_MODE = (sfVideoMode){1280, 720, 32};
    } else {
        STATE(s_size) = BIG;
        VIDEO_MODE = (sfVideoMode) {1920, 1080, 32};
    }
}

int load_settings(struct window *my_rpg)
{
    int size = my_file_size("game_data/settings.rpg");
    char *file = my_read_file("game_data/settings.rpg", size);
    char **s_data = NULL;
    int len = -1;
    if (file == NULL)
        return 1;

    s_data = my_str_to_word_array(file, "\n");
    for (len = 0; s_data[len] != NULL ; len++);
    if (len != 4)
        return 1;
    change_sound(my_rpg, my_getnbr(s_data[0]) - 5);
    change_music(my_rpg, my_getnbr(s_data[1]) - 5);
    update_states(my_rpg, my_getnbr(s_data[2]), my_getnbr(s_data[3]));
    reload_window(my_rpg);
    return 0;
}

void save_settings(struct window *my_rpg)
{
    char *path = "game_data/settings.rpg";
    close(open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644));
    save_data(path, MYITOS(STATE(sound)), my_get_nbr_len(STATE(sound)));
    save_data(path, MYITOS(STATE(music)), my_get_nbr_len(STATE(music)));
    save_data(path, MYITOS(STATE(s_type)), my_get_nbr_len(STATE(s_type)));
    save_data(path, MYITOS(STATE(s_size)), my_get_nbr_len(STATE(s_size)));
}
