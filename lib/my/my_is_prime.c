/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** CPool day 5 - Task 6
*/

int my_is_prime(int nb)
{
    if (nb == 1 || nb <= 0) return 0;
    for (int i = nb  - 1; i > 1; i--) {
        if (nb % i == 0) {
            return 0;
        }
    }

    return 1;
}
