/*
** EPITECH PROJECT, 2023
** current
** File description:
** fight_utils
*/

#include "../../include/my_rpg.h"
#include <stdlib.h>

attack_t create_attack(int damage, int speed, int precision, char *text)
{
    attack_t attack = malloc(sizeof(struct attack_slot));

    attack->damage = damage;
    attack->precision = precision;
    attack->speed = speed;
    attack->text = text;
    return attack;
}

slot_t create_slot(int id, image_t sprite, attack_t attack)
{
    slot_t slot = malloc(sizeof(struct attack_slot));

    slot->id = id;
    slot->sprite = sprite;
    slot->stats = attack;
    return slot;
}
