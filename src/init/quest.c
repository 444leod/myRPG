/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** quest
*/

#include "../../include/my_rpg.h"

static int init_text(struct window *my_rpg)
{
    QUEST(text) = new_txt(" Find your sword\n  Puss in Boots !", 30,
        (sfVector2f){1540, 70}, my_rpg->font);
    CHECK_MALLOC(QUEST(text));
    QUEST(nbr) = new_txt("0", 30, (sfVector2f){1640, 170}, my_rpg->font);
    CHECK_MALLOC(QUEST(nbr));
    QUEST(nbr2) = new_txt("/1", 30, (sfVector2f){1660, 170}, my_rpg->font);
    CHECK_MALLOC(QUEST(nbr2));
    return SUCCESS;
}

static int init_sprite(struct window *my_rpg)
{
    QUEST(bg) = create_sprite("quest_box.png", (sfVector2f){0, 0});
    CHECK_MALLOC(QUEST(bg));

    return SUCCESS;
}

int init_quests(struct window *my_rpg)
{
    my_rpg->quests = malloc(sizeof(struct quests));
    CHECK_ERROR(init_text(my_rpg));
    CHECK_ERROR(init_sprite(my_rpg));
    QUEST(id) = 0;
    QUEST(completed) = 0;
    QUEST(actual_completed) = 0;
    return SUCCESS;
}
