/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** CPool day 5 - Task 4
*/
int power_rec(int result, int nb, int p);

int my_compute_power_rec(int nb, int p)
{
    return power_rec(nb, nb, p);
}

int power_rec(int result, int nb, int p)
{
    if (p == 0) return 1;
    if (p < 0) return 0;
    return result * power_rec(result, nb ,p - 1);
}
