/*
** EPITECH PROJECT, 2023
** player_data.c
** File description:
** B-MUL-200-LIL-2-1-myrpg-nicolas.pechart
*/
#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <fcntl.h>
#include <unistd.h>

int get_health(void)
{
    int size = my_file_size("game_data/game.rpg");
    char *file = my_read_file("game_data/game.rpg", size);
    char **s_data = NULL;
    int len = -1;
    if (file == NULL)
        return 100;

    s_data = my_str_to_word_array(file, "\n");
    if (s_data == NULL)
        return 100;
    for (len = 0; s_data[len] != NULL ; len++);
    if (len != 13)
        return 100;
    return my_getnbr(s_data[3]);
}

int get_stamina(void)
{
    int size = my_file_size("game_data/game.rpg");
    char *file = my_read_file("game_data/game.rpg", size);
    char **s_data = NULL;
    int len = -1;
    if (file == NULL)
        return 100;

    s_data = my_str_to_word_array(file, "\n");
    if (s_data == NULL)
        return 100;
    for (len = 0; s_data[len] != NULL ; len++);
    if (len != 13)
        return 100;
    return my_getnbr(s_data[0]);
}

int get_xp(void)
{
    int size = my_file_size("game_data/game.rpg");
    char *file = my_read_file("game_data/game.rpg", size);
    char **s_data = NULL;
    int len = -1;
    if (file == NULL)
        return 10;

    s_data = my_str_to_word_array(file, "\n");
    if (s_data == NULL)
        return 10;
    for (len = 0; s_data[len] != NULL ; len++);
    if (len != 13)
        return 10;
    return my_getnbr(s_data[2]);
}

void save_player_data(struct window *my_rpg)
{
    char *path = "game_data/game.rpg";
    int stamina = PLAYER->stamina;
    PLAYER->x = PLAYER->position.x;
    PLAYER->y = PLAYER->position.y;
    close(open(path, O_CREAT | O_TRUNC | O_WRONLY, 0644));
    save_data(path, MYITOS(stamina), MYGNBR(stamina));
    save_data(path, MYITOS(PLAYER->max_stamina), MYGNBR(PLAYER->max_stamina));
    save_data(path, MYITOS(PLAYER->xp), MYGNBR(PLAYER->xp));
    save_data(path, MYITOS(PLAYER->health), MYGNBR(PLAYER->health));
    save_data(path, MYITOS(PLAYER->refill), MYGNBR(PLAYER->refill));
    save_data(path, MYITOS(PLAYER->x), MYGNBR(PLAYER->x));
    save_data(path, MYITOS(PLAYER->y), MYGNBR(PLAYER->y));
    save_data(path, MYITOS(PLAYER->level), MYGNBR(PLAYER->level));
    save_data(path, MYITOS(PLAYER->skill_p), MYGNBR(PLAYER->skill_p));
    save_data(path, MYITOS(PLAYER->damage_p), MYGNBR(PLAYER->damage_p));
    save_data(path, MYITOS(PLAYER->health_p), MYGNBR(PLAYER->health_p));
    save_data(path, MYITOS(PLAYER->sword), MYGNBR(PLAYER->sword));
    save_data(path, MYITOS(PLAYER->coconut), MYGNBR(PLAYER->coconut));
}
