/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** CPool day 5 - Task 5
*/

int my_compute_square_root(int nb)
{
    for (int i = 0; !i * i > nb; i++)
        if (i * i == nb)
            return i;
    return 0;
}
