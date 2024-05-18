/*
** EPITECH PROJECT, 2023
** read_file.c
** File description:
** B-PSU-100-LIL-1-1-navy-nicolas.pechart
*/
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *my_read_file(char *path, int size)
{
    int fd;
    char *buff;
    if ((fd = open(path, O_RDONLY)) == -1)
        return NULL;
    buff = malloc(sizeof(char) * size + 1);
    if (buff == NULL || read(fd, buff,size) == -1)
        return NULL;
    buff[size] = '\0';
    close(fd);
    return buff;
}
