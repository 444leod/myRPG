/*
** EPITECH PROJECT, 2022
** my_pow.c
** File description:
** CPool day 9 - Lib Fix
*/

int my_pow(int nbr, int x)
{
    int temp = nbr;
    for (int i = 0; i < x; i++) {
        temp *= nbr;
    }
    return temp;
}
