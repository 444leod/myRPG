/*
** EPITECH PROJECT, 2023
** my_file_exists.c
** File description:
** B-PSU-200-LIL-2-1-minishell1-nicolas.pechart
*/
#include <fcntl.h>
#include <unistd.h>

int my_file_exists(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return 0;
    close(fd);
    return 1;
}
