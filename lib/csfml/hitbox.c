/*
** EPITECH PROJECT, 2023
** CSFML LIB
** File description:
** hitbox
*/

#include "../../include/lib_csfml.h"

bool is_mouse_on_sprite(sfIntRect sprite_rect, sfVector2f mouse_pos)
{
    if (sfIntRect_contains(&sprite_rect, mouse_pos.x, mouse_pos.y))
        return true;
    return false;
}

bool is_mouse_on_sprite_f(sfFloatRect sprite_rect, sfVector2f mouse_pos)
{
    if (sfFloatRect_contains(&sprite_rect, mouse_pos.x, mouse_pos.y))
        return true;
    return false;
}

int change_state(int state, int button)
{
    if (state == button)
        return -1;
    return button;
}

bool has_clicked(sfEvent event, sfMouseButton button)
{
    return (event.type == sfEvtMouseButtonPressed &&
        event.mouseButton.button == button);
}
