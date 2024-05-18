/*
** EPITECH PROJECT, 2023
** current
** File description:
** fight
*/

#include "../../include/my_rpg.h"
#include "../../include/my.h"
#include <stdlib.h>

static int init_f_texts(struct window *my_rpg)
{
    FIGHT(ally) = malloc(sizeof(struct ally));
    FIGHT(ennemy) = malloc(sizeof(struct ennemy));
    CHECK_MALLOC(FIGHT(ally));
    CHECK_MALLOC(FIGHT(ennemy));
    F_PLAYER(max_hp) = 30;
    F_PLAYER(hp) = 30;
    F_ENNEMY(name) = sfText_create();
    CHECK_MALLOC(F_ENNEMY(name));
    sfText_setColor(F_ENNEMY(name), sfBlack);
    sfText_setFont(F_ENNEMY(name), my_rpg->font);
    sfText_setCharacterSize(F_ENNEMY(name), 60);
    sfText_setString(F_ENNEMY(name), "ennemy");
    sfText_setPosition(F_ENNEMY(name), (sfVector2f){100, 180});
    FIGHT(zone) = 0;
    CHECK_ERROR(init_fight_texts(my_rpg));
    CHECK_ERROR(init_fight_lifes(my_rpg));
    return (0);
}

static int init_attacks(struct window *my_rpg)
{
    V2F pos = {0, 0};
    (FIGHT(attacks_sp))[0] = create_sprite("fight/attack1.png", pos);
    (FIGHT(attacks_sp))[1] = create_sprite("fight/attack2.png", pos);
    (FIGHT(attacks_sp))[2] = create_sprite("fight/attack3.png", pos);
    (FIGHT(attacks_sp))[3] = create_sprite("fight/attack4.png", pos);
    (FIGHT(attacks_sp))[4] = create_sprite("fight/attack5.png", pos);
    (FIGHT(attacks_sp))[5] = create_sprite("fight/attack6.png", pos);
    (FIGHT(attacks_sp))[6] = create_sprite("fight/attack7.png", pos);
    FIGHT(attack_stats)[0] = create_attack(10, 100, 60, "Rapier Strike !");
    FIGHT(attack_stats)[1] = create_attack(5, 80, 80, "Scratch !");
    FIGHT(attack_stats)[2] = create_attack(-10, 90, 100, "Sweet Eyes !");
    FIGHT(attack_stats)[3] = create_attack(-1, 100, 60, "Deadly hiss !");
    FIGHT(attack_stats)[4] = create_attack(5, 30, 100, "Knife Strike !");
    FIGHT(attack_stats)[5] = create_attack(15, 75, 30, "Bite !");
    FIGHT(attack_stats)[6] = create_attack(-84, 110, 70, "Dodge !");
    for (int i = 0; i < 7; i++){
        CHECK_MALLOC(FIGHT(attacks_sp)[i]);
        CHECK_MALLOC(FIGHT(attack_stats)[i]);
    }
    return SUCCESS;
}

static int init_slots(struct window *my_rpg)
{
    F_PLAYER(slots) = malloc(sizeof(struct attack_slot) * 4);
    CHECK_MALLOC(F_PLAYER(slots));
    F_PLAYER(slots)[0] = create_slot(0,
        FIGHT(attacks_sp)[0], FIGHT(attack_stats)[0]);
    F_PLAYER(slots)[1] = NULL;
    F_PLAYER(slots)[2] = NULL;
    F_PLAYER(slots)[3] = NULL;
    FIGHT(bg) = malloc(sizeof(image_t) * 3);
    CHECK_MALLOC(FIGHT(bg));
    FIGHT(bg)[0] = create_sprite("fight/background1.png", (V2F){0, 0});
    CHECK_MALLOC(FIGHT(bg)[0]);
    FIGHT(bg)[1] = create_sprite("fight/background2.png", (V2F){0, 0});
    CHECK_MALLOC(FIGHT(bg)[1]);
    FIGHT(bg)[2] = create_sprite("fight/background3.png", (V2F){0, 0});
    CHECK_MALLOC(FIGHT(bg)[2]);
    FIGHT(attacks) = create_sprite("fight/attacks_screen.png", (V2F){0, 0});
    FIGHT(healths) = create_sprite("fight/fight_health.png", (V2F){0, 0});
    FIGHT(fightscreen) = create_sprite("fight/fight_screen.png", (V2F){0, 0});
    FIGHT(state) = 0;
    return SUCCESS;
}

static int init_hitboxes(struct window *my_rpg)
{
    FIGHT(hitboxes) = malloc(sizeof(struct my_rect) * 4);
    CHECK_MALLOC(FIGHT(hitboxes));
    (FIGHT(hitboxes))[0] = create_rect(sfWhite, (IRECT){240, 60, 660, 234});
    (FIGHT(hitboxes))[1] = create_rect(sfWhite, (IRECT){1008, 60, 660, 234});
    (FIGHT(hitboxes))[2] = create_rect(sfWhite, (IRECT){240, 432, 660, 234});
    (FIGHT(hitboxes))[3] = create_rect(sfWhite, (IRECT){1008, 432, 660, 234});
    for (int i = 0; i < 4; i++)
        CHECK_MALLOC(FIGHT(hitboxes)[i]);
    return SUCCESS;
}

int init_fight(struct window *my_rpg)
{
    my_rpg->fight = malloc(sizeof(struct my_fight));
    CHECK_MALLOC(my_rpg->fight);
    FIGHT(attacks_sp) = malloc(sizeof(image_t) * 7);
    CHECK_MALLOC(FIGHT(attacks_sp));
    FIGHT(attack_stats) = malloc(sizeof(attack_t) * 7);
    CHECK_MALLOC(FIGHT(attack_stats));
    CHECK_ERROR(init_attacks(my_rpg));
    FIGHT(first) = 0;
    FIGHT(fuit) = 0;
    CHECK_ERROR(init_f_texts(my_rpg));
    CHECK_ERROR(init_slots(my_rpg));
    CHECK_ERROR(init_hitboxes(my_rpg));
    FIGHT(fight) = create_rect(sfWhite, (IRECT){336, 101, 1248, 499});
    FIGHT(cancel) = create_rect(sfWhite, (IRECT){270, 822, 1380, 227});
    FIGHT(bag) = create_sprite("fight/bag.png", (V2F){431, 85});
    CHECK_MALLOC(FIGHT(fight));
    CHECK_MALLOC(FIGHT(bag));
    CHECK_MALLOC(FIGHT(cancel));
    F_PLAYER(attack) = 1;
    return SUCCESS;
}
