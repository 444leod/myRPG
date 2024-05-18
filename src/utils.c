/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** utils
*/

#include "../include/my_rpg.h"
#include "../include/my.h"
#include <unistd.h>
#include <fcntl.h>

/**
 * @brief Give a random number between the 2 given numbers
 * @param min an int
 * @param max an int
 * @return nbr between min and max
*/
int get_rand_between(int min, int max)
{
    int fd = open("/dev/urandom", O_RDONLY);
    int readd;
    unsigned int nbr;

    if (fd <= 0)
        return 84;
    readd = read(fd, &nbr, sizeof(unsigned int));
    if (readd == -1)
        return 84;
    srand(nbr);
    close(fd);
    return rand() % (max - min + 1) + min;
}
