/*
** EPITECH PROJECT, 2023
** load_player_data.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <unistd.h>

static void continue_loading(struct window *my_rpg, char **s_data)
{
    PLAYER->stamina = my_getnbr(s_data[0]);
    PLAYER->max_stamina = my_getnbr(s_data[1]);
    PLAYER->xp = my_getnbr(s_data[2]);
    PLAYER->health = my_getnbr(s_data[3]);
    PLAYER->refill = my_getnbr(s_data[4]);
    PLAYER->x = my_getnbr(s_data[5]);
    PLAYER->y = my_getnbr(s_data[6]);
    PLAYER->level = my_getnbr(s_data[7]);
    PLAYER->skill_p = my_getnbr(s_data[8]);
    PLAYER->damage_p = my_getnbr(s_data[9]);
    PLAYER->health_p = my_getnbr(s_data[10]);
    PLAYER->sword = my_getnbr(s_data[11]);
    PLAYER->coconut = my_getnbr(s_data[12]);
    QUEST(nbr) = new_txt(MYITOS(PLAYER->coconut),
        30, (sfVector2f){1640, 170}, my_rpg->font);
    PLAYER->position.x = PLAYER->x;
    PLAYER->position.y = PLAYER->y;
}

int load_player_data(struct window *my_rpg)
{
    int size = my_file_size("game_data/game.rpg");
    char *file = my_read_file("game_data/game.rpg", size);
    char **s_data = NULL;
    int len = -1;
    if (file == NULL) return 1;
    s_data = my_str_to_word_array(file, "\n");
    if (s_data == NULL) return 1;
    for (len = 0; s_data[len] != NULL ; len++);
    if (len != 13) return 1;
    continue_loading(my_rpg, s_data);
    return 0;
}
