/*
** EPITECH PROJECT, 2023
** current
** File description:
** vectors
*/

#include "../../include/lib_csfml.h"

sfVector2f substract_vectors(sfVector2f v1, sfVector2f v2)
{
    sfVector2f vector;
    vector.x = v1.x - v2.x;
    vector.y = v1.y - v2.y;
    return vector;
}
