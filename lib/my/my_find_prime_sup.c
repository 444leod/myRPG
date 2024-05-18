/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** CPool day 5 - Task 7
*/
int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int result = nb;
    while (my_is_prime(result) != 1) {
        result++;
    }
    return result;
}
