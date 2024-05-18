/*
** EPITECH PROJECT, 2023
** my_get_nbr_len.c
** File description:
** B-MUL-100-LIL-1-1-myradar-nicolas.pechart
*/

int my_get_nbr_len(int nbr)
{
    int x = 1;
    int i = 1;
    if (nbr < 0) {
        nbr = -nbr;
    }
    while (nbr / x >= 10) {
        i++;
        x = x * 10;
    }
    return i;
}
